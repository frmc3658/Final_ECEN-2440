/*
 * gpio.h
 *
 */

#ifndef GPIO_H_
#define GPIO_H_

//***************************************************************
// included files
//**************************************************************/
/* System includes */

/* Texas Instruments includes */
#include "msp.h"

/* Developer includes */

//***************************************************************
// defined macros
//**************************************************************/
/* GPIO pins [P2] */
#define OB_RED          BIT0
#define OB_GREEN        BIT1
#define OB_BLUE         BIT2
#define EX_RED          BIT7;
#define EX_WHITE        BIT5;
/* GPIO pins [P3] */
#define EX_BLUE         BIT0;

/* GPIO Callbacks */


//***************************************************************
// enums
//**************************************************************/


//***************************************************************
// structs
//**************************************************************/


//***************************************************************
// function prototypes
//**************************************************************/
void gpio_open(void);
void config_timer_gpio(void);
void config_gpio_led(void);

#endif /* GPIO_H_ */
