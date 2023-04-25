#ifndef NEC_IR_H
#define NEC_IR_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint8_t address;
    uint8_t command;
} nec_command_t;

/*
 * tbd
 */
extern bool nec_ir_cmd_event;

/*
 * tbd
 */
extern nec_command_t nec_ir_cmd;

/*
 * tbd
 */
void nec_ir_init(void);

/*
 * tbd
 */
void nec_ir_process(void);

#endif /* NEC_IR_H */
