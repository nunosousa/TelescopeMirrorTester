#define DT_DRV_COMPAT microchip_mcp4716

#include <zephyr.h>
#include <drivers/i2c.h>
#include <drivers/dac.h>
#include <logging/log.h>

LOG_MODULE_REGISTER(dac_mcp4716, CONFIG_DAC_LOG_LEVEL);

/* Information in this file comes from MCP4716 datasheet revision D
 * found at https://ww1.microchip.com/downloads/en/DeviceDoc/22272C.pdf
 */

/* Defines for field values in MCP4716 DAC register */
#define MCP4716_DAC_MAX_VAL						0x7FF

#define MCP4716_FAST_MODE_POWER_DOWN_POS		4U
#define MCP4716_FAST_MODE_DAC_UPPER_VAL_POS		6U
#define MCP4716_FAST_MODE_DAC_UPPER_VAL_MASK	0x0F
#define MCP4716_FAST_MODE_DAC_LOWER_VAL_POS		2U
#define MCP4716_FAST_MODE_DAC_LOWER_VAL_MASK	0xFC

#define MCP4716_READ_RDY_POS					7U
#define MCP4716_READ_RDY_MASK					(0x1 << MCP4716_READ_RDY_POS)

/* After writing eeprom, the MCP4716 can be in a busy state for 25 - 50ms
 * See section 1.0 of MCP4716 datasheet, 'Electrical Characteristics'
 */
#define MCP4716_BUSY_TIMEOUT_MS					60U

struct mcp4716_config {
	const struct device *i2c_dev;
	uint16_t i2c_addr;
};

/* Read mcp4716 and check RDY status bit */
static int mcp4716_wait_until_ready(const struct device *dev, uint16_t i2c_addr)
{
	uint8_t rx_data[6];
	bool mcp4716_ready = false;
	int ret;
	uint32_t timeout = k_uptime_get_32() + MCP4716_BUSY_TIMEOUT_MS;

	/* Wait until RDY bit is set or return error if timer exceeds MCP4716_BUSY_TIMEOUT_MS */
	while (!mcp4716_ready) {
		ret = i2c_read(dev, rx_data, sizeof(rx_data), i2c_addr);

		if (ret == 0) {
			mcp4716_ready = rx_data[0] & MCP4716_READ_RDY_MASK;
		} else {
			/* I2C error */
			return ret;
		}

		if (k_uptime_get_32() > timeout) {
			return -ETIMEDOUT;
		}
	}

	return 0;
}

/* MCP4716 is a single channel 10 bit DAC */
static int mcp4716_channel_setup(const struct device *dev,
				   const struct dac_channel_cfg *channel_cfg)
{
	if (channel_cfg->channel_id != 0) {
		return -EINVAL;
	}

	if (channel_cfg->resolution != 10) {
		return -ENOTSUP;
	}

	return 0;
}

static int mcp4716_write_value(const struct device *dev, uint8_t channel,
				uint32_t value)
{
	const struct mcp4716_config *config = (struct mcp4716_config *)dev->config;
	uint8_t tx_data[2];
	int ret;

	if (channel != 0) {
		return -EINVAL;
	}

	/* Check value isn't over 10 bits */
	if (value > MCP4716_DAC_MAX_VAL) {
		return -ENOTSUP;
	}

	/* WRITE_MODE_FAST message format (2 bytes):
	 *
	 * ||     15 14     |        13 12        |     9 8 7 6     || 5 4 3 2 1 0 x x ||
	 * || Fast mode (0) | Power-down bits (0) | DAC value[11:8] || DAC value[7:0]  ||
	 */
	tx_data[0] = ((value >> MCP4716_FAST_MODE_DAC_UPPER_VAL_POS)
		& MCP4716_FAST_MODE_DAC_UPPER_VAL_MASK);
	tx_data[1] = ((value << MCP4716_FAST_MODE_DAC_LOWER_VAL_POS)
		& MCP4716_FAST_MODE_DAC_LOWER_VAL_MASK);
	ret = i2c_write(config->i2c_dev, tx_data, sizeof(tx_data),
		config->i2c_addr);

	return ret;
}

static int dac_mcp4716_init(const struct device *dev)
{
	const struct mcp4716_config *config = dev->config;

	if (!device_is_ready(config->i2c_dev)) {
		LOG_ERR("I2C device not found");
		return -EINVAL;
	}

	/* Check we can read a 'RDY' bit from this device */
	if (mcp4716_wait_until_ready(config->i2c_dev, config->i2c_addr)) {
		LOG_ERR("I2C device failed init");
		return -EBUSY;
	}

	return 0;
}

static const struct dac_driver_api mcp4716_driver_api = {
	.channel_setup = mcp4716_channel_setup,
	.write_value = mcp4716_write_value,
};


#define INST_DT_MCP4716(index)										\
	static const struct mcp4716_config mcp4716_config_##index = {	\
		.i2c_dev = DEVICE_DT_GET(DT_INST_BUS(index)),				\
		.i2c_addr = DT_INST_REG_ADDR(index)							\
	};																\
																	\
	DEVICE_DT_INST_DEFINE(index, dac_mcp4716_init,					\
			    NULL, NULL,											\
			    &mcp4716_config_##index, POST_KERNEL,				\
			    CONFIG_DAC_MCP4716_INIT_PRIORITY,					\
			    &mcp4716_driver_api);

DT_INST_FOREACH_STATUS_OKAY(INST_DT_MCP4716);
