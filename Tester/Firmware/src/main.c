#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <drivers/uart.h>
#include <drivers/pwm.h>
#include <drivers/dac.h>
#include <drivers/video.h>
#include <usb/usb_device.h>
#include <shell/shell.h>
#include <string.h>
#include <stdlib.h>

LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);


static int cmd_motor(const struct shell *shell, size_t argc, char **argv)
{
	bool is_positive_motion;
	int32_t pwm_value;
	uint32_t pwm_pos_value, pwm_neg_value, pin_value;
	const struct device *pwm_pos, *pwm_neg;
	const struct device *swtch;

	if (argc != 3) {
		return -1; // Expected 3 arguments.
	}

	pwm_value = atoi(argv[2]);

	if ((pwm_value >= -100) && (pwm_value < 0)) {
		pwm_pos_value = 0;
		pwm_neg_value = ((20U * USEC_PER_MSEC)*(-pwm_value))/100;
		is_positive_motion = false;
	}
	else if ((pwm_value >= 0) && (pwm_value <= 100)) {
		pwm_pos_value = ((20U * USEC_PER_MSEC)*pwm_value)/100;
		pwm_neg_value = 0;
		is_positive_motion = true;
	}
	else {
		return -1; // Setpoint out of range.
	}

	if (strcmp(argv[1], "x") == 0) {
		if (is_positive_motion) {
			swtch = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_positive_x), gpios));
			pin_value = gpio_pin_get(swtch, DT_GPIO_PIN(DT_NODELABEL(switch_positive_x), gpios));

			if (pin_value == 1) {
				return 0;
			}
		} else {
			swtch = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_negative_x), gpios));
			pin_value = gpio_pin_get(swtch, DT_GPIO_PIN(DT_NODELABEL(switch_negative_x), gpios));

			if (pin_value == 1) {
				return 0;
			}
		}

		pwm_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1x_pos))));
		pwm_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1x_neg))));

		pwm_pin_set_usec(pwm_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1x_pos)),
					(20U * USEC_PER_MSEC), pwm_pos_value, 0);
		pwm_pin_set_usec(pwm_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1x_neg)),
					(20U * USEC_PER_MSEC), pwm_neg_value, 0);

	} else if (strcmp(argv[1], "y") == 0) {
		if (is_positive_motion) {
			swtch = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_positive_y), gpios));
			pin_value = gpio_pin_get(swtch, DT_GPIO_PIN(DT_NODELABEL(switch_positive_y), gpios));

			if (pin_value == 1) {
				return 0;
			}
		} else {
			swtch = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_negative_y), gpios));
			pin_value = gpio_pin_get(swtch, DT_GPIO_PIN(DT_NODELABEL(switch_negative_y), gpios));

			if (pin_value == 1) {
				return 0;
			}
		}

		pwm_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1y_pos))));
		pwm_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1y_neg))));

		pwm_pin_set_usec(pwm_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1y_pos)),
					(20U * USEC_PER_MSEC), pwm_pos_value, 0);
		pwm_pin_set_usec(pwm_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1y_neg)),
					(20U * USEC_PER_MSEC), pwm_neg_value, 0);

	} else if (strcmp(argv[1], "z") == 0) {
		if (is_positive_motion) {
			swtch = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_positive_z), gpios));
			pin_value = gpio_pin_get(swtch, DT_GPIO_PIN(DT_NODELABEL(switch_positive_z), gpios));

			if (pin_value == 1) {
				return 0;
			}
		} else {
			swtch = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_negative_z), gpios));
			pin_value = gpio_pin_get(swtch, DT_GPIO_PIN(DT_NODELABEL(switch_negative_z), gpios));

			if (pin_value == 1) {
				return 0;
			}
		}

		pwm_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2z_pos))));
		pwm_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2z_neg))));

		pwm_pin_set_usec(pwm_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2z_pos)),
					(20U * USEC_PER_MSEC), pwm_pos_value, 0);
		pwm_pin_set_usec(pwm_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2z_neg)),
					(20U * USEC_PER_MSEC), pwm_neg_value, 0);

	} else if (strcmp(argv[1], "t") == 0) {
		pwm_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2t_pos))));
		pwm_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2t_neg))));

		shell_print(shell, "enter");

		if (pwm_neg == NULL) {
			shell_print(shell, "NULL neg");
		}

		if (pwm_pos == NULL) {
			shell_print(shell, "NULL pos");
		}
		int ret1, ret2;
		ret1 = pwm_pin_set_usec(pwm_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2t_pos)),
					(20U * USEC_PER_MSEC), pwm_pos_value, 0);
		ret2 = pwm_pin_set_usec(pwm_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2t_neg)),
					(20U * USEC_PER_MSEC), pwm_neg_value, 0);

		if (ret1 == 0) {
			shell_print(shell, "ret1 0");
		}

		if (ret2 == 0) {
			shell_print(shell, "ret2 0");
		}

	} else {
		return -1; // Expected argument not found.
	}

	return 0;
}

