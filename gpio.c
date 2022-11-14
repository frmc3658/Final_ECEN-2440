/*
 * gpio.c
 *
 *  Created on: Nov 9, 2022
 *      Author: fjmcd
 */


#include "gpio.h"
#include ""

void gpio_open(void)
{

}

void config_gpio(void)
{

}

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
