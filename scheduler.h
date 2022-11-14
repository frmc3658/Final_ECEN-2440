/*
 * scheduler.h
 *
 *  Created on: Nov 9, 2022
 *      Author: fjmcd
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#define CLEAR_SCHEDULED_EVENTS 0x00

void scheduler_open(void);
void add_scheduled_event(uint32_t event);
void remove_scheduled_event(uint32_t event);
uint32_t get_scheduled_events(void);

#endif /* SCHEDULER_H_ */
