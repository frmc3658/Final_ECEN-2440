/*
 * scheduler.c
 *
 */

//***************************************************************
// include header
//**************************************************************/
#include "scheduler.h"


//***************************************************************
// static/private data
//**************************************************************/
static volatile uint32_t scheduled_events;


//***************************************************************
// static/private functions
//**************************************************************/


//***************************************************************
// function definitions
//**************************************************************/
void scheduler_open(void)
{
    // TODO: MAKE ATOMIC
    // clear scheduler
    scheduled_events = CLEAR_SCHEDULED_EVENTS;
}

void add_scheduled_event(uint32_t event)
{
    // TODO: MAKE ATOMIC
    scheduled_events |= event;
}

void remove_scheduled_event(uint32_t event)
{
    // TODO: MAKE ATMOIC
    scheduled_events &= ~event;
}


// return events_scheduled
uint32_t get_scheduled_events(void)
{
    // TODO: MAKE ATOMIC
    uint32_t events = scheduled_events;

    return events;
}
