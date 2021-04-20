#define CMD_RESPONSE_THREAD_STACK_SIZE 256
#define CMD_RESPONSE_THREAD_PRIORITY 5
#define PARSER_QUEUE_STACK_SIZE 256
#define PARSER_QUEUE_PRIORITY 5


void command_parser_init(void);
void command_tokenizer(struct k_work *work_item);
void command_parser(uint8_t *command, uint8_t length);
void generate_response(void *unused0, void *unused1, void *unused2);
