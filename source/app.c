/*
 * app.c
 *
 */

//***************************************************************
// include header
//**************************************************************/
#include "app.h"


//***************************************************************
// static/private data
//**************************************************************/


//***************************************************************
// static/private functions
//**************************************************************/


//***************************************************************
// function definitions
//**************************************************************/
// open application specific peripherals
void app_peripheral_open(void)
{
    gpio_open();
    timer_open();
    scheduler_open();
}

// drive P2 LEDs high
void drive_leds(void)
{
    // drive LEDs high
    P2->OUT |= OB_RED;
    P2->OUT |= OB_GREEN;
    P2->OUT |= OB_BLUE;

    /* TODO: MAKE FUNCTION
     * TODO: USE HW DELAY */
    // dance party
    P2->OUT ^= EX_RED;
    delay(25000);
    P2->OUT ^= EX_WHITE;
    delay(25000);
    P3->OUT ^= EX_BLUE;
    delay(25000);
}


// turn off P2 LEDs
void turn_off_leds(void)
{
    // drive LEDs low
    P2->OUT &= ~OB_RED;
    P2->OUT &= ~OB_GREEN;
    P2->OUT &= ~OB_BLUE;
    P2->OUT &= ~EX_RED;
    P2->OUT &= ~EX_WHITE;
    P3->OUT &= ~EX_BLUE;
}
