#include <zephyr.h>
#include <usb/usb_device.h>
#include <drivers/uart.h>
#include <shell/shell.h>


static int cmd_demo(const struct shell *shell, size_t argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	shell_print(shell, "Demo command!");

	return 0;
}

SHELL_CMD_REGISTER(demo, NULL, "Demo command", cmd_demo);

void main(void)
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
