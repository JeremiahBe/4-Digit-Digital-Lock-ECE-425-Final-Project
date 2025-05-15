/*
 * @file Lock_System.h
 * @brief Header file for the Lock System module in the Digital Lock project.
 *        Declares functions and constants used for managing user code input
 *
 * @note This header supports a 4-digit code entry system.
 * @note All values are stored in RAM and compared on demand.
 *
 * @author Jeremiah Bennett
 */



#include <stdint.h>
#include <stdbool.h>

#define NUM_DIGITS 4  // Number of digits in the lock code

// Initializes the lock system state
void LockSystem_Init(void);

// Resets the entered code and state
void LockSystem_Reset(void);

// Stores a digit value at the specified index
void LockSystem_SetDigit(int index, int value);

// Checks whether the entered code matches the correct code
bool LockSystem_CheckCode(void);

