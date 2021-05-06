#include <zephyr.h>
#include <kernel.h>
#include <drivers/i2c.h>
#include <drivers/dac.h>
#include <sys/util.h>
#include <sys/byteorder.h>
#include <sys/__assert.h>
#include <logging/log.h>

LOG_MODULE_REGISTER(dac_mcp4716, CONFIG_DAC_LOG_LEVEL);

/* Register addresses */
#define MCP4716_REG_DEVICE_CONFIG  0x01U
#define MCP4716_REG_STATUS_TRIGGER 0x02U
#define MCP4716_REG_BRDCAST        0x03U
#define MCP4716_REG_DACA_DATA      0x08U

#define MCP4716_DEVICE_ID      0x500	/* STATUS_TRIGGER[DEVICE_ID] */
#define MCP4716_DEVICE_ID      0x300	/* STATUS_TRIGGER[DEVICE_ID] */
#define MCP4716_SW_RST         0x0A	/* STATUS_TRIGGER[SW_RST] */
#define MCP4716_POR_DELAY      5
#define MCP4716_MAX_CHANNEL    8

struct mcp4716_config {
	const char *i2c_bus;
	uint16_t i2c_addr;
	uint8_t resolution;
};

struct mcp4716_data {
	const struct device *i2c;
	uint8_t configured;
};

static int mcp4716_reg_read(const struct device *dev, uint8_t reg,
			      uint16_t *val)
{
	struct mcp4716_data *data = dev->data;
	const struct mcp4716_config *cfg = dev->config;

	if (i2c_burst_read(data->i2c, cfg->i2c_addr,
			   reg, (uint8_t *) val, 2) < 0) {
		LOG_ERR("I2C read failed");
		return -EIO;
	}

	*val = sys_be16_to_cpu(*val);

	return 0;
}

static int mcp4716_reg_write(const struct device *dev, uint8_t reg,
			       uint16_t val)
{
	struct mcp4716_data *data = dev->data;
	const struct mcp4716_config *cfg = dev->config;
	uint8_t buf[3] = {reg, val >> 8, val & 0xFF};

	return i2c_write(data->i2c, buf, sizeof(buf), cfg->i2c_addr);
}

int mcp4716_reg_update(const struct device *dev, uint8_t reg,
			 uint16_t mask, bool setting)
{
	uint16_t regval;
	int ret;

	ret = mcp4716_reg_read(dev, reg, &regval);
	if (ret) {
		return -EIO;
	}

	if (setting) {
		regval |= mask;
	} else {
		regval &= ~mask;
	}

	ret = mcp4716_reg_write(dev, reg, regval);
	if (ret) {
		return ret;
	}

	return 0;
}

static int mcp4716_channel_setup(const struct device *dev,
				   const struct dac_channel_cfg *channel_cfg)
{
	const struct mcp4716_config *config = dev->config;
	struct mcp4716_data *data = dev->data;
	bool setting = false;
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

	/* Clear PDNn bit */
	ret = mcp4716_reg_update(dev, MCP4716_REG_DEVICE_CONFIG,
				BIT(channel_cfg->channel_id), setting);
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
	uint16_t regval;
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

	regval = value << 2;
	regval &= 0xFFFF;

	ret = mcp4716_reg_write(dev, MCP4716_REG_DACA_DATA + channel, regval);
	if (ret) {
		LOG_ERR("Unable to set value %d on channel %d", value, channel);
		return -EIO;
	}

	return 0;
}

static int mcp4716_soft_reset(const struct device *dev)
{
	uint16_t regval = MCP4716_SW_RST;
	int ret;

	ret = mcp4716_reg_write(dev, MCP4716_REG_STATUS_TRIGGER, regval);
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

#define INST_DT_MCP4716(inst) DT_INST(inst, microchip_mcp4716)

#define DAC_MCP4716_DEVICE(n) \
	static struct mcp4716_data mcp4716_data_##n; \
	static const struct mcp4716_config mcp4716_config_##n = { \
		.i2c_bus = DT_BUS_LABEL(INST_DT_MCP4716(n)), \
		.i2c_addr = DT_REG_ADDR(INST_DT_MCP4716(n)), \
		.resolution = 10, \
	}; \
	DEVICE_DT_DEFINE(INST_DT_MCP4716(n), \
				&mcp4716_init, device_pm_control_nop, \
				&mcp4716_data_##n, \
				&mcp4716_config_##n, POST_KERNEL, \
				CONFIG_DAC_MCP4716_INIT_PRIORITY, \
				&mcp4716_driver_api)

#define CALL_WITH_ARG(arg, expr) expr(arg)

#define INST_DT_DAC_MCP4716_FOREACH(inst_expr) \
	UTIL_LISTIFY(DT_NUM_INST_STATUS_OKAY(microchip_mcp4716), \
		     CALL_WITH_ARG, inst_expr)

INST_DT_DAC_MCP4716_FOREACH(DAC_MCP4716_DEVICE);
