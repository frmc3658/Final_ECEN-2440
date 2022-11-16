/*
 * brd_config.h
 *
 */

#ifndef ATOMIC_OP_H_
#define ATOMIC_OP_H_

//***************************************************************
// included files
//**************************************************************/
/* System includes */
#include <stdint.h>

/* Texas Instruments includes */

/* Developer includes */
#include "msp.h"

//***************************************************************
// defined macros
//**************************************************************/
/* Macros for atomic operations */
#define DECLARE_ATOMIC_IRQ_STATE        uint32_t irqState
/* ASSUMES DECLARE_ATOMIC_IRQ_STATE FIRST */
#define ENTER_ATOMIC()                  irqState = enter_atomic()
#define EXIT_ATOMIC()                   exit_atomic(irqState)


/* pre-processor directive to convientiently create atomic operations */
#define MAKE_ATOMIC(operation)      \
    {                               \
        DECLARE_ATOMIC_IRQ_STATE;   \
        ENTER_ATOMIC();             \
        {                           \
            operation               \
        }                           \
        EXIT_ATOMIC();              \
    }                               \


//***************************************************************
// enums
//**************************************************************/


//***************************************************************
// structs
//**************************************************************/


//***************************************************************
// function prototypes
//**************************************************************/
uint32_t enter_atomic(void);
void exit_atomic(uint32_t irqState);

#endif /* ATOMIC_OP_H_ */
