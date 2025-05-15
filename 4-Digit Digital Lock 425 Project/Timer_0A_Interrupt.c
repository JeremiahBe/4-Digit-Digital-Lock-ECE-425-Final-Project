/**
 * @file Timer_0A_Interrupt.c
 *
 * @brief Source code for the Timer_0A_Interrupt driver.
 *
 * This file contains the function definitions for the Timer_0A_Interrupt driver.
 * It uses the Timer 0A module to generate periodic interrupts.
 *
 *
 * @author Jeremiah Bennett
 */

#include "Timer_0A_Interrupt.h"

// Declare pointer to the user-defined task
void (*Timer_0A_Task)(void);

void Timer_0A_Interrupt_Init(void(*task)(void))
{
	// Store the user-defined task function for use during interrupt handling
	Timer_0A_Task = task;
	
	SYSCTL->RCGCTIMER |=  0x01;
	
	TIMER0->CTL &= ~0x01;
	
	TIMER0->CFG |= 0x04;
	
	TIMER0->TAMR |= 0x02;
	
	TIMER0->TAPR &= ~0x000000FF;
	
	TIMER0->TAPR = 50;

	TIMER0->TAILR = (1000 - 1);
	
	TIMER0->ICR |= 0x01;
	
	TIMER0->IMR |= 0x01;
	
	NVIC->IPR[4] = (NVIC->IPR[4] & 0x00FFFFFF) | (1 << 29);
	
	NVIC->ISER[0] |= (1 << 19);
	
	TIMER0->CTL |= 0x01;
}

void TIMER0A_Handler(void)
{
	// Read the Timer 0A time-out interrupt flag
	if (TIMER0->MIS & 0x01)
	{
		// Execute the user-defined function
		(*Timer_0A_Task)();
		

		TIMER0->ICR |= 0x01;
	}
}
