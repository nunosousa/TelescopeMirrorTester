#include <stdio.h>
#include <string.h>
#include <device.h>
#include <drivers/uart.h>
#include <zephyr.h>
#include <sys/ring_buffer.h>
#include <usb/usb_device.h>
#include <logging/log.h>

#include "command_parser.h"

LOG_MODULE_REGISTER(cdc_acm_echo, LOG_LEVEL_INF);

#define RING_BUF_SIZE 1024
uint8_t ring_buffer[RING_BUF_SIZE];
struct ring_buf ringbuf;

// Define Command Parser Work Queue auxiliary data structures
K_THREAD_STACK_DEFINE(parser_queue_stack, PARSER_QUEUE_STACK_SIZE);
struct k_work_q parser_queue;
struct k_work rx_work_item;
#define RX_CMD_RING_BUF_SIZE 64
RING_BUF_DECLARE(rx_cmd_ring_buffer, RX_CMD_RING_BUF_SIZE);

// Define Command response auxiliary data strctures
K_THREAD_STACK_DEFINE(cmd_response_thread_stack, CMD_RESPONSE_THREAD_STACK_SIZE);
static struct k_thread cmd_response_thread;
static k_tid_t cmd_response_tid;

static void interrupt_handler(const struct device *dev, void *user_data)
{
	ARG_UNUSED(user_data);

	while (uart_irq_update(dev) && uart_irq_is_pending(dev)) {
		if (uart_irq_rx_ready(dev)) {
			uint32_t rb_len, recv_len, err;
			uint8_t *data;
			
			/* Allocate buffer within a ring buffer memory. */
			rb_len = ring_buf_put_claim(&rx_cmd_ring_buffer, &data, RX_CMD_RING_BUF_SIZE);

			/* Work directly on a ring buffer memory. */
			recv_len = uart_fifo_read(dev, data, rb_len);

			/* Indicate amount of valid data. rx_size can be equal or less than size. */
			err = ring_buf_put_finish(&rx_cmd_ring_buffer, recv_len);
			if (err == 0) {
				k_work_submit(&rx_work_item);
			}
		}

		if (uart_irq_tx_ready(dev)) {
			uint8_t buffer[64];
			int rb_len, send_len;

			rb_len = ring_buf_get(&ringbuf, buffer, sizeof(buffer));
			if (!rb_len) {
				LOG_DBG("Ring buffer empty, disable TX IRQ");
				uart_irq_tx_disable(dev);
				continue;
			}

			send_len = uart_fifo_fill(dev, buffer, rb_len);
			if (send_len < rb_len) {
				LOG_ERR("Drop %d bytes", rb_len - send_len);
			}

			LOG_DBG("ringbuf -> tty fifo %d bytes", send_len);
		}
	}
}

void command_parser(struct k_work *new_work)
{
	const struct device *dev;
	struct command_data *new_command;

	dev = device_get_binding("CDC_ACM_0");

	while(1)
	{
		break;
	}
}

void generate_response(void *unused0, void *unused1, void *unused2)
{
	while(1)
	{
		//ring_buf_put(&ringbuf, "aaaaa\n", 6);
		
		//uart_irq_tx_enable(dev);
		//k_thread_suspend();
	}
}

void command_parser_init(void)
{
	const struct device *dev;
	uint32_t baudrate, dtr = 0U;
	int ret;

	dev = device_get_binding("CDC_ACM_0");
	if (!dev) {
		LOG_ERR("CDC ACM device not found");
		return;
	}

	ret = usb_enable(NULL);
	if (ret != 0) {
		LOG_ERR("Failed to enable USB");
		return;
	}

	ring_buf_init(&ringbuf, sizeof(ring_buffer), ring_buffer);

	LOG_INF("Wait for DTR");

	while (true) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		if (dtr) {
			break;
		} else {
			/* Give CPU resources to low priority threads. */
			k_sleep(K_MSEC(100));
		}
	}

	LOG_INF("DTR set");

	/* They are optional, we use them to test the interrupt endpoint */
	ret = uart_line_ctrl_set(dev, UART_LINE_CTRL_DCD, 1);
	if (ret) {
		LOG_WRN("Failed to set DCD, ret code %d", ret);
	}

	ret = uart_line_ctrl_set(dev, UART_LINE_CTRL_DSR, 1);
	if (ret) {
		LOG_WRN("Failed to set DSR, ret code %d", ret);
	}

	/* Wait 1 sec for the host to do all settings */
	k_busy_wait(1000000);

	ret = uart_line_ctrl_get(dev, UART_LINE_CTRL_BAUD_RATE, &baudrate);
	if (ret) {
		LOG_WRN("Failed to get baudrate, ret code %d", ret);
	} else {
		LOG_INF("Baudrate detected: %d", baudrate);
	}

	uart_irq_callback_set(dev, interrupt_handler);

	/* Enable rx interrupts */
	uart_irq_rx_enable(dev);

	/* Start Work Queues */
	k_work_queue_start(&parser_queue, parser_queue_stack,
						K_THREAD_STACK_SIZEOF(parser_queue_stack),
						PARSER_QUEUE_PRIORITY, NULL);
	k_work_init(&rx_work_item, command_parser);

	/* Start Threads */
	cmd_response_tid = k_thread_create(&cmd_response_thread,
						cmd_response_thread_stack,
						K_THREAD_STACK_SIZEOF(cmd_response_thread_stack),
						generate_response,
						NULL, NULL, NULL,
						CMD_RESPONSE_THREAD_PRIORITY, 0, K_NO_WAIT);
}
