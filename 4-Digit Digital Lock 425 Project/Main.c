/*
 * @file main.c
 * @brief Digital Lock System using PMOD Encoder, Buzzer, LEDs, and UART0 (Tera Term)
  * @note This driver assumes that the system clock's frequency is 50 MHz.
 * 
 * @note Refer to Table 2-9 (Interrupts) on pages 104 - 106 from the TM4C123G Microcontroller Datasheet
 * to view the Vector Number, Interrupt Request (IRQ) Number, and the Vector Address
 * for each peripheral.
 *
 * @author Jeremiah Bennett
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "PMOD_ENC.h"
#include "Lock_System.h"
#include "Buzzer.h"
#include "Indicators.h"
#include "Timer_0A_Interrupt.h"
#include "UART0.h"

#define MAX_VAL 15
#define MIN_VAL 1

static uint8_t state = 0;
static uint8_t last_state = 0;
static uint8_t button_pressed = 0;
static int encoder_val = 1;
static int digit_index = 0;
static int last_encoder_val = -1;

void PMOD_ENC_Task(void);
void Display_Digit_Entry(void);
void Process_Code_Entry(void);
void Reset_Lock(void);

int main(void)
{
    // Initialize peripherals
    SysTick_Delay_Init();
    UART0_Init();
    PMOD_ENC_Init();
    LockSystem_Init();
    Buzzer_Init();
    Indicators_Init();

    // Start with reading the initial encoder state
    Timer_0A_Interrupt_Init(&PMOD_ENC_Task);
    last_state = PMOD_ENC_Get_State();

    Display_Digit_Entry();

    while (1)
    {
        if (button_pressed)
        {
            button_pressed = 0;
            LockSystem_SetDigit(digit_index, encoder_val);
            digit_index++;

            if (digit_index >= NUM_DIGITS)
            {
                Process_Code_Entry();
                SysTick_Delay1ms(2000);
                Reset_Lock();
            }
            else
            {
                Display_Digit_Entry();
            }
        }
    }
}

void PMOD_ENC_Task(void)
{
    state = PMOD_ENC_Get_State();

    if (PMOD_ENC_Button_Read(state) && !PMOD_ENC_Button_Read(last_state))
    {
        button_pressed = 1;
    }

    int rotation = PMOD_ENC_Get_Rotation(state, last_state);
    encoder_val += rotation;

    if (encoder_val < MIN_VAL) encoder_val = MIN_VAL;
    if (encoder_val > MAX_VAL) encoder_val = MAX_VAL;

    last_state = state;

    if (!button_pressed && digit_index < NUM_DIGITS && encoder_val != last_encoder_val)
    {
        Display_Digit_Entry();
        last_encoder_val = encoder_val;
    }
}

void Display_Digit_Entry(void)
{
    UART0_Output_String("Enter Digit ");
    UART0_Output_Unsigned_Decimal(digit_index + 1);
    UART0_Output_Newline();

    UART0_Output_String("Value: ");
    UART0_Output_Unsigned_Decimal(encoder_val);
    UART0_Output_Newline();
}

void Process_Code_Entry(void)
{
    if (LockSystem_CheckCode())
    {
        UART0_Output_String("Code Accepted!");
        UART0_Output_Newline();
        Indicators_GreenOn();
        Buzzer_Beep(600);
    }
    else
    {
        UART0_Output_String("Wrong Code!");
				UART0_Output_Newline();
				Indicators_RedOn();

				// Funny alarm style beep
				Buzzer_Beep(100);
				SysTick_Delay1ms(50);
				Buzzer_Beep(200);
				SysTick_Delay1ms(50);
				Buzzer_Beep(100);
				SysTick_Delay1ms(50);
				Buzzer_Beep(300);
    }
}

void Reset_Lock(void)
{
    LockSystem_Reset();
    Indicators_AllOff();
    digit_index = 0;
    encoder_val = 1;
    Display_Digit_Entry();
}