static int cmd_laser(const struct shell *shell, size_t argc, char **argv)
{
	int32_t laser_value;
	const struct device *laser;
	const uint32_t dac_max_value = 0x07FF;

	if (argc != 2) {
		return -1; // Expected 2 arguments.
	}

	laser = device_get_binding(DT_LABEL(DT_NODELABEL(laser_dac)));

	laser_value = atoi(argv[1]);

	if((laser_value < 0) || (laser_value > dac_max_value)) {
		shell_error(shell, "Laser intensity must be between 0 and 2047.");
		return -1;
	}

	laser_value = dac_max_value - laser_value;

	return dac_write_value(laser, 0, (uint32_t)laser_value);
}

static int cmd_switches(const struct shell *shell, size_t argc, char **argv)
{
	int32_t laser_value;
	const struct device *laser;
	const uint32_t dac_max_value = 0x07FF;
/*
	sensor = device_get_binding("SERCOM0");

	DT_SPI_DEV_CS_GPIOS_PIN(DT_NODELABEL(x_pos_sensor))
	DT_SPI_DEV_CS_GPIOS_PIN(DT_NODELABEL(y_pos_sensor))

	err = gpio_pin_configure(dev_data->cs_gpio_dev, PMW3360_CS_GPIO_PIN,
				 GPIO_OUTPUT);
	err = gpio_pin_set_raw(dev_data->cs_gpio_dev, PMW3360_CS_GPIO_PIN, val);
*/
	return 0;
}

static int cmd_sensor(const struct shell *shell, size_t argc, char **argv)
{
	struct video_buffer *buffer, *vbuf;
	struct video_format fmt;
	const struct device *video;
	unsigned int frame = 0;
	size_t bsize;
	int i = 0;

	/* Default to software video pattern generator */
	video = device_get_binding(DT_LABEL(DT_NODELABEL(x_pos_sensor)));
	if (video == NULL) {
		LOG_ERR("Video device not found");
		return -1;
	}

	/* Get default/native format */
	if (video_get_format(video, VIDEO_EP_OUT, &fmt)) {
		LOG_ERR("Unable to retrieve video format");
		return -1;
	}

	/* Size to allocate for each buffer */
	bsize = fmt.pitch * fmt.height;

	/* Alloc video buffers and enqueue for capture */
	buffer = video_buffer_alloc(bsize);
	if (buffer == NULL) {
		LOG_ERR("Unable to alloc video buffer of %d", bsize);
		return -1;
	}

	video_enqueue(video, VIDEO_EP_OUT, buffer);

	/* Start video capture */
	if (video_stream_start(video)) {
		LOG_ERR("Unable to start capture (interface)");
		video_buffer_release(buffer);
		return -1;
	}

	return 0;

	/* Grab video frame */
	int err;

	err = video_dequeue(video, VIDEO_EP_OUT, &vbuf, K_FOREVER);
	if (err) {
		LOG_ERR("Unable to dequeue video buf");
		video_buffer_release(buffer);
		return -1;
	}

	/* Stop video capture */
	if (video_stream_stop(video)) {
		LOG_ERR("Unable to stop capture (interface)");
		video_buffer_release(buffer);
		return -1;
	}

	shell_hexdump(shell, vbuf->buffer, bsize);

	video_buffer_release(buffer);

	return 0;
}

