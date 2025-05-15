/*
 * @file Indicators.c
 * @brief Source file for controlling visual indicators (LEDs) in the Digital Lock System. 
 *        Provides functions to turn on/off red and green LEDs to indicate 
 *        passcode status to the user.
 *
 * @note LEDs are connected to GPIO pins (e.g., PB0 for green, PB1 for red).
 * @note Green LED signals a correct code entry, while red LED signals an incorrect entry.
 * @note Includes functions to activate, deactivate, and reset both LEDs as needed.
 *
 * @author Jeremiah Bennett
 */

#include "TM4C123GH6PM.h"
#include "Indicators.h"

#define GREEN_LED_PIN (1U << 0) // PB0
#define RED_LED_PIN   (1U << 1) // PB1

void Indicators_Init(void)
{
    SYSCTL->RCGCGPIO |= 0x02; // Enable clock for GPIOB
    while (!(SYSCTL->PRGPIO & 0x02)) {}

    GPIOB->DIR |= GREEN_LED_PIN | RED_LED_PIN;
    GPIOB->DEN |= GREEN_LED_PIN | RED_LED_PIN;
    GPIOB->DATA &= ~(GREEN_LED_PIN | RED_LED_PIN);
}

void Indicators_GreenOn(void)
{
    GPIOB->DATA |= GREEN_LED_PIN;
    GPIOB->DATA &= ~RED_LED_PIN;
}

void Indicators_RedOn(void)
{
    GPIOB->DATA |= RED_LED_PIN;
    GPIOB->DATA &= ~GREEN_LED_PIN;
}

void Indicators_AllOff(void)
{
    GPIOB->DATA &= ~(GREEN_LED_PIN | RED_LED_PIN);
}