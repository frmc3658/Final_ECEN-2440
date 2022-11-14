/*
 * gpio.h
 *
 *  Created on: Nov 9, 2022
 *      Author: fjmcd
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "msp.h"

// GPIO pins [P2]
#define RED         0x00
#define GREEN       0x01
#define BLUE        0x02

void gpio_open(void);
void config_gpio(void);
void config_gpio_led(void);

#endif /* GPIO_H_ */
