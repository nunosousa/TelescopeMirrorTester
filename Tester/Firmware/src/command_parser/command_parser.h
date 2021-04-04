#define PARSER_QUEUE_STACK_SIZE 256
#define PARSER_QUEUE_PRIORITY 5
#define MAX_COMMAND_SIZE 16

void command_parser_init(void);
void command_parser(struct k_work *work_item);
void generate_response(void);

