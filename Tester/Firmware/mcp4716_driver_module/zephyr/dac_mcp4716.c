#include <zephyr.h>
#include <kernel.h>
#include <drivers/i2c.h>
#include <drivers/dac.h>
#include <sys/util.h>
#include <sys/byteorder.h>
#include <sys/__assert.h>
#include <logging/log.h>

#define DT_DRV_COMPAT microchip_mcp4716

LOG_MODULE_REGISTER(dac_mcp4716, CONFIG_DAC_LOG_LEVEL);

#define MCP4716_PD_BITS_CONFIG   0x00U
#define MCP4716_VREF_BITS_CONFIG 0x00U
#define MCP4716_G_BITS_CONFIG    0x00U
#define MCP4716_NV_DAC_CONFIG    0x07FFU
#define MCP4716_SW_ADDR          0xFF
#define MCP4716_POR_DELAY        5
#define MCP4716_MAX_CHANNEL      1

struct mcp4716_config {
	const char *i2c_bus;
	uint16_t i2c_addr;
	uint8_t resolution;
};

struct mcp4716_data {
	const struct device *i2c;
	uint8_t configured;
};

int mcp4716_all_mem_reg_update(const struct device *dev, uint16_t value,
			 uint8_t pd, uint8_t vref, uint8_t g)
{
	struct mcp4716_data *data = dev->data;
	const struct mcp4716_config *cfg = dev->config;
	uint8_t buf[3];
	
	buf[0] = 0x60 | ((vref << 3) & 0x18) | ((pd << 1) & 0x06) | (g & 0x01);
	buf[1] = (value >> 2) & 0xFF;
	buf[2] = (value << 6) & 0xC0;

	return i2c_write(data->i2c, buf, sizeof(buf), cfg->i2c_addr);
}

int mcp4716_dac_vol_reg_update(const struct device *dev, uint16_t value,
			 uint8_t pd)
{
	struct mcp4716_data *data = dev->data;
	const struct mcp4716_config *cfg = dev->config;
	uint8_t buf[2];
	
	buf[0] = ((value >> 6) | ((pd << 4) & 0x30)) & 0x3F;
	buf[1] = (value << 2) & 0xFC;

	return i2c_write(data->i2c, buf, sizeof(buf), cfg->i2c_addr);
}

static int mcp4716_channel_setup(const struct device *dev,
				   const struct dac_channel_cfg *channel_cfg)
{
	const struct mcp4716_config *config = dev->config;
	struct mcp4716_data *data = dev->data;
	int ret;

	if (channel_cfg->channel_id > MCP4716_MAX_CHANNEL - 1) {
		LOG_ERR("Unsupported channel %d", channel_cfg->channel_id);
		return -ENOTSUP;
	}

	if (channel_cfg->resolution != config->resolution) {
		LOG_ERR("Unsupported resolution %d", channel_cfg->resolution);
		return -ENOTSUP;
	}

	if (data->configured & BIT(channel_cfg->channel_id)) {
		LOG_DBG("Channel %d already configured", channel_cfg->channel_id);
		return 0;
	}

	ret = mcp4716_all_mem_reg_update(dev, MCP4716_NV_DAC_CONFIG,
			 MCP4716_PD_BITS_CONFIG, MCP4716_VREF_BITS_CONFIG, MCP4716_G_BITS_CONFIG);
	if (ret) {
		LOG_ERR("Unable to update DEVICE_CONFIG register");
		return -EIO;
	}

	data->configured |= BIT(channel_cfg->channel_id);

	LOG_DBG("Channel %d initialized", channel_cfg->channel_id);

	return 0;
}

static int mcp4716_write_value(const struct device *dev, uint8_t channel,
				uint32_t value)
{
	const struct mcp4716_config *config = dev->config;
	struct mcp4716_data *data = dev->data;
	int ret;

	if (channel > MCP4716_MAX_CHANNEL - 1) {
		LOG_ERR("Unsupported channel %d", channel);
		return -ENOTSUP;
	}

	if (!(data->configured & BIT(channel))) {
		LOG_ERR("Channel %d not initialized", channel);
		return -EINVAL;
	}

	if (value >= (1 << (config->resolution))) {
		LOG_ERR("Value %d out of range", value);
		return -EINVAL;
	}

	ret = mcp4716_dac_vol_reg_update(dev, value, MCP4716_PD_BITS_CONFIG);
	if (ret) {
		LOG_ERR("Unable to set value %d on channel %d", value, channel);
		return -EIO;
	}

	return 0;
}

static int mcp4716_soft_reset(const struct device *dev)
{
	struct mcp4716_data *data = dev->data;
	uint16_t addr = MCP4716_SW_ADDR;
	int ret;

	ret = i2c_write(data->i2c, NULL, 0, addr);
	if (ret) {
		return -EIO;
	}
	k_msleep(MCP4716_POR_DELAY);

	return 0;
}

static int mcp4716_init(const struct device *dev)
{
	const struct mcp4716_config *config = dev->config;
	struct mcp4716_data *data = dev->data;
	int ret;

	data->i2c = device_get_binding(config->i2c_bus);
	if (!data->i2c) {
		LOG_ERR("Could not find I2C device");
		return -EINVAL;
	}

	ret = mcp4716_soft_reset(dev);
	if (ret) {
		LOG_ERR("Soft-reset failed");
		return ret;
	}

	data->configured = 0;

	LOG_DBG("Init complete");

	return 0;
}

static const struct dac_driver_api mcp4716_driver_api = {
	.channel_setup = mcp4716_channel_setup,
	.write_value = mcp4716_write_value,
};

#define CREATE_DAC_MCP4716_DEVICE(inst)                              \
     static struct mcp4716_data mcp4716_data_##inst;                 \
     static const struct mcp4716_config mcp4716_config_##inst = {    \
		.i2c_bus = DT_BUS_LABEL(DT_INST(inst, microchip_mcp4716)),   \
		.i2c_addr = DT_REG_ADDR(DT_INST(inst, microchip_mcp4716)),   \
		.resolution = 10,                                            \
     };                                                              \
     DEVICE_DT_INST_DEFINE(inst,                                     \
                           mcp4716_init,                             \
                           NULL,                                     \
                           &mcp4716_data_##inst,                     \
                           &mcp4716_config_##inst,                   \
                           POST_KERNEL,                              \
						   CONFIG_DAC_MCP4716_INIT_PRIORITY,         \
                           &mcp4716_driver_api);

/* Call the device creation macro for each instance: */
DT_INST_FOREACH_STATUS_OKAY(CREATE_DAC_MCP4716_DEVICE)
