/*
 * timer.c
 *
 */

//***************************************************************
// include header
//**************************************************************/
#include "timer.h"


//***************************************************************
// static/private data
//**************************************************************/


//***************************************************************
// static/private functions
//**************************************************************/


//***************************************************************
// function definitions
//**************************************************************/
void timer_open(void)
{
    // disable NVIC for TA0.1
    __NVIC_DisableIRQ(TA0_N_IRQn);

    // stop TA0 before modifying operation (TRM 19.2.1)
    stop_timer();

    // configure TA0
    config_timer();

    // start TA0
    start_timer();

    // enable NVIC for TA0.1
    __NVIC_GetEnableIRQ(TA0_N_IRQn);
}

// start timer peripheral
void start_timer(void)
{
    // set TA0 mode control: continuous mode
    TIMER_A0->CTL |= TIMER_A_CTL_MC__CONTINUOUS;
}


// stop timer peripheral
void stop_timer(void)
{
    // set MC to halt/stop mode
    TIMER_A0->CTL = TIMER_A_CTL_MC__STOP;
}


// configure timer peripheral
void config_timer(void)
{
    // clear R register
    TIMER_A0->CTL |= TIMER_A_CTL_CLR;

    // select SMCLK as source
    TIMER_A0->CTL |= TIMER_A_CTL_SSEL__SMCLK;

    // set input divider; 2^1
    TIMER_A0->CTL |= TIMER_A_CTL_ID__1;

    // set capture/compare input select for CCIA
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_CCIS__CCIA;

    // synchronize capture source
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_SCS;

    // set capture mode
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_CAP;

    // set capture mode for falling and rising edge (TRM 19.3.3)
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_CM__BOTH;

    // enable capture/compare interrupts
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_CCIE;

    // lower capture/compare interrupt flag
    TIMER_A0->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;

    // enable timer interrupts
    TIMER_A0->CTL |= TIMER_A_CTL_IE;
}


//***************************************************************
// interrupt handlers
//**************************************************************/
void TA0_N_IRQHandler(void)
{
    // lower timer and capture/compare interrupt flags
    TIMER_A0->CTL &= ~TIMER_A_CTL_IFG;
    TIMER_A0->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;

    // save capture/compare and counter states
    uint16_t cctl_state = TIMER_A0->CCTL[1];
    uint16_t cctl_r = TIMER_A0->R;

    // if CCI is HIGH ...
    if(cctl_state & TIMER_A_CCTLN_CCI)
    {
        add_scheduled_event(TIMER_A0_CCI_HIGH_CB);
    }
    else
    {
        add_scheduled_event(TIMER_A0_CCI_LOW_CB)
    }

    // restore counter and CCTL state
    TIMER_A0->CCTL[1] = cctl_state;
    TIMER_A0->R = cctl_r;
}
