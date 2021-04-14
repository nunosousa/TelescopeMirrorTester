#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <device.h>
#include <drivers/uart.h>
#include <zephyr.h>
#include <sys/ring_buffer.h>
#include <usb/usb_device.h>
#include <logging/log.h>

#include "command_parser.h"

LOG_MODULE_REGISTER(cdc_acm_echo, LOG_LEVEL_INF);

// Define Command Parser Work Queue auxiliary data structures
K_THREAD_STACK_DEFINE(parser_queue_stack, PARSER_QUEUE_STACK_SIZE);
struct k_work_q parser_queue;
struct k_work rx_work_item;

#define MAX_CMD_SIZE 16
#define RX_CMD_RING_BUF_SIZE 16
#define TX_CMD_RING_BUF_SIZE 64
RING_BUF_DECLARE(rx_cmd_ring_buffer, RX_CMD_RING_BUF_SIZE);
RING_BUF_DECLARE(tx_cmd_ring_buffer, TX_CMD_RING_BUF_SIZE);

// Define Command response auxiliary data strctures
K_THREAD_STACK_DEFINE(cmd_response_thread_stack, CMD_RESPONSE_THREAD_STACK_SIZE);
static struct k_thread cmd_response_thread;
static k_tid_t cmd_response_tid;

static void interrupt_handler(const struct device *dev, void *user_data)
{
	ARG_UNUSED(user_data);

	while (uart_irq_update(dev) && uart_irq_is_pending(dev)) {
		if (uart_irq_rx_ready(dev)) {
			uint8_t *data;
			uint32_t rb_len, recv_len, err;
			
			/* Allocate buffer within a ring buffer memory. */
			rb_len = ring_buf_put_claim(&rx_cmd_ring_buffer, &data, RX_CMD_RING_BUF_SIZE);

			/* Work directly on a ring buffer memory. */
			recv_len = uart_fifo_read(dev, data, rb_len);

			/* Indicate amount of valid data. rx_size can be equal or less than size. */
			err = ring_buf_put_finish(&rx_cmd_ring_buffer, recv_len);
			if ((err == 0) && (recv_len > 0)) {
				k_work_submit(&rx_work_item);
			}

			/* Generate echo for the received characters */
			err = ring_buf_put(&tx_cmd_ring_buffer, data, recv_len);
			if ((err > 0) && (recv_len > 0)) {
				uart_irq_tx_enable(dev);
			}
		}

		if (uart_irq_tx_ready(dev)) {
			uint8_t *data;
			uint32_t rb_len, send_len;

			/* Get buffer within a ring buffer memory. */
			rb_len = ring_buf_get_claim(&tx_cmd_ring_buffer, &data, TX_CMD_RING_BUF_SIZE);
			if (!rb_len) {
				uart_irq_tx_disable(dev);
				continue;
			}

			/* Work directly on a ring buffer memory. */
			send_len = uart_fifo_fill(dev, data, rb_len);
			
			/* Indicate amount of data that can be freed. */
			ring_buf_get_finish(&tx_cmd_ring_buffer, send_len);
		}
	}
}

void command_tokenizer(struct k_work *new_work)
{
	uint8_t data, new_cmd;
	static uint8_t count = 0;
	static uint8_t command[MAX_CMD_SIZE];

	while(1)
	{
		while(ring_buf_get(&rx_cmd_ring_buffer, &data, 1) == 1)
		{
			command[count] = data;

			if(count < (MAX_CMD_SIZE-1))
			{
				++count;
			}

			if(data == '\r')
			{
				command_parser(command, count);
				count = 0;
				break;
			}
		}
	}
}

void command_parser(uint8_t *command, uint8_t length)
{
	uint8_t terminated_cmd[MAX_CMD_SIZE+1], cmd_value;

	// Serial commands
	// PWM1-99, PWM1+99
	// PWM2-99, PWM1+99
	// PWM3-99, PWM1+99
	// PWM4-99, PWM1+99
	// LSR100, LSR199
	// OPT10, OPT11
	// OPT20, OPT21

	if(length <= MAX_CMD_SIZE)
	{
		memcpy(terminated_cmd, command, length);
		terminated_cmd[length] = '\0';
	}
	else
	{
		return;
	}

	if((length == 7) && (!memcmp(command, "PMW", 3)))
	{
		switch(command[3])
		{
			case '1':
				cmd_value = atoi(command[4]);
				/* set PWM 1 to value */
				break;
			case '2':
				cmd_value = atoi(command[4]);
				/* set PWM 2 to value */
				break;
			case '3':
				cmd_value = atoi(command[4]);
				/* set PWM 3 to value */
				break;
			case '4':
				cmd_value = atoi(command[4]);
				/* set PWM 4 to value */
				break;
			default:
				return;
		}
	}
	else if((length == 6) && (!memcmp(command, "LSR", 3)))
	{
		switch(command[3])
		{
			case '1':
				cmd_value = atoi(command[4]);
				/* set LASER 1 to value */
				break;
			default:
				return;
		}
	}
	else if((length == 6) && (!memcmp(command, "OPT", 3)))
	{
		/* code */
	}

	return;
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
