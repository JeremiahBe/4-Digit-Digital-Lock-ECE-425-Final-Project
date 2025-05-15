/*
 * @file Buzzer.h
 * @brief Header file for the Buzzer driver in the Digital Lock System.
 *        Declares functions for initializing and controlling a piezo buzzer
 *        to provide audio feedback for correct or incorrect code entry.
 *
 * @note This driver assumes that the system clock's frequency is 50 MHz.
 * @note The buzzer is controlled via a GPIO pin (e.g., PB2).
 * @note Refer to Table 2-9 (Interrupts) on pages 104 - 106 from the TM4C123G 
 *       Microcontroller Datasheet to view interrupt vector information.
 *
 * @author Jeremiah Bennett
 */


#include <stdint.h>

// Initializes PB2 as output for the piezo buzzer
void Buzzer_Init(void);

// Turns on the buzzer for a specified duration in milliseconds
void Buzzer_Beep(uint32_t duration_ms);

