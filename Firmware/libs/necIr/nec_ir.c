#include "../../hal/timer1_nec.h"

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    NEC_ZERO,
    NEC_ONE,
    NEC_START,
    NEC_START_WAIT,
    NEC_REPEAT,
    NEC_REPEAT_WAIT
} nec_symbol_t;

typedef enum
{
    NEC_WAIT_FOR_START,
    NEC_PROCESS_ADDR,
    NEC_PROCESS_ADDR_INV,
    NEC_PROCESS_CMD,
    NEC_PROCESS_CMD_INV
} nec_state_t;

/*
 * tbd
 */
static bool nec_ir_is_inside_range(uint32_t count, uint32_t base, uint32_t tolerance);

/*
 * tbd
 */
void nec_ir_init(void)
{
    timer1_nec_init();

    return;
}

/*
 * tbd
 */
static bool nec_ir_is_inside_range(uint32_t count, uint32_t base, uint32_t tolerance)
{
    if ((count >= (base - tolerance)) || (count <= (base + tolerance)))
        return true;

    return false;
}

/*
 * tbd
 */
void nec_ir_process(void)
{
    uint8_t bit_count, address, address_inv, command, command_inv;
    uint32_t capture;
    nec_symbol_t nec_symbol;
    static nec_state_t state = NEC_WAIT_FOR_START;

    /* Get a timer capture event, measure it, determine which symbol it is
    and process it */
    while (timer1_nec_get_capture(&capture) == 0)
    {
        switch (state)
        {
        case NEC_WAIT_FOR_START:
            if (nec_ir_is_inside_range(capture, NEC_START_BURST_TIME, NEC_HIGH_TOLERANCE))
            {
                state = NEC_PROCESS_ADDR;
                bit_count = 0;
            }
            break;

        case NEC_PROCESS_ADDR:
            if (nec_ir_is_inside_range(capture, NEC_ZERO_TIME, NEC_LOW_TOLERANCE))
            {
                state = NEC_PROCESS_ADDR;
            }
            else if(nec_ir_is_inside_range(capture, NEC_ONE_TIME, NEC_LOW_TOLERANCE))
            {

            }
            break;

        default:
            break;
        }
    }

    return;
}
