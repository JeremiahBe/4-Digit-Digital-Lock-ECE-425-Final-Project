/**
 * @file UART0.h
 *
 * @brief Header file for the UART0 driver.
 *
 * This file contains the function definitions for the UART0 driver.
 *
 * @note Assumes that the frequency of the system clock is 50 MHz.
 *
 * @author Jeremiah Bennett
 */

#include "TM4C123GH6PM.h"

#define UART0_RECEIVE_FIFO_EMPTY_BIT_MASK 0x10
#define UART0_TRANSMIT_FIFO_FULL_BIT_MASK 0x20

/**
 * @brief Carriage return character
 */
#define UART0_CR   0x0D
/**
 * @brief Line feed character
 */
#define UART0_LF   0x0A
/**
 * @brief Back space character
 */
#define UART0_BS   0x08
/**
 * @brief escape character
 */
#define UART0_ESC  0x1B
/**
 * @brief space character
 */
#define UART0_SP   0x20
/**
 * @brief delete character
 */
#define UART0_DEL  0x7F

void UART0_Init(void);


char UART0_Input_Character(void);


void UART0_Output_Character(char data);


void UART0_Input_String(char *buffer_pointer, uint16_t buffer_size);


void UART0_Output_String(char *pt);


uint32_t UART0_Input_Unsigned_Decimal(void);


void UART0_Output_Unsigned_Decimal(uint32_t n);


uint32_t UART0_Input_Unsigned_Hexadecimal(void);


void UART0_Output_Unsigned_Hexadecimal(uint32_t number);

/**
 * @brief The UART0_Output_Newline function transmits the carriage return (CR) and line feed (LF) to go to a new line.
 *
 * @param None
 *
 * @return None
 */
void UART0_Output_Newline(void);