SHELL_CMD_REGISTER(motor, NULL, "Set motor pwm duty cycle in {x, y, z or t} axis to % value (range -100 to 100). Usage syntax: motor [axis] [value]", cmd_motor);
SHELL_CMD_REGISTER(laser, NULL, "Set laser intensity to % value (range 0 to 100). Usage syntax: laser [value]", cmd_laser);
SHELL_CMD_REGISTER(switches, NULL, "Report end switches state", cmd_switches);
SHELL_CMD_REGISTER(sensor, NULL, "Report end switches state", cmd_sensor);


static struct gpio_callback sw_px_cb_data, sw_nx_cb_data, sw_py_cb_data,
							sw_ny_cb_data, sw_pz_cb_data, sw_nz_cb_data;

void limit_switch_reached(const struct device *port, struct gpio_callback *cb, gpio_port_pins_t pins)
{	
	const struct device *pwm_pos, *pwm_neg;

	ARG_UNUSED(port);
	ARG_UNUSED(cb);

	switch(pins) {
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_positive_x), gpios)):
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_negative_x), gpios)):
			pwm_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1x_pos))));
			pwm_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1x_neg))));

			pwm_pin_set_usec(pwm_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1x_pos)),
						(20U * USEC_PER_MSEC), 0, 0);
			pwm_pin_set_usec(pwm_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1x_neg)),
						(20U * USEC_PER_MSEC), 0, 0);
			break;
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_positive_y), gpios)):
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_negative_y), gpios)):
			pwm_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1y_pos))));
			pwm_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1y_neg))));

			pwm_pin_set_usec(pwm_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1y_pos)),
						(20U * USEC_PER_MSEC), 0, 0);
			pwm_pin_set_usec(pwm_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1y_neg)),
						(20U * USEC_PER_MSEC), 0, 0);
			break;
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_positive_z), gpios)):
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_negative_z), gpios)):
			pwm_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2z_pos))));
			pwm_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2z_neg))));

			pwm_pin_set_usec(pwm_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2z_pos)),
						(20U * USEC_PER_MSEC), 0, 0);
			pwm_pin_set_usec(pwm_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2z_neg)),
						(20U * USEC_PER_MSEC), 0, 0);
			break;
		default:
			return;
	}
}

