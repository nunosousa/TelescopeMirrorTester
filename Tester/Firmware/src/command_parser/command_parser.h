#define PARSER_THREAD_STACK_SIZE 1024
#define PARSER_THREAD_PRIORITY 5

void command_parser_init(void);
void command_parser(void *unused0, void *unused1, void *unused2);
void generate_response(void);

