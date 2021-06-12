#define DT_DRV_COMPAT pixart_pmw3360

#include <zephyr.h>
#include <device.h>

#include <drivers/video.h>
#include <drivers/spi.h>
#include <drivers/gpio.h>

#include <logging/log.h>

LOG_MODULE_REGISTER(pmw3360, CONFIG_LOG_DEFAULT_LEVEL);


/* Timings defined by spec */
#define T_NCS_SCLK	1			/* 120 ns */
#define T_SRX		(20 - T_NCS_SCLK)	/* 20 us */
#define T_SCLK_NCS_WR	(35 - T_NCS_SCLK)	/* 35 us */
#define T_SWX		(180 - T_SCLK_NCS_WR)	/* 180 us */
#define T_SRAD		160			/* 160 us */
#define T_SRAD_MOTBR	35			/* 35 us */
#define T_BEXIT		1			/* 500 ns */

/* Timing defined on SROM download burst mode figure */
#define T_BRSEP		15			/* 15 us */

/* Timing defined on frame capture download burst mode figure */
#define T_LOAD		15			/* 15 us */


/* Sensor registers */
#define PMW3360_REG_PRODUCT_ID			0x00
#define PMW3360_REG_REVISION_ID			0x01
#define PMW3360_REG_MOTION			0x02
#define PMW3360_REG_DELTA_X_L			0x03
#define PMW3360_REG_DELTA_X_H			0x04
#define PMW3360_REG_DELTA_Y_L			0x05
#define PMW3360_REG_DELTA_Y_H			0x06
#define PMW3360_REG_SQUAL			0x07
#define PMW3360_REG_RAW_DATA_SUM		0x08
#define PMW3360_REG_MAXIMUM_RAW_DATA		0x09
#define PMW3360_REG_MINIMUM_RAW_DATA		0x0A
#define PMW3360_REG_SHUTTER_LOWER		0x0B
#define PMW3360_REG_SHUTTER_UPPER		0x0C
#define PMW3360_REG_CONTROL			0x0D
#define PMW3360_REG_CONFIG1			0x0F
#define PMW3360_REG_CONFIG2			0x10
#define PMW3360_REG_ANGLE_TUNE			0x11
#define PMW3360_REG_FRAME_CAPTURE		0x12
#define PMW3360_REG_SROM_ENABLE			0x13
#define PMW3360_REG_RUN_DOWNSHIFT		0x14
#define PMW3360_REG_REST1_RATE_LOWER		0x15
#define PMW3360_REG_REST1_RATE_UPPER		0x16
#define PMW3360_REG_REST1_DOWNSHIFT		0x17
#define PMW3360_REG_REST2_RATE_LOWER		0x18
#define PMW3360_REG_REST2_RATE_UPPER		0x19
#define PMW3360_REG_REST2_DOWNSHIFT		0x1A
#define PMW3360_REG_REST3_RATE_LOWER		0x1B
#define PMW3360_REG_REST3_RATE_UPPER		0x1C
#define PMW3360_REG_OBSERVATION			0x24
#define PMW3360_REG_DATA_OUT_LOWER		0x25
#define PMW3360_REG_DATA_OUT_UPPER		0x26
#define PMW3360_REG_RAW_DATA_DUMP		0x29
#define PMW3360_REG_SROM_ID			0x2A
#define PMW3360_REG_MIN_SQ_RUN			0x2B
#define PMW3360_REG_RAW_DATA_THRESHOLD		0x2C
#define PMW3360_REG_CONFIG5			0x2F
#define PMW3360_REG_POWER_UP_RESET		0x3A
#define PMW3360_REG_SHUTDOWN			0x3B
#define PMW3360_REG_INVERSE_PRODUCT_ID		0x3F
#define PMW3360_REG_LIFTCUTOFF_TUNE3		0x41
#define PMW3360_REG_ANGLE_SNAP			0x42
#define PMW3360_REG_LIFTCUTOFF_TUNE1		0x4A
#define PMW3360_REG_MOTION_BURST		0x50
#define PMW3360_REG_LIFTCUTOFF_TUNE_TIMEOUT	0x58
#define PMW3360_REG_LIFTCUTOFF_TUNE_MIN_LENGTH	0x5A
#define PMW3360_REG_SROM_LOAD_BURST		0x62
#define PMW3360_REG_LIFT_CONFIG			0x63
#define PMW3360_REG_RAW_DATA_BURST		0x64
#define PMW3360_REG_LIFTCUTOFF_TUNE2		0x65

