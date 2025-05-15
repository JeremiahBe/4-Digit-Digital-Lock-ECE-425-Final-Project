/**
 * @file Timer_0A_Interrupt.h
 *
 * @brief Header file for the Timer_0A_Interrupt driver.
 *
 * @author Jeremiah Bennett
 */
 
#include "TM4C123GH6PM.h"

// Declare pointer to the user-defined task
extern void (*Timer_0A_Task)(void);


void Timer_0A_Interrupt_Init(void(*task)(void));


void TIMER0A_Handler(void);
