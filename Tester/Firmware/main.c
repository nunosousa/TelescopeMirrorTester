#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
    DDRD = 255; // MAKE ALL PORT D PINS OUTPUTS
    
    while(1) {
        PORTD = 255;_delay_ms(100); // LED ON
        PORTD = 0;  _delay_ms(100); // LED OFF
        }
    
    return 0;
}