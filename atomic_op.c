/*
 * atomic_op.c
 *
 */

//***************************************************************
// include header
//**************************************************************/
#include "atomic_op.h"

//***************************************************************
// static/private data
//**************************************************************/


//***************************************************************
// static/private functions
//**************************************************************/


//***************************************************************
// function definitions
//**************************************************************/
// stores the state of the PRIMASK and disables
// interrupts to enter an atomic operations
uint32_t enter_atomic(void)
{
    uint32_t irqState = __get_interrupt_state();
    __disable_interrupts();
    return irqState;
}

// re-enables interrupts to exit an atomic operation
void exit_atomic(uint32_t irqState)
{
    if(!irqState)
    {
        __enable_interrupts();
    }
}
