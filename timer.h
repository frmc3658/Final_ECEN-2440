/*
 * timer.h
 *
 */

#ifndef TIMER_H_
#define TIMER_H_

//***************************************************************
// included files
//**************************************************************/
/* System includes */

/* Texas Instruments includes */
#include "msp.h"

/* Developer includes */
#include "gpio.h"
#include "scheduler.h"


//***************************************************************
// defined macros
//**************************************************************/
#define TICKS                   0xFFFF              // max value for 16-bit CCR[1]
#define TIMER_A0_CCI_HIGH_CB    0X8                 // callback value for CCI high
#define TIMER_A0_CCI_LOW_CB     0x4                 // callback value for CCI low


//***************************************************************
// enums
//**************************************************************/


//***************************************************************
// structs
//**************************************************************/


//***************************************************************
// function prototypes
//**************************************************************/
void timer_open(void);
void start_timer(void);
void stop_timer(void);
void config_timer(void);

#endif /* TIMER_H_ */