void initialize_limit_switches(void)
{
	const struct device *sw_px, *sw_nx, *sw_py, *sw_ny, *sw_pz, *sw_nz;
	int sw_px_ret, sw_nx_ret, sw_py_ret, sw_ny_ret, sw_pz_ret, sw_nz_ret;

	sw_px = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_positive_x), gpios));
	sw_nx = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_negative_x), gpios));
	sw_py = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_positive_y), gpios));
	sw_ny = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_negative_y), gpios));
	sw_pz = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_positive_z), gpios));
	sw_nz = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(switch_negative_z), gpios));

	if ((sw_px == NULL) || (sw_nx == NULL) || (sw_py == NULL)
	|| (sw_ny == NULL) || (sw_pz == NULL) || (sw_nz == NULL)) {
		return;
	}

	sw_px_ret = gpio_pin_configure(sw_px,
									DT_GPIO_PIN(DT_NODELABEL(switch_positive_x), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(switch_positive_x), gpios));
	sw_nx_ret = gpio_pin_configure(sw_nx,
									DT_GPIO_PIN(DT_NODELABEL(switch_negative_x), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(switch_negative_x), gpios));
	sw_py_ret = gpio_pin_configure(sw_py,
									DT_GPIO_PIN(DT_NODELABEL(switch_positive_y), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(switch_positive_y), gpios));
	sw_ny_ret = gpio_pin_configure(sw_ny,
									DT_GPIO_PIN(DT_NODELABEL(switch_negative_y), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(switch_negative_y), gpios));
	sw_pz_ret = gpio_pin_configure(sw_pz,
									DT_GPIO_PIN(DT_NODELABEL(switch_positive_z), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(switch_positive_z), gpios));
	sw_nz_ret = gpio_pin_configure(sw_nz,
									DT_GPIO_PIN(DT_NODELABEL(switch_negative_z), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(switch_negative_z), gpios));

	if ((sw_px_ret != 0) || (sw_nx_ret != 0) || (sw_py_ret != 0)
	|| (sw_ny_ret != 0) || (sw_pz_ret != 0) || (sw_nz_ret != 0)) {
		return;
	}

	sw_px_ret = gpio_pin_interrupt_configure(sw_px,
											DT_GPIO_PIN(DT_NODELABEL(switch_positive_x), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	sw_nx_ret = gpio_pin_interrupt_configure(sw_nx,
											DT_GPIO_PIN(DT_NODELABEL(switch_negative_x), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	sw_py_ret = gpio_pin_interrupt_configure(sw_py,
											DT_GPIO_PIN(DT_NODELABEL(switch_positive_y), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	sw_ny_ret = gpio_pin_interrupt_configure(sw_ny,
											DT_GPIO_PIN(DT_NODELABEL(switch_negative_y), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	sw_pz_ret = gpio_pin_interrupt_configure(sw_pz,
											DT_GPIO_PIN(DT_NODELABEL(switch_positive_z), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	sw_nz_ret = gpio_pin_interrupt_configure(sw_nz,
											DT_GPIO_PIN(DT_NODELABEL(switch_negative_z), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	
	if ((sw_px_ret != 0) || (sw_nx_ret != 0) || (sw_py_ret != 0)
	|| (sw_ny_ret != 0) || (sw_pz_ret != 0) || (sw_nz_ret != 0)) {
		return;
	}

	gpio_init_callback(&sw_px_cb_data, limit_switch_reached,
						BIT(DT_GPIO_PIN(DT_NODELABEL(switch_positive_x), gpios)));
	gpio_init_callback(&sw_nx_cb_data, limit_switch_reached,
						BIT(DT_GPIO_PIN(DT_NODELABEL(switch_negative_x), gpios)));
	gpio_init_callback(&sw_py_cb_data, limit_switch_reached,
						BIT(DT_GPIO_PIN(DT_NODELABEL(switch_positive_y), gpios)));
	gpio_init_callback(&sw_ny_cb_data, limit_switch_reached,
						BIT(DT_GPIO_PIN(DT_NODELABEL(switch_negative_y), gpios)));
	gpio_init_callback(&sw_pz_cb_data, limit_switch_reached,
						BIT(DT_GPIO_PIN(DT_NODELABEL(switch_positive_z), gpios)));
	gpio_init_callback(&sw_nz_cb_data, limit_switch_reached,
						BIT(DT_GPIO_PIN(DT_NODELABEL(switch_negative_z), gpios)));

	gpio_add_callback(sw_px, &sw_px_cb_data);
	gpio_add_callback(sw_nx, &sw_nx_cb_data);
	gpio_add_callback(sw_py, &sw_py_cb_data);
	gpio_add_callback(sw_ny, &sw_ny_cb_data);
	gpio_add_callback(sw_pz, &sw_pz_cb_data);
	gpio_add_callback(sw_nz, &sw_nz_cb_data);
}


static struct gpio_callback motor_alert_cb_data, laser_alert_cb_data;

void power_switch_alert(const struct device *port, struct gpio_callback *cb, gpio_port_pins_t pins)
{

	ARG_UNUSED(port);
	ARG_UNUSED(cb);

}

void initialize_power_switch(void)
{
	const struct device *motor_pwr_switch, *motor_alert, *laser_driver, *laser_alert;
	int motor_pwr_switch_ret, motor_alert_ret, laser_driver_ret, laser_alert_ret;

	motor_pwr_switch = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(motor_power_switch), enable_gpios));
	motor_alert = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(motor_drives_alert), gpios));
	laser_alert = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(laser_drive_alert), gpios));

	if ((motor_pwr_switch == NULL) || (motor_alert == NULL)	|| (laser_alert == NULL)) {
		return;
	}

	motor_pwr_switch_ret = gpio_pin_configure(motor_pwr_switch,
									DT_GPIO_PIN(DT_NODELABEL(motor_power_switch), enable_gpios),
									GPIO_OUTPUT | DT_GPIO_FLAGS(DT_NODELABEL(motor_power_switch), enable_gpios));
	motor_alert_ret = gpio_pin_configure(motor_alert,
									DT_GPIO_PIN(DT_NODELABEL(motor_drives_alert), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(motor_drives_alert), gpios));
	laser_alert_ret = gpio_pin_configure(laser_alert,
									DT_GPIO_PIN(DT_NODELABEL(laser_drive_alert), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(laser_drive_alert), gpios));

	if ((motor_pwr_switch_ret != 0) || (motor_alert_ret != 0) || (laser_alert_ret != 0)) {
		return;
	}

	motor_pwr_switch_ret = gpio_pin_set(motor_pwr_switch, DT_GPIO_PIN(DT_NODELABEL(motor_power_switch), enable_gpios), 1);

	if (motor_pwr_switch_ret != 0) {
		return;
	}

	motor_alert_ret = gpio_pin_interrupt_configure(motor_alert,
											DT_GPIO_PIN(DT_NODELABEL(motor_drives_alert), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	laser_alert_ret = gpio_pin_interrupt_configure(laser_alert,
											DT_GPIO_PIN(DT_NODELABEL(laser_drive_alert), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	
	if ((motor_alert_ret != 0) || (laser_alert_ret != 0)) {
		return;
	}

	gpio_init_callback(&motor_alert_cb_data, power_switch_alert,
						BIT(DT_GPIO_PIN(DT_NODELABEL(motor_drives_alert), gpios)));
	gpio_init_callback(&laser_alert_cb_data, power_switch_alert,
						BIT(DT_GPIO_PIN(DT_NODELABEL(laser_drive_alert), gpios)));

	gpio_add_callback(motor_alert, &motor_alert_cb_data);
	gpio_add_callback(laser_alert, &laser_alert_cb_data);
}


static struct gpio_callback pwm1_alert_cb_data, pwm2_alert_cb_data;

void pwm_alert(const struct device *port, struct gpio_callback *cb, gpio_port_pins_t pins)
{

	ARG_UNUSED(port);
	ARG_UNUSED(cb);

}

void initialize_motor_drives(void)
{
	const struct device *pwm1_sleep, *pwm1_fault, *pwm2_sleep, *pwm2_fault;
	int pwm1_sleep_ret, pwm1_fault_ret, pwm2_sleep_ret, pwm2_fault_ret;

	pwm1_sleep = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(pwm_sleep_1), gpios));
	pwm1_fault = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(pwm_fault_1), gpios));
	pwm2_sleep = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(pwm_sleep_2), gpios));
	pwm2_fault = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(pwm_fault_2), gpios));

	if ((pwm1_sleep == NULL) || (pwm1_fault == NULL) || (pwm2_sleep == NULL) || (pwm2_fault == NULL)) {
		return;
	}

	pwm1_sleep_ret = gpio_pin_configure(pwm1_sleep,
									DT_GPIO_PIN(DT_NODELABEL(pwm_sleep_1), gpios),
									GPIO_OUTPUT | DT_GPIO_FLAGS(DT_NODELABEL(pwm_sleep_1), gpios));
	pwm1_fault_ret = gpio_pin_configure(pwm1_fault,
									DT_GPIO_PIN(DT_NODELABEL(pwm_fault_1), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(pwm_fault_1), gpios));
	pwm2_sleep_ret = gpio_pin_configure(pwm2_sleep,
									DT_GPIO_PIN(DT_NODELABEL(pwm_sleep_2), gpios),
									GPIO_OUTPUT | DT_GPIO_FLAGS(DT_NODELABEL(pwm_sleep_2), gpios));
	pwm2_fault_ret = gpio_pin_configure(pwm2_fault,
									DT_GPIO_PIN(DT_NODELABEL(pwm_fault_2), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(pwm_fault_2), gpios));

	if ((pwm1_sleep_ret != 0) || (pwm1_fault_ret != 0) || (pwm2_sleep_ret != 0)
	|| (pwm2_fault_ret != 0)) {
		return;
	}

	gpio_pin_set(pwm1_sleep, DT_GPIO_PIN(DT_NODELABEL(pwm_sleep_1), gpios), 0);
	gpio_pin_set(pwm2_sleep, DT_GPIO_PIN(DT_NODELABEL(pwm_sleep_2), gpios), 0);

	pwm1_fault_ret = gpio_pin_interrupt_configure(pwm1_fault,
											DT_GPIO_PIN(DT_NODELABEL(pwm_fault_1), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	pwm2_fault_ret = gpio_pin_interrupt_configure(pwm2_fault,
											DT_GPIO_PIN(DT_NODELABEL(pwm_fault_2), gpios),
											GPIO_INT_EDGE_TO_ACTIVE);
	
	if ((pwm1_fault_ret != 0) || (pwm2_fault_ret != 0)) {
		return;
	}

	gpio_init_callback(&pwm1_alert_cb_data, pwm_alert,
						BIT(DT_GPIO_PIN(DT_NODELABEL(pwm_fault_1), gpios)));
	gpio_init_callback(&pwm2_alert_cb_data, pwm_alert,
						BIT(DT_GPIO_PIN(DT_NODELABEL(pwm_fault_2), gpios)));

	gpio_add_callback(pwm1_fault, &pwm1_alert_cb_data);
	gpio_add_callback(pwm2_fault, &pwm2_alert_cb_data);


	const struct device *pwm1_x_pos, *pwm1_x_neg, *pwm1_y_pos, *pwm1_y_neg;
	const struct device *pwm2_z_pos, *pwm2_z_neg, *pwm2_t_pos, *pwm2_t_neg;

	pwm1_x_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1x_pos))));
	pwm1_x_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1x_neg))));
	pwm1_y_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1y_pos))));
	pwm1_y_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm1y_neg))));
	pwm2_z_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2z_pos))));
	pwm2_z_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2z_neg))));
	pwm2_t_pos = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2t_pos))));
	pwm2_t_neg = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm2t_neg))));

	if ((pwm1_x_pos == NULL) || (pwm1_x_neg == NULL) || (pwm1_y_pos == NULL) || (pwm1_y_neg == NULL) ||
	(pwm2_z_pos == NULL) || (pwm2_z_neg == NULL) || (pwm2_t_pos == NULL) || (pwm2_t_neg == NULL)) {
		return;
	}

	pwm_pin_set_usec(pwm1_x_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1x_pos)),
					(20U * USEC_PER_MSEC), 0, 0);
	pwm_pin_set_usec(pwm1_x_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1x_neg)),
					(20U * USEC_PER_MSEC), 0, 0);
	pwm_pin_set_usec(pwm1_y_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1y_pos)),
					(20U * USEC_PER_MSEC), 0, 0);
	pwm_pin_set_usec(pwm1_y_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm1y_neg)),
					(20U * USEC_PER_MSEC), 0, 0);
	pwm_pin_set_usec(pwm2_z_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2z_pos)),
					(20U * USEC_PER_MSEC), 0, 0);
	pwm_pin_set_usec(pwm2_z_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2z_neg)),
					(20U * USEC_PER_MSEC), 0, 0);
	pwm_pin_set_usec(pwm2_t_pos, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2t_pos)),
					(20U * USEC_PER_MSEC), 0, 0);
	pwm_pin_set_usec(pwm2_t_neg, DT_PWMS_CHANNEL(DT_NODELABEL(pwm2t_neg)),
					(20U * USEC_PER_MSEC), 0, 0);
}

void initialize_laser_driver(void)
{
	const struct device *laser_driver;
	const struct dac_channel_cfg dac_ch_cfg = {
		.channel_id  = 0,
		.resolution  = 10,
	};

	laser_driver = device_get_binding(DT_LABEL(DT_NODELABEL(laser_dac)));
	if (laser_driver == NULL) {
		return;
	}

	dac_channel_setup(laser_driver, &dac_ch_cfg);
}

void initialize_shell_port(void)
{
	const struct device *dev;
	uint32_t dtr = 0;

	dev = device_get_binding(CONFIG_UART_SHELL_ON_DEV_NAME);
	if (dev == NULL || usb_enable(NULL)) {
		return;
	}

	k_sleep(K_MSEC(100));
	uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
}

void main(void)
{
	const struct device *dev;
	uint32_t dtr = 0;

	initialize_limit_switches();
	initialize_shell_port();
	initialize_power_switch();
	initialize_motor_drives();
	initialize_laser_driver();

	dev = device_get_binding(CONFIG_UART_SHELL_ON_DEV_NAME);
	if (dev == NULL) {
		return;
	}

	while (!dtr) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		k_sleep(K_MSEC(100));
	}
}
