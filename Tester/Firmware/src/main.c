#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <drivers/uart.h>
#include <drivers/pwm.h>
#include <usb/usb_device.h>
#include <shell/shell.h>


enum activated_switch {positive_x, negative_x, positive_y, negative_y, positive_z, negative_z};
K_MSGQ_DEFINE(switch_msgq, sizeof(enum activated_switch), 10, 4);

static int cmd_demo(const struct shell *shell, size_t argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	shell_print(shell, "Demo command!");

	return 0;
}

static int cmd_switch(const struct shell *shell, size_t argc, char **argv)
{
	enum activated_switch current_switch;

	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	//k_msgq_get(&switch_msgq, &current_switch, K_FOREVER);

	while(k_msgq_get(&switch_msgq, &current_switch, K_NO_WAIT)) {
		k_msleep(100);
	}

	switch(current_switch) {
		case positive_x:
			shell_warn(shell, "+X Limit Switch reached");
			break;
		case negative_x:
			shell_warn(shell, "-X Limit Switch reached");
			break;
		case positive_y:
			shell_warn(shell, "+Y Limit Switch reached");
			break;
		case negative_y:
			shell_warn(shell, "-Y Limit Switch reached");
			break;
		case positive_z:
			shell_warn(shell, "+Z Limit Switch reached");
			break;
		case negative_z:
			shell_warn(shell, "-Z Limit Switch reached");
			break;
		default:
		return 0;
	}

	return 0;
}

SHELL_CMD_REGISTER(demo, NULL, "Demo command", cmd_demo);
SHELL_CMD_REGISTER(switches, NULL, "Report end switches state", cmd_switch);


static struct gpio_callback sw_px_cb_data, sw_nx_cb_data, sw_py_cb_data,
							sw_ny_cb_data, sw_pz_cb_data, sw_nz_cb_data;

void limit_switch_reached(const struct device *port, struct gpio_callback *cb, gpio_port_pins_t pins)
{
	enum activated_switch current_switch;
	
	ARG_UNUSED(port);
	ARG_UNUSED(cb);

	switch(pins) {
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_positive_x), gpios)):
			current_switch = positive_x;
			break;
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_negative_x), gpios)):
			current_switch = negative_x;
			break;
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_positive_y), gpios)):
			current_switch = positive_y;
			break;
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_negative_y), gpios)):
			current_switch = negative_y;
			break;
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_positive_z), gpios)):
			current_switch = positive_z;
			break;
		case BIT(DT_GPIO_PIN(DT_NODELABEL(switch_negative_z), gpios)):
			current_switch = negative_z;
			break;
		default:
			return;
	}
	
    while (k_msgq_put(&switch_msgq, &current_switch, K_NO_WAIT) != 0) {
		k_msgq_purge(&switch_msgq);
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
	const struct device *motor_driver, *motor_alert, *laser_driver, *laser_alert;
	int motor_driver_ret, motor_alert_ret, laser_driver_ret, laser_alert_ret;

	motor_driver = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(motor_drives_switch), gpios));
	motor_alert = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(motor_drives_alert), gpios));
	laser_driver = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(laser_drive_switch), gpios));
	laser_alert = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(laser_drive_alert), gpios));

	if ((motor_driver == NULL) || (motor_alert == NULL) || (laser_driver == NULL)
	|| (laser_alert == NULL)) {
		return;
	}

	motor_driver_ret = gpio_pin_configure(motor_driver,
									DT_GPIO_PIN(DT_NODELABEL(motor_drives_switch), gpios),
									GPIO_OUTPUT | DT_GPIO_FLAGS(DT_NODELABEL(motor_drives_switch), gpios));
	motor_alert_ret = gpio_pin_configure(motor_alert,
									DT_GPIO_PIN(DT_NODELABEL(motor_drives_alert), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(motor_drives_alert), gpios));
	laser_driver_ret = gpio_pin_configure(laser_driver,
									DT_GPIO_PIN(DT_NODELABEL(laser_drive_switch), gpios),
									GPIO_OUTPUT | DT_GPIO_FLAGS(DT_NODELABEL(laser_drive_switch), gpios));
	laser_alert_ret = gpio_pin_configure(laser_alert,
									DT_GPIO_PIN(DT_NODELABEL(laser_drive_alert), gpios),
									GPIO_INPUT | DT_GPIO_FLAGS(DT_NODELABEL(laser_drive_alert), gpios));

	if ((motor_driver_ret != 0) || (motor_alert_ret != 0) || (laser_driver_ret != 0)
	|| (laser_alert_ret != 0)) {
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

void motor_switch_control(bool activate)
{
	const struct device *motor_driver;
	int motor_driver_ret;

	motor_driver = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(motor_drives_switch), gpios));
	
	if (motor_driver == NULL) {
		return;
	}

	if (activate) {
		gpio_pin_set(motor_driver, DT_GPIO_PIN(DT_NODELABEL(motor_drives_switch), gpios), 1);
	} else {
		gpio_pin_set(motor_driver, DT_GPIO_PIN(DT_NODELABEL(motor_drives_switch), gpios), 0);
	}
}