/* Sensor identification values */
#define PMW3360_PRODUCT_ID			0x42
#define PMW3360_FIRMWARE_ID			0x04

#define SPI_WRITE_BIT				BIT(7)


extern const size_t pmw3360_firmware_length;
extern const uint8_t pmw3360_firmware_data[];

enum async_init_step {
	ASYNC_INIT_STEP_POWER_UP,
	ASYNC_INIT_STEP_FW_LOAD_START,
	ASYNC_INIT_STEP_FW_LOAD_CONTINUE,
	ASYNC_INIT_STEP_FW_LOAD_VERIFY,
	ASYNC_INIT_STEP_CONFIGURE,
	ASYNC_INIT_STEP_COUNT
};

static const int32_t async_init_delay[ASYNC_INIT_STEP_COUNT] = {
	[ASYNC_INIT_STEP_POWER_UP]         = 1,
	[ASYNC_INIT_STEP_FW_LOAD_START]    = 50,
	[ASYNC_INIT_STEP_FW_LOAD_CONTINUE] = 10,
	[ASYNC_INIT_STEP_FW_LOAD_VERIFY]   = 1,
	[ASYNC_INIT_STEP_CONFIGURE]        = 0,
};

static int pmw3360_async_init_power_up(struct pmw3360_data *dev_data);
static int pmw3360_async_init_fw_load_start(struct pmw3360_data *dev_data);
static int pmw3360_async_init_fw_load_continue(struct pmw3360_data *dev_data);
static int pmw3360_async_init_fw_load_verify(struct pmw3360_data *dev_data);
static int pmw3360_async_init_configure(struct pmw3360_data *dev_data);

static int (* const async_init_fn[ASYNC_INIT_STEP_COUNT])(struct pmw3360_data *dev_data) = {
	[ASYNC_INIT_STEP_POWER_UP] = pmw3360_async_init_power_up,
	[ASYNC_INIT_STEP_FW_LOAD_START] = pmw3360_async_init_fw_load_start,
	[ASYNC_INIT_STEP_FW_LOAD_CONTINUE] = pmw3360_async_init_fw_load_continue,
	[ASYNC_INIT_STEP_FW_LOAD_VERIFY] = pmw3360_async_init_fw_load_verify,
	[ASYNC_INIT_STEP_CONFIGURE] = pmw3360_async_init_configure,
};

enum frame_capture_step {
	FRAME_CAPTURE_STEP_SETUP,
	FRAME_CAPTURE_STEP_BURST_READ,
	FRAME_CAPTURE_STEP_COUNT
};

static const int32_t frame_capture_delay[FRAME_CAPTURE_STEP_COUNT] = {
	[FRAME_CAPTURE_STEP_SETUP]         = 0,
	[FRAME_CAPTURE_STEP_BURST_READ]    = 20,
};

static int pmw3360_frame_capture_setup(struct pmw3360_data *dev_data);
static int pmw3360_frame_capture_burst_read(struct pmw3360_data *dev_data);

static int (* const frame_capture_fn[FRAME_CAPTURE_STEP_COUNT])(struct pmw3360_data *dev_data) = {
	[FRAME_CAPTURE_STEP_SETUP] = pmw3360_frame_capture_setup,
	[FRAME_CAPTURE_STEP_BURST_READ] = pmw3360_frame_capture_burst_read,
};

struct pmw3360_data {
	struct k_work_delayable		init_work;
	struct k_work_delayable		frame_capture_work;
	struct video_format			fmt;
	const struct device			*cs_gpio_dev;
	const gpio_pin_t			cs_gpio_pin;
	const struct device			*spi_dev;
	const struct spi_config		spi_cfg;
	enum async_init_step		async_init_step;
	enum frame_capture_step		frame_capture_step;
	int							err;
	bool						ready;
};

static const struct video_format_cap fmts[] = {
	{
		.pixelformat = 0,
		.width_min = 36,
		.width_max = 36,
		.height_min = 36,
		.height_max = 36,
		.width_step = 0,
		.height_step = 0,
	},
	{ 0 }
};


