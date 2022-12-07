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
/***************************************************************************//**
 * @brief
 *   Enter atomic operation.
 *
 * @details
 *   Stores the PRIMASK state in order to suspend interrupts until
 *   exit_atomic() is called.
 *
 * @return irqState
 *   Returns the state of the PRIMASK for use as a function argument
 *   with exit_atomic().
 ******************************************************************************/
uint32_t enter_atomic(void)
{
    uint32_t irqState = __get_interrupt_state();
    __disable_interrupts();
    return irqState;
}


/***************************************************************************//**
 * @brief
 *   Exit atomic operation.
 *
 * @details
 *   If the irqState was previously enabled, re-enable interrupts.
 *
 * @param[in] irqState
 *   Stored state of PRIMASK prior to entering an atomic operation.
 ******************************************************************************/
void exit_atomic(uint32_t irqState)
{
    if(!irqState)
    {
        __enable_interrupts();
    }
}
