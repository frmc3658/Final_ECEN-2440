/**
 * main.c
 */

#include "msp.h"


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer


	while(1)
	{

	}
}