static int spi_cs_ctrl(struct pmw3360_data *dev_data, bool enable)
{
	int val = (enable) ? (0) : (1);
	int err;

	if (!enable) {
		k_busy_wait(T_NCS_SCLK);
	}

	err = gpio_pin_set_raw(dev_data->cs_gpio_dev, dev_data->cs_gpio_pin, val);

	if (err) {
		LOG_ERR("SPI CS ctrl failed");
	}

	if (enable) {
		k_busy_wait(T_NCS_SCLK);
	}

	return err;
}

static int reg_read(struct pmw3360_data *dev_data, uint8_t reg, uint8_t *buf)
{
	int err;

	__ASSERT_NO_MSG((reg & SPI_WRITE_BIT) == 0);

	err = spi_cs_ctrl(dev_data, true);
	if (err) {
		return err;
	}

	/* Write register address. */
	const struct spi_buf tx_buf = {
		.buf = &reg,
		.len = 1
	};
	const struct spi_buf_set tx = {
		.buffers = &tx_buf,
		.count = 1
	};

	err = spi_write(dev_data->spi_dev, &dev_data->spi_cfg, &tx);
	if (err) {
		LOG_ERR("Reg read failed on SPI write");
		return err;
	}

	k_busy_wait(T_SRAD);

	/* Read register value. */
	struct spi_buf rx_buf = {
		.buf = buf,
		.len = 1,
	};
	const struct spi_buf_set rx = {
		.buffers = &rx_buf,
		.count = 1,
	};

	err = spi_read(dev_data->spi_dev, &dev_data->spi_cfg, &rx);
	if (err) {
		LOG_ERR("Reg read failed on SPI read");
		return err;
	}

	err = spi_cs_ctrl(dev_data, false);
	if (err) {
		return err;
	}

	k_busy_wait(T_SRX);

	return 0;
}

static int reg_write(struct pmw3360_data *dev_data, uint8_t reg, uint8_t val)
{
	int err;

	__ASSERT_NO_MSG((reg & SPI_WRITE_BIT) == 0);

	err = spi_cs_ctrl(dev_data, true);
	if (err) {
		return err;
	}

	uint8_t buf[] = {
		SPI_WRITE_BIT | reg,
		val
	};
	const struct spi_buf tx_buf = {
		.buf = buf,
		.len = ARRAY_SIZE(buf)
	};
	const struct spi_buf_set tx = {
		.buffers = &tx_buf,
		.count = 1
	};

	err = spi_write(dev_data->spi_dev, &dev_data->spi_cfg, &tx);
	if (err) {
		LOG_ERR("Reg write failed on SPI write");
		return err;
	}

	k_busy_wait(T_SCLK_NCS_WR);

	err = spi_cs_ctrl(dev_data, false);
	if (err) {
		return err;
	}

	k_busy_wait(T_SWX);

	return 0;
}

static int burst_write(struct pmw3360_data *dev_data, uint8_t reg, const uint8_t *buf,
		       size_t size)
{
	int err;

	err = spi_cs_ctrl(dev_data, true);
	if (err) {
		return err;
	}

	/* Write address of burst register */
	uint8_t write_buf = reg | SPI_WRITE_BIT;
	struct spi_buf tx_buf = {
		.buf = &write_buf,
		.len = 1
	};
	const struct spi_buf_set tx = {
		.buffers = &tx_buf,
		.count = 1
	};

	err = spi_write(dev_data->spi_dev, &dev_data->spi_cfg, &tx);
	if (err) {
		LOG_ERR("Burst write failed on SPI write");
		return err;
	}

	/* Write data */
	for (size_t i = 0; i < size; i++) {
		write_buf = buf[i];

		k_busy_wait(T_BRSEP);

		err = spi_write(dev_data->spi_dev, &dev_data->spi_cfg, &tx);
		if (err) {
			LOG_ERR("Burst write failed on SPI write (data)");
			return err;
		}
	}
	
	k_busy_wait(T_BRSEP);

	/* Terminate burst mode. */
	err = spi_cs_ctrl(dev_data, false);
	if (err) {
		return err;
	}

	k_busy_wait(T_BEXIT);

	return 0;
}

