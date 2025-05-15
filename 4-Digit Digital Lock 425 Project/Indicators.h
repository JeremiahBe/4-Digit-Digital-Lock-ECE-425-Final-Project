/*
 * @file Indicators.h
 * @brief Header file for the visual indicators (LEDs) used in the Digital Lock System.
 *        Declares functions for initializing and controlling red and green LEDs to 
 *        provide feedback
 *
 * @note LEDs are typically connected to GPIO Port B (e.g., PB0 for green, PB1 for red).
 * @note Refer to Table 2-9 (Interrupts) on pages 104 - 106 from the TM4C123G 
 *       Microcontroller Datasheet for relevant GPIO interrupt references if extended.
 *
 * @author Jeremiah Bennett
 */

#include <stdint.h>

// Initializes GPIOB pins for Green and Red LEDs
void Indicators_Init(void);

// Turns ON the Green LED and turns OFF the Red LED
void Indicators_GreenOn(void);

// Turns ON the Red LED and turns OFF the Green LED
void Indicators_RedOn(void);

// Turns OFF both LEDs
void Indicators_AllOff(void);

