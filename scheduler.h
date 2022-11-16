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
#include <stdint.h>

/* Texas Instruments includes */

/* Developer includes */


//***************************************************************
// defined macros
//**************************************************************/
#define CLEAR_SCHEDULED_EVENTS 0x00     // default value of scheduled_events static variable


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