static int burst_read(struct pmw3360_data *dev_data, uint8_t reg, uint8_t *buf,
		       size_t size)
{
	int err;

	err = spi_cs_ctrl(dev_data, true);
	if (err) {
		return err;
	}

	/* Write address of burst register */
	const struct spi_buf tx_buf = {
		.buf = &reg,
		.len = 1
	};
	const struct spi_buf_set tx = {
		.buffers = &tx_buf,
		.count = 1
	};

	err = spi_write(dev_data->spi_dev, &dev_data->spi_cfg, &tx);
	if (err) {
		LOG_ERR("Burst write failed on SPI write");
		return err;
	}

	k_busy_wait(T_SRAD);

	/* Burst read data */
	uint8_t read_buf;
	struct spi_buf rx_buf = {
		.buf = read_buf,
		.len = 1,
	};
	const struct spi_buf_set rx = {
		.buffers = &rx_buf,
		.count = 1,
	};

	for (size_t i = 0; i < size; i++) {

		err = spi_read(dev_data->spi_dev, &dev_data->spi_cfg, &rx);
		if (err) {
			LOG_ERR("Burst read failed on SPI read (data)");
			return err;

		}
		buf[i] = read_buf;

		k_busy_wait(T_LOAD);
	}

	/* Terminate burst mode. */
	err = spi_cs_ctrl(dev_data, false);
	if (err) {
		return err;
	}

	k_busy_wait(T_BEXIT);

	return 0;
}

static int pmw3360_async_init_fw_load_start(struct pmw3360_data *dev_data)
{
	int err = 0;

	/* Read from registers 0x02-0x06 regardless of the motion pin state. */
	for (uint8_t reg = 0x02; (reg <= 0x06) && !err; reg++) {
		uint8_t buf[1];
		err = reg_read(dev_data, reg, buf);
	}

	if (err) {
		LOG_ERR("Cannot read from data registers");
		return err;
	}

	/* Write 0 to Rest_En bit of Config2 register to disable Rest mode. */
	err = reg_write(dev_data, PMW3360_REG_CONFIG2, 0x00);
	if (err) {
		LOG_ERR("Cannot disable REST mode");
		return err;
	}

	/* Write 0x1D in SROM_enable register to initialize the operation */
	err = reg_write(dev_data, PMW3360_REG_SROM_ENABLE, 0x1D);
	if (err) {
		LOG_ERR("Cannot initialize SROM");
		return err;
	}

	return err;
}

static int pmw3360_async_init_fw_load_continue(struct pmw3360_data *dev_data)
{
	int err;

	LOG_INF("Uploading optical sensor firmware...");

	/* Write 0x18 to SROM_enable to start SROM download */
	err = reg_write(dev_data, PMW3360_REG_SROM_ENABLE, 0x18);
	if (err) {
		LOG_ERR("Cannot start SROM download");
		return err;
	}

	/* Write SROM file into SROM_Load_Burst register.
	 * Data must start with SROM_Load_Burst address.
	 */
	err = burst_write(dev_data, PMW3360_REG_SROM_LOAD_BURST,
			  pmw3360_firmware_data, pmw3360_firmware_length);
	if (err) {
		LOG_ERR("Cannot write firmware to sensor");
	}

	return err;
}

static int pmw3360_async_init_fw_load_verify(struct pmw3360_data *dev_data)
{
	int err;

	/* Read the SROM_ID register to verify the firmware ID before any
	 * other register reads or writes
	 */

	uint8_t fw_id;
	err = reg_read(dev_data, PMW3360_REG_SROM_ID, &fw_id);
	if (err) {
		LOG_ERR("Cannot obtain firmware id");
		return err;
	}

	LOG_DBG("Optical chip firmware ID: 0x%x", fw_id);
	if (fw_id != PMW3360_FIRMWARE_ID) {
		LOG_ERR("Chip is not running from SROM!");
		return -EIO;
	}

	uint8_t product_id;
	err = reg_read(dev_data, PMW3360_REG_PRODUCT_ID, &product_id);
	if (err) {
		LOG_ERR("Cannot obtain product id");
		return err;
	}

	if (product_id != PMW3360_PRODUCT_ID) {
		LOG_ERR("Invalid product id!");
		return -EIO;
	}

	/* Write 0x00 to Config2 register for wired mouse design.
	 * This enables entering rest modes.
	 */
	err = reg_write(dev_data, PMW3360_REG_CONFIG2, 0x00);
	if (err) {
		LOG_ERR("Cannot enable REST modes");
	}

	return err;
}

static int pmw3360_async_init_power_up(struct pmw3360_data *dev_data)
{
	/* Reset sensor */
	return reg_write(dev_data, PMW3360_REG_POWER_UP_RESET, 0x5A);
}

static int pmw3360_async_init_configure(struct pmw3360_data *dev_data)
{
	int err = 0;

	return err;
}

