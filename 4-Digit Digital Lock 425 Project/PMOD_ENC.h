/**
 * @file PMOD_ENC.h
 * @brief Header file for the PMOD_ENC driver.

 *
 * @author Jeremiah Bennett
 *
 */

#include "TM4C123GH6PM.h"

#define PMOD_ENC_PIN_A_MASK     0x01
#define PMOD_ENC_PIN_B_MASK     0x02
#define PMOD_ENC_BUTTON_MASK    0x04
#define PMOD_ENC_SWITCH_MASK    0x08
#define PMOD_ENC_ALL_PINS_MASK  0x0F


void PMOD_ENC_Init(void);


uint8_t PMOD_ENC_Get_State(void);


int PMOD_ENC_Get_Rotation(uint8_t state, uint8_t last_state);


uint8_t PMOD_ENC_Button_Read(uint8_t state);


uint8_t PMOD_ENC_Switch_Read(uint8_t state);
