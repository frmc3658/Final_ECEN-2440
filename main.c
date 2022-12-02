/**
 * main.c
 *
 */

//***************************************************************
// include header
//**************************************************************/
#include "main.h"


void main(void)
{
    // stop watchdog timer
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

	// open application specific peripherals
	app_peripheral_open();

	// infinite while loop
	while(1)
	{
	    // if timer CCI high callback event has been scheduled ...
	    if(TIMER_A0_CCI_HIGH_CB & get_scheduled_events())
	    {
	        // remove events
	        remove_scheduled_event(TIMER_A0_CCI_HIGH_CB);
            remove_scheduled_event(GPIO_EXTERNAL_LED_CB);

	        // turn off LEDs
	        turn_off_leds();
	    }

	    // if timer CCI low callback event has been scheduled ...
	    if(TIMER_A0_CCI_LOW_CB & get_scheduled_events())
	    {
	        // remove event
	        remove_scheduled_event(TIMER_A0_CCI_LOW_CB);

	        // drive LEDs high
	        drive_leds();
	    }

	    //
	    if(GPIO_EXTERNAL_LED_CB & get_scheduled_events())
	    {
	        //
	    }
	}
}
