#include "nec_ir.h"
#include "../../hal/timer1_nec.h"

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    NEC_WAIT_FOR_START,
    NEC_PROCESS_ADDR,
    NEC_PROCESS_ADDR_INV,
    NEC_PROCESS_CMD,
    NEC_PROCESS_CMD_INV,
    NEC_CMD_END
} nec_state_t;

/*
 * tbd
 */
bool nec_ir_cmd_event = false;

/*
 * tbd
 */
nec_command_t nec_ir_cmd = {0, 0};

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
    uint8_t bit_position = 0;
    uint8_t address = 0, address_inv = 0, command = 0, command_inv = 0;
    uint32_t capture;
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
                bit_position = 0;
                address = 0;
                address_inv = 0;
                command = 0;
                command_inv = 0;
            }

            break;

        case NEC_PROCESS_ADDR:
            if (nec_ir_is_inside_range(capture, NEC_ZERO_TIME, NEC_LOW_TOLERANCE))
            {
                bit_position++;
            }
            else if (nec_ir_is_inside_range(capture, NEC_ONE_TIME, NEC_LOW_TOLERANCE))
            {
                address |= (1 << bit_position);
                bit_position++;
            }
            else
            {
                state = NEC_WAIT_FOR_START;
                break;
            }

            if (bit_position >= 8)
            {
                state = NEC_PROCESS_ADDR_INV;
                bit_position = 0;
            }

            break;

        case NEC_PROCESS_ADDR_INV:
            if (nec_ir_is_inside_range(capture, NEC_ZERO_TIME, NEC_LOW_TOLERANCE))
            {
                bit_position++;
            }
            else if (nec_ir_is_inside_range(capture, NEC_ONE_TIME, NEC_LOW_TOLERANCE))
            {
                address_inv |= (1 << bit_position);
                bit_position++;
            }
            else
            {
                state = NEC_WAIT_FOR_START;
                break;
            }

            if (bit_position >= 8)
            {
                state = NEC_PROCESS_CMD;
                bit_position = 0;
            }

            break;

        case NEC_PROCESS_CMD:
            if (nec_ir_is_inside_range(capture, NEC_ZERO_TIME, NEC_LOW_TOLERANCE))
            {
                bit_position++;
            }
            else if (nec_ir_is_inside_range(capture, NEC_ONE_TIME, NEC_LOW_TOLERANCE))
            {
                command |= (1 << bit_position);
                bit_position++;
            }
            else
            {
                state = NEC_WAIT_FOR_START;
                break;
            }

            if (bit_position >= 8)
            {
                state = NEC_PROCESS_CMD_INV;
                bit_position = 0;
            }

            break;

        case NEC_PROCESS_CMD_INV:
            if (nec_ir_is_inside_range(capture, NEC_ZERO_TIME, NEC_LOW_TOLERANCE))
            {
                bit_position++;
            }
            else if (nec_ir_is_inside_range(capture, NEC_ONE_TIME, NEC_LOW_TOLERANCE))
            {
                command_inv |= (1 << bit_position);
                bit_position++;
            }
            else
            {
                state = NEC_WAIT_FOR_START;
                break;
            }

            if (bit_position >= 8)
            {
                state = NEC_CMD_END;
                bit_position = 0;
                address_inv = ~address_inv;
                command_inv = ~command_inv;
                if ((address == address_inv) && (command == command_inv))
                {
                    nec_ir_cmd_event = true;
                    nec_ir_cmd.address = address;
                    nec_ir_cmd.command = command;
                }
            }

            break;

        case NEC_CMD_END:
            if (nec_ir_is_inside_range(capture, NEC_START_WAIT_TIME, NEC_HIGH_TOLERANCE))
            {
                state = NEC_PROCESS_ADDR;
                bit_position = 0;
                address = 0;
                address_inv = 0;
                command = 0;
                command_inv = 0;
            }
            else
                state = NEC_WAIT_FOR_START;

            break;

        default:
            break;
        }
    }

    return;
}
