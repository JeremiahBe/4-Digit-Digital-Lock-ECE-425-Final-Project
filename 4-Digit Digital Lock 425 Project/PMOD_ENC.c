/**
 * @file PMOD_ENC.c
 * @brief Source code for the PMOD_ENC driver.
 *
 *
 * @author Jeremiah Bennett
 *
 */
 
#include "PMOD_ENC.h"

void PMOD_ENC_Init(void)
{
    // Enable the clock to Port D by setting the Bit 3
    SYSCTL->RCGCGPIO |= 0x08;

    // Configure the PD3, PD2, PD1, and PD0 pins as inputs
    GPIOD->DIR &= ~PMOD_ENC_ALL_PINS_MASK;


    GPIOD->AFSEL &= ~PMOD_ENC_ALL_PINS_MASK;

    // Enable the digital functionality for the PD3, PD2, PD1, and PD0 pins
    GPIOD->DEN |= PMOD_ENC_ALL_PINS_MASK;
}

uint8_t PMOD_ENC_Get_State(void)
{
	uint8_t state = GPIOD -> DATA & PMOD_ENC_ALL_PINS_MASK;
  return state;
}

int PMOD_ENC_Get_Rotation(uint8_t state, uint8_t last_state)
{

    if ((state & PMOD_ENC_PIN_A_MASK) != 0 && (last_state & PMOD_ENC_PIN_A_MASK) == 0)
    {
        if ((state & PMOD_ENC_PIN_B_MASK) != 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return 0;
    }
}

uint8_t PMOD_ENC_Button_Read(uint8_t state)
{
    return state & PMOD_ENC_BUTTON_MASK;
}

uint8_t PMOD_ENC_Switch_Read(uint8_t state)
{
    return state & PMOD_ENC_SWITCH_MASK;
}