void laser_switch_control(bool activate)
{
	const struct device *laser_driver;
	int laser_driver_ret;

	laser_driver = device_get_binding(DT_GPIO_LABEL(DT_NODELABEL(laser_drive_switch), gpios));
	
	if (laser_driver == NULL) {
		return;
	}

	if (activate) {
		gpio_pin_set(laser_driver, DT_GPIO_PIN(DT_NODELABEL(laser_drive_switch), gpios), 1);
	} else {
		gpio_pin_set(laser_driver, DT_GPIO_PIN(DT_NODELABEL(laser_drive_switch), gpios), 0);
	}
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


	const struct device *pwm1_a11, *pwm1_a12, *pwm1_b11, *pwm1_b12;
	const struct device *pwm2_a21, *pwm2_a22, *pwm2_b21, *pwm2_b22;
	int pwm1_a11_ret, pwm1_a12_ret, pwm1_b11_ret, pwm1_b12_ret;
	int pwm2_a21_ret, pwm2_a22_ret, pwm2_b21_ret, pwm2_b22_ret;

	pwm1_a11 = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm_1_a11))));
	pwm1_a12 = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm_1_a12))));
	pwm1_b11 = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm_1_b11))));
	pwm1_b12 = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm_1_b12))));
	pwm2_a21 = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm_2_a21))));
	pwm2_a22 = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm_2_a22))));
	pwm2_b21 = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm_2_b21))));
	pwm2_b22 = device_get_binding(DT_LABEL(DT_PWMS_CTLR(DT_NODELABEL(pwm_2_b22))));

	if ((pwm1_a11 == NULL) || (pwm1_a12 == NULL) || (pwm1_b11 == NULL) || (pwm1_b12 == NULL) ||
	(pwm2_a21 == NULL) || (pwm2_a22 == NULL) || (pwm2_b21 == NULL) || (pwm2_b22 == NULL)) {
		return;
	}

	pwm1_a11_ret = pwm_pin_set_usec(pwm1_a11, DT_PWMS_CHANNEL(DT_NODELABEL(pwm_1_a11)),
					(20U * USEC_PER_MSEC), (20U * USEC_PER_MSEC)/2, 0);
	pwm1_a12_ret = pwm_pin_set_usec(pwm1_a12, DT_PWMS_CHANNEL(DT_NODELABEL(pwm_1_a12)),
					(20U * USEC_PER_MSEC), 0, 0);
	
	if ((pwm1_a11_ret != 0)) {
		return;
	}	
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
	
	motor_switch_control(true);
	laser_switch_control(true);

	dev = device_get_binding(CONFIG_UART_SHELL_ON_DEV_NAME);
	if (dev == NULL) {
		return;
	}

	while (!dtr) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		k_sleep(K_MSEC(100));
	}
}
