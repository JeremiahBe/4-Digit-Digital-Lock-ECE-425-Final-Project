/*
 * @file SysTick_Delay.h
 * @brief Digital Lock System using PMOD Encoder, Buzzer, LEDs, and UART0 (Tera Term)
  * @note This driver assumes that the system clock's frequency is 50 MHz.
 * 
 * @note Refer to Table 2-9 (Interrupts) on pages 104 - 106 from the TM4C123G Microcontroller Datasheet
 * to view the Vector Number, Interrupt Request (IRQ) Number, and the Vector Address
 * for each peripheral.
 *
 * @author Jeremiah Bennett
 */


#include <stdint.h>

// Initializes SysTick for delay functions
void SysTick_Delay_Init(void);

// Delays for the specified number of milliseconds (ms)
void SysTick_Delay1ms(uint32_t delay);

// Delays for the specified number of microseconds (us)
void SysTick_Delay1us(uint32_t delay);
