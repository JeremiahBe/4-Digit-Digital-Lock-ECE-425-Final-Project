# 4-Digit-Digital-Lock-ECE-425-Final-Project

This project implements a 4-digit digital lock system using the Tiva TM4C123G microcontroller. The system allows users to enter a numeric passcode using a PMOD rotary encoder and provides real-time feedback through LEDs, a piezo buzzer, and UART serial output via Tera Term.

The project demonstrates core embedded systems concepts such as GPIO control, interrupt-driven input handling, UART communication, modular driver development, and user feedback mechanisms. If the correct passcode is entered, the system activates a green LED and a short success beep. If the passcode is incorrect, a red LED turns on, the buzzer alarms three times, and an error message is sent over UART.
