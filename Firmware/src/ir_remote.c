#include "ir_remote.h"

#include "../libs/necIr/nec_ir.h"
#include "../libs/indicatorLED/indicator_led.h"

#include <stdio.h>

/*
 * tbd.
 */
void ir_remote_process(void)
{
    nec_command_t *remote_code;

    remote_code = nec_ir_get_command();

    if (remote_code == NULL)
        return;

    indicator_led_set_state(REMOTE, LED_ON);

    printf("%d, %d \n", remote_code->address, remote_code->command);

    indicator_led_set_state(REMOTE, LED_OFF);
}
