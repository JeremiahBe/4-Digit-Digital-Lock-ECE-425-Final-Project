/*
 * @file Buzzer.c
 * @brief Source file for the Buzzer driver used in the Digital Lock System. 
 *        This module provides functions to generate sound feedback using a piezo buzzer 
 *        to indicate correct or incorrect code entry events.
 *
 * @note The buzzer is connected to a GPIO output pin 
 *
 * @author Jeremiah Bennett
 */

 
#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "Buzzer.h"

#define BUZZER_PIN (1U << 2)  // PB2

void Buzzer_Init(void)
{
    SYSCTL->RCGCGPIO |= 0x02;  // Enable clock for GPIOB
    while (!(SYSCTL->PRGPIO & 0x02)) {}

    GPIOB->DIR |= BUZZER_PIN;
    GPIOB->DEN |= BUZZER_PIN;
    GPIOB->DATA &= ~BUZZER_PIN;
}

void Buzzer_Beep(uint32_t duration_ms)
{
    GPIOB->DATA |= BUZZER_PIN;
    SysTick_Delay1ms(duration_ms);
    GPIOB->DATA &= ~BUZZER_PIN;
}