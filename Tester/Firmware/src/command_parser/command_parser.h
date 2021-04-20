#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <zephyr.h>

#define CMD_RESPONSE_THREAD_STACK_SIZE 256
#define CMD_RESPONSE_THREAD_PRIORITY 5
#define PARSER_QUEUE_STACK_SIZE 256
#define PARSER_QUEUE_PRIORITY 5
#define MAX_CMD_SIZE 16
#define RX_CMD_RING_BUF_SIZE 16
#define TX_CMD_RING_BUF_SIZE 64


void command_parser_init(void);
void command_tokenizer(struct k_work *);
void command_parser(uint8_t *command, uint8_t length);
void generate_response(void *unused0, void *unused1, void *unused2);

#endif /* COMMAND_PARSER_H */