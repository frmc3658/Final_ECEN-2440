/*
 * scheduler.h
 *
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

//***************************************************************
// included files
//**************************************************************/
/* System includes */
#include <atomic_op.h>
#include <stdint.h>

/* Texas Instruments includes */
#include "msp.h"

/* Developer includes */


//***************************************************************
// defined macros
//**************************************************************/
/* Event masks */
#define CLEAR_SCHEDULED_EVENTS 0x00     // default value of scheduled_events static variable
/* Callbacks */
#define TIMER_A0_CCI_HIGH_CB    0X8                 // callback value for CCI high
#define TIMER_A0_CCI_LOW_CB     0x4                 // callback value for CCI low
#define GPIO_EXTERNAL_LED_CB    0x2

//***************************************************************
// enums
//**************************************************************/


//***************************************************************
// structs
//**************************************************************/


//***************************************************************
// function prototypes
//**************************************************************/
void scheduler_open(void);
void add_scheduled_event(uint32_t event);
void remove_scheduled_event(uint32_t event);
uint32_t get_scheduled_events(void);

#endif /* SCHEDULER_H_ */
