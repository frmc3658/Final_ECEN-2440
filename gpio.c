/*
 * gpio.c
 *
 */

//***************************************************************
// include header
//**************************************************************/
#include "gpio.h"


//***************************************************************
// static/private data
//**************************************************************/


//***************************************************************
// static/private functions
//**************************************************************/


//***************************************************************
// function definitions
//**************************************************************/
// open the gpio peripheral
void gpio_open(void)
{
    config_timer_gpio();
    config_gpio_led();
}


// configure timer gpio
void config_timer_gpio(void)
{
    // set P2.4 as input to read signal from comparator
    P2->DIR &= ~BIT4;

    // selecting primary functionality on P2.4 for TA0.1 (TRM 12.4.8)
    P2->SEL0 |= BIT4;
    P2->SEL1 &= ~BIT4;

    // input with pullup resistor (TRM 12.2.4)
    P2->REN |= BIT4;
    P2->OUT |= BIT4;
}


// configure P2 LEDs gpio
void config_gpio_led(void)
{
    // Set as output
    P2->DIR |= RED;
    P2->DIR |= GREEN;
    P2->DIR |= BLUE;

    // set drive strength to high
    P2->DS |= RED;
    P2->DS |= GREEN;
    P2->DS |= BLUE;
}


// drive P2 LEDs high
void drive_leds(void)
{
    // drive P2.0, P2.1, and P2.3 high to turn on LEDs
    P2->OUT |= RED;
    P2->OUT |= BLUE;
    P2->OUT |= GREEN;
}


// turn off P2 LEDs
void turn_off_leds(void)
{
    P2->OUT &= ~RED;
    P2->OUT &= ~BLUE;
    P2->OUT &= ~GREEN;
}