static void pmw3360_async_init(struct k_work *work)
{
	struct pmw3360_data *dev_data;


	dev_data = CONTAINER_OF(work, struct pmw3360_data, init_work);

	ARG_UNUSED(work);

	LOG_DBG("PMW3360 async init step %d", dev_data->async_init_step);

	dev_data->err = async_init_fn[dev_data->async_init_step](dev_data);
	if (dev_data->err) {
		LOG_ERR("PMW3360 initialization failed");
	} else {
		dev_data->async_init_step++;

		if (dev_data->async_init_step == ASYNC_INIT_STEP_COUNT) {
			dev_data->ready = true;
			LOG_INF("PMW3360 initialized");
		} else {
			k_work_reschedule(&dev_data->init_work,
					      K_MSEC(async_init_delay[dev_data->async_init_step]));
		}
	}
}

static int pmw3360_frame_capture_setup(struct pmw3360_data *dev_data)
{
	int err = 0;
	
	/* Set frame capture */
	err = reg_write(dev_data, PMW3360_REG_FRAME_CAPTURE, 0x83);
	if (err) {
		LOG_ERR("Cannot configure Frame_Capture register");
		return err;
	}

	/* Set frame capture */
	err = reg_write(dev_data, PMW3360_REG_FRAME_CAPTURE, 0xC5);
	if (err) {
		LOG_ERR("Cannot configure Frame_Capture register");
		return err;
	}

	return err;
}

static int pmw3360_frame_capture_burst_read(struct pmw3360_data *dev_data)
{
	int err = 0;

	return err;
}

static void pmw3360_frame_capture_init(struct k_work *work)
{
	struct pmw3360_data *dev_data;


	dev_data = CONTAINER_OF(work, struct pmw3360_data, frame_capture_work);

	ARG_UNUSED(work);

	LOG_DBG("PMW3360 async init step %d", dev_data->frame_capture_step);

	dev_data->err = async_init_fn[dev_data->frame_capture_step](dev_data);
	if (dev_data->err) {
		LOG_ERR("PMW3360 initialization failed");
	} else {
		dev_data->frame_capture_step++;

		if (dev_data->frame_capture_step == ASYNC_INIT_STEP_COUNT) {
			dev_data->ready = true;
			LOG_INF("PMW3360 initialized");
		} else {
			k_work_reschedule(&dev_data->frame_capture_work,
					      K_MSEC(frame_capture_delay[dev_data->frame_capture_step]));
		}
	}
}

static int pmw3360_init_cs(struct pmw3360_data *dev_data)
{
	int err;

	if (!device_is_ready(dev_data->cs_gpio_dev)) {
		LOG_ERR("CS GPIO device not found");
		return -ENXIO;
	}

	err = gpio_pin_configure(dev_data->cs_gpio_dev, dev_data->cs_gpio_pin,
				 GPIO_OUTPUT);
	if (!err) {
		err = spi_cs_ctrl(dev_data, false);
	} else {
		LOG_ERR("Cannot configure CS PIN");
	}

	return err;
}

static int pmw3360_init_spi(struct pmw3360_data *dev_data)
{
	if (!device_is_ready(dev_data->spi_dev)) {
		LOG_ERR("SPI device not found");
		return -ENXIO;
	}

	return 0;
}

static int pmw3360_set_fmt(const struct device *dev,
			   enum video_endpoint_id ep,
			   struct video_format *fmt)
{
	/* we only support one format */
	if (fmt->pixelformat != 0 || fmt->height != 36 ||
	    fmt->width != 36) {
		return -ENOTSUP;
	}

	return 0;
}

static int pmw3360_get_fmt(const struct device *dev,
			   enum video_endpoint_id ep,
			   struct video_format *fmt)
{
	struct pmw3360_data *dev_data = dev->data;

	*fmt = dev_data->fmt;

	return 0;
}

static int pmw3360_stream_start(const struct device *dev)
{
	struct pmw3360_data *dev_data = dev->data;

	return k_work_schedule(&dev_data->buf_work, K_MSEC(33));
}

static int pmw3360_stream_stop(const struct device *dev)
{
	struct pmw3360_data *dev_data = dev->data;

	k_work_cancel_delayable_sync(&dev_data->buf_work, &dev_data->work_sync);

	return 0;
}

static int pmw3360_enqueue(const struct device *dev,
				      enum video_endpoint_id ep,
				      struct video_buffer *vbuf)
{
	struct pmw3360_data *dev_data = dev->data;

