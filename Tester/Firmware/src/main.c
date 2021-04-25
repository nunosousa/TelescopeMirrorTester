#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <drivers/uart.h>
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

void initialize_gpios(void)
{
	const struct device *sw_px, *sw_nx, *sw_py, *sw_ny, *sw_pz, *sw_nz;
	int sw_px_ret, sw_nx_ret, sw_py_ret, sw_ny_ret, sw_pz_ret, sw_nz_ret;

	sw_px = device_get_binding(DT_LABEL(DT_NODELABEL(switch_positive_x)));
	sw_nx = device_get_binding(DT_LABEL(DT_NODELABEL(switch_negative_x)));
	sw_py = device_get_binding(DT_LABEL(DT_NODELABEL(switch_positive_y)));
	sw_ny = device_get_binding(DT_LABEL(DT_NODELABEL(switch_negative_y)));
	sw_pz = device_get_binding(DT_LABEL(DT_NODELABEL(switch_positive_z)));
	sw_nz = device_get_binding(DT_LABEL(DT_NODELABEL(switch_negative_z)));

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

void initialize_shell_port(void)
{
	const struct device *dev;
	uint32_t dtr = 0;

	dev = device_get_binding(CONFIG_UART_SHELL_ON_DEV_NAME);
	if (dev == NULL || usb_enable(NULL)) {
		return;
	}

	while (!dtr) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		k_sleep(K_MSEC(100));
	}
}

void main(void)
{
	initialize_gpios();
	initialize_shell_port(); // This function will stay in a infinite loop
}
