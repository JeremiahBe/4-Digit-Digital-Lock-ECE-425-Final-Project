/*
 * @file SysTick_Delay.c
 * @brief Source file for delay functions using the SysTick timer. 
 *        Provides millisecond and microsecond delays for time-dependent 
 *        operations in the Digital Lock System.
 *
 * @note This driver assumes that the system clock's frequency is 50 MHz.
 * @note Uses the built-in SysTick timer to generate accurate delays.
 *
 * @author Jeremiah Bennett
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"

void SysTick_Delay_Init(void)
{
    SysTick->CTRL = 0;              // Disable SysTick
    SysTick->LOAD = 0x00FFFFFF;     // Max reload value
    SysTick->VAL = 0;               // Clear current value
    SysTick->CTRL = 0x05;           // Enable with core clock
}

void SysTick_Delay1ms(uint32_t delay)
{
    for (uint32_t i = 0; i < delay; i++)
    {
        SysTick->LOAD = 16300 - 1; // 16 MHz clock = 1 ms
        SysTick->VAL = 0;
        while ((SysTick->CTRL & 0x10000) == 0) {}
    }
}

void SysTick_Delay1us(uint32_t delay)
{
    for (uint32_t i = 0; i < delay; i++)
    {
        SysTick->LOAD = 20 - 1; // 16 MHz clock = 1 us
        SysTick->VAL = 0;
        while ((SysTick->CTRL & 0x10000) == 0) {}
    }
}