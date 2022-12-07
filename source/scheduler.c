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
/***************************************************************************//**
 * @brief
 *   Open the scheduler.
 *
 * @details
 *   Clears the scheduled_events variable.
 ******************************************************************************/
void scheduler_open(void)
{
    // clear scheduler
    MAKE_ATOMIC
    (
        scheduled_events = CLEAR_SCHEDULED_EVENTS;
    );
}


/***************************************************************************//**
 * @brief
 *   Add an event to the scheduler.
 *
 * @details
 *   Adds a callback event to the scheduler.
 *
 * @param[in] event
 *   Event to add to the scheduler.
 ******************************************************************************/
void add_scheduled_event(uint32_t event)
{
    MAKE_ATOMIC
    (
        scheduled_events |= event;
    );
}


/***************************************************************************//**
 * @brief
 *   Removes an event from the scheduler.
 *
 * @details
 *   Removes callback event from the scheduler.
 *
 * @param[in] event
 *   Event to be removed from the scheduler.
 ******************************************************************************/
void remove_scheduled_event(uint32_t event)
{
    MAKE_ATOMIC
    (
        scheduled_events &= ~event;
    );
}


/***************************************************************************//**
 * @brief
 *   Get the events from the scheduler.
 *
 * @return event
 *   Returns scheduled events.
 ******************************************************************************/
uint32_t get_scheduled_events(void)
{
    uint32_t events;

    MAKE_ATOMIC
    (
        events = scheduled_events;
    );

    return events;
}
