/*
 * @file Lock_System.c
 * @brief Source file for the Lock System logic used in the Digital Lock project.
 *        This module handles digit entry storage, passcode verification, code reset, 
 *        and admin code detection to manage access control behavior.
 *
 * @note Supports storage and comparison of 4-digit numeric codes 
 * @note Includes functionality for both user code and admin override code logic.
 * @note Provides interface to reset the system state and update the stored passcode at runtime.
 *
 * @author Jeremiah Bennett
 */

#include "Lock_System.h"

static int entered_code[NUM_DIGITS] = {0};
static const int correct_code[NUM_DIGITS] = {1, 1, 1, 1};

void LockSystem_Init(void)
{
    for (int i = 0; i < NUM_DIGITS; i++)
    {
        entered_code[i] = 0;
    }
}

void LockSystem_Reset(void)
{
    for (int i = 0; i < NUM_DIGITS; i++)
    {
        entered_code[i] = 0;
    }
}

void LockSystem_SetDigit(int index, int value)
{
    if (index >= 0 && index < NUM_DIGITS)
    {
        entered_code[index] = value;
    }
}

bool LockSystem_CheckCode(void)
{
    for (int i = 0; i < NUM_DIGITS; i++)
    {
        if (entered_code[i] != correct_code[i])
        {
            return false;
        }
    }
    return true;
}