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
/***************************************************************************//**
 * @brief
 *   Open the GPIO peripherals.
 *
 * @details
 *   Configures LEDs and TIMER_A0.
 ******************************************************************************/
void gpio_open(void)
{
    config_gpio_led();
    config_timer_gpio();
}


/***************************************************************************//**
 * @brief
 *   Configure TIMER_A0 GPIO.
 *
 * @details
 *   Configure P2.4 for primary functionality (TIMER_A0) and configure
 *   pullup resistor.
 ******************************************************************************/
void config_timer_gpio(void)
{
    // selecting primary functionality on P2.4 for TA0.1 (TRM 12.4.8)
    P2->SEL0 |= BIT4;
    P2->SEL1 &= ~BIT4;

    // input with pullup resistor (TRM 12.2.4)
    // set P2.4 as input to read signal from comparator
    P2->DIR &= ~BIT4;
    P2->REN |= BIT4;
    P2->OUT |= BIT4;
}


/***************************************************************************//**
 * @brief
 *   Configure onboard and external LEDs.
 *
 * @details
 *   Sets LEDs as output; selects GPIO functionality for P2.5, P2.7, & P3.0;
 *   and sets drive strength to high.
 ******************************************************************************/
void config_gpio_led(void)
{
    // EXTERNAL LEDS
    // set as output
    P2->DIR |= OB_RED;
    P2->DIR |= OB_GREEN;
    P2->DIR |= OB_BLUE;
    P2->DIR |= EX_RED;
    P2->DIR |= EX_WHITE;
    P3->DIR |= EX_BLUE;

    // select GPIO functionality for P2.5
    P2->SEL0 &= ~EX_RED;
    P2->SEL1 &= ~EX_RED;

    // select GPIO functionality P2.7
    P2->SEL0 &= ~EX_WHITE;
    P2->SEL1 &= ~EX_WHITE;

    // select GPIO functionality P3.0
    P3->SEL0 &= ~EX_BLUE;
    P3->SEL1 &= ~EX_BLUE;

    // set drive strength to high
    P2->DS |= EX_RED;
    P2->DS |= EX_WHITE;
    P3->DS |= EX_BLUE;
}