	if (ep != VIDEO_EP_OUT) {
		return -EINVAL;
	}

	k_fifo_put(&dev_data->fifo_in, vbuf);

	return 0;
}

static int pmw3360_dequeue(const struct device *dev,
				      enum video_endpoint_id ep,
				      struct video_buffer **vbuf,
				      k_timeout_t timeout)
{
	struct pmw3360_data *dev_data = dev->data;

	if (ep != VIDEO_EP_OUT) {
		return -EINVAL;
	}

	*vbuf = k_fifo_get(&dev_data->fifo_out, timeout);
	if (*vbuf == NULL) {
		return -EAGAIN;
	}

	return 0;
}

static int pmw3360_flush(const struct device *dev,
				    enum video_endpoint_id ep,
				    bool cancel)
{
	struct pmw3360_data *dev_data = dev->data;
	struct video_buffer *vbuf;

	if (!cancel) {
		/* wait for all buffer to be processed */
		do {
			k_sleep(K_MSEC(1));
		} while (!k_fifo_is_empty(&dev_data->fifo_in));
	} else {
		while ((vbuf = k_fifo_get(&data->fifo_in, K_NO_WAIT))) {
			k_fifo_put(&dev_data->fifo_out, vbuf);
			if (IS_ENABLED(CONFIG_POLL) && dev_data->signal) {
				k_poll_signal_raise(dev_data->signal,
						    VIDEO_BUF_ABORTED);
			}
		}
	}

	return 0;
}

static int pmw3360_get_caps(const struct device *dev,
			    enum video_endpoint_id ep,
			    struct video_caps *caps)
{
	caps->format_caps = fmts;
	return 0;
}

static int pmw3360_init(const struct device *dev)
{
	struct video_format fmt;
	struct pmw3360_data *dev_data = dev->data;
	int err;


	err = pmw3360_init_cs(dev_data);
	if (err) {
		return err;
	}

	err = pmw3360_init_spi(dev_data);
	if (err) {
		return err;
	}
	
	fmt.pixelformat = 0;
	fmt.width = 36;
	fmt.height = 36;
	fmt.pitch = 36;

	err = pmw3360_set_fmt(dev, VIDEO_EP_OUT, &fmt);
	if (err) {
		LOG_ERR("Unable to configure default format");
		return -EIO;
	}

	dev_data->async_init_step = ASYNC_INIT_STEP_POWER_UP;

	k_work_init_delayable(&dev_data->init_work, pmw3360_async_init);

	k_work_reschedule(&dev_data->init_work,
			      K_MSEC(async_init_delay[dev_data->async_init_step]));

	return err;
}

static const struct video_driver_api pmw3360_driver_api = {
	.set_format = pmw3360_set_fmt,
	.get_format = pmw3360_get_fmt,
	.get_caps = pmw3360_get_caps,
	.stream_start = pmw3360_stream_start,
	.stream_stop = pmw3360_stream_stop,
	.flush = pmw3360_flush,
	.enqueue = pmw3360_enqueue,
	.dequeue = pmw3360_dequeue,
};

#define INST_DT_PMW3360(index)										\
	static struct pmw3360_data pmw3360_data_##index = {				\
	.cs_gpio_dev = DEVICE_DT_GET(DT_INST_SPI_DEV_CS_GPIOS_CTLR(index)),\
	.cs_gpio_pin = DT_INST_SPI_DEV_CS_GPIOS_PIN(index),				\
	.spi_dev = DEVICE_DT_GET(DT_INST_BUS(index)),					\
	.spi_cfg.operation = SPI_WORD_SET(8) | SPI_TRANSFER_MSB | SPI_MODE_CPOL | SPI_MODE_CPHA,\
	.spi_cfg.frequency = DT_PROP(DT_DRV_INST(index), spi_max_frequency),\
	.spi_cfg.slave = DT_REG_ADDR(DT_DRV_INST(index)),				\
	};																\
																	\
	DEVICE_DT_INST_DEFINE(index, pmw3360_init,				    	\
			    NULL, &pmw3360_data_##index,						\
			    NULL, POST_KERNEL,									\
			    CONFIG_PMW3360_INIT_PRIORITY,				     	\
			    &pmw3360_driver_api);

DT_INST_FOREACH_STATUS_OKAY(INST_DT_PMW3360);
