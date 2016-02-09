/*
This file contains all Controllino specific extensions to standard Arduino framework:
	- I/O pin aliases
	- RTC API interface
	- RS485 interface

Version 0.9
25.9.2015

Version History
0.1 - 1.8.2014 - First header definition of all key words
0.2 - 6.8.2014 - Updated functions prototypes
0.3 - 17.9.2014 - Added Maxi definitions, rewrote everything to double digit numbering
0.4 - 9.10.2014 - Added comments to function headers
0.5 - 17.10.2014 - Updated headers to conserve memory. Cosmetic changes. 
0.6 - 14.1.2015 - RS485 interface.
0.7 - 10.2.2015 - Updated RTC SS functions
0.8 - 3.6.2015 - Added visual aliases
0.9 - 25.9.2015 - Updated RTC functions with weekdays
*/

#ifndef Controllino_h
#define Controllino_h

#include "SPI.h"

// For backwards compatibility
#if ARDUINO > 22
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#ifdef CONTROLLINO_MINI
// Controllino I/O pin alias vs Arduino pin number
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_00 2
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_00 2

#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_01 3
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_01 3

#define CONTROLLINO_SCREW_TERMINAL_RELAY_02 4
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_02 4
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_02 4

#define CONTROLLINO_SCREW_TERMINAL_RELAY_03 5
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_03 5
#define CONTROLLINO_PIN_HEADER_PWM_00 5
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_03 5
#define CONTROLLINO_SCREW_TERMINAL_PWM_00 5

#define CONTROLLINO_SCREW_TERMINAL_RELAY_04 6
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_04 6
#define CONTROLLINO_PIN_HEADER_PWM_01 6
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_04 6
#define CONTROLLINO_SCREW_TERMINAL_PWM_01 6

#define CONTROLLINO_SCREW_TERMINAL_RELAY_05 7
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_05 7
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_05 7

#define CONTROLLINO_SCREW_TERMINAL_RELAY_00 8
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_00 8
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_00 8

#define CONTROLLINO_SCREW_TERMINAL_RELAY_01 9
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_01 9
#define CONTROLLINO_PIN_HEADER_PWM_02 9
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_01 9
#define CONTROLLINO_SCREW_TERMINAL_PWM_02 9

#define CONTROLLINO_PIN_HEADER_PWM_03 10
#define CONTROLLINO_PIN_HEADER_SS 10
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_08 10
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_08 10

#define CONTROLLINO_PIN_HEADER_PWM_04 11
#define CONTROLLINO_PIN_HEADER_MOSI 11
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_09 11
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_09 11

#define CONTROLLINO_PIN_HEADER_MISO 12
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_10 12
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_10 12

#define CONTROLLINO_PIN_HEADER_SCK 13
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_11 13
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_11 13

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_00 14
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_00 14
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_00 14
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_00 14

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_01 15
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_01 15
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_01 15
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_01 15

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_02 16
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_02 16
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_02 16
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_02 16

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_03 17
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_03 17
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_03 17
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_03 17

#define CONTROLLINO_PIN_HEADER_SDA 18
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_06 18
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_06 18

#define CONTROLLINO_PIN_HEADER_SCL 19
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_07 19
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_07 19

#define CONTROLLINO_PIN_HEADER_ANALOG_IN_06 20
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_IN_06 20

#define CONTROLLINO_PIN_HEADER_ANALOG_IN_07 21
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_IN_07 21

//Controllino MINI visual aliases

#define CONTROLLINO_D0 4
#define CONTROLLINO_D1 5
#define CONTROLLINO_D2 6
#define CONTROLLINO_D3 7
#define CONTROLLINO_D4 8
#define CONTROLLINO_D5 9
#define CONTROLLINO_D6 18
#define CONTROLLINO_D7 19

#define CONTROLLINO_A0 14
#define CONTROLLINO_A1 15
#define CONTROLLINO_A2 16
#define CONTROLLINO_A3 17
#define CONTROLLINO_A4 20
#define CONTROLLINO_A5 21
#define CONTROLLINO_IN0 2
#define CONTROLLINO_IN1 3

#endif

#ifdef CONTROLLINO_MAXI

#define CONTROLLINO_PIN_HEADER_PWM_00 2
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_00 2
#define CONTROLLINO_SCREW_TERMINAL_PWM_00 2
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_00 2

#define CONTROLLINO_PIN_HEADER_PWM_01 3
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_01 3
#define CONTROLLINO_SCREW_TERMINAL_PWM_01 3
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_01 3

#define CONTROLLINO_PIN_HEADER_PWM_02 4
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_02 4
#define CONTROLLINO_SCREW_TERMINAL_PWM_02 4
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_02 4

#define CONTROLLINO_PIN_HEADER_PWM_03 5
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_03 5
#define CONTROLLINO_SCREW_TERMINAL_PWM_03 5
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_03 5

#define CONTROLLINO_PIN_HEADER_PWM_04 6
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_04 6
#define CONTROLLINO_SCREW_TERMINAL_PWM_04 6
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_04 6

#define CONTROLLINO_PIN_HEADER_PWM_05 7
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_05 7
#define CONTROLLINO_SCREW_TERMINAL_PWM_05 7
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_05 7

#define CONTROLLINO_PIN_HEADER_PWM_06 8
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_06 8
#define CONTROLLINO_SCREW_TERMINAL_PWM_06 8
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_06 8

#define CONTROLLINO_PIN_HEADER_PWM_07 9
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_07 9
#define CONTROLLINO_SCREW_TERMINAL_PWM_07 9
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_07 9

#define CONTROLLINO_PIN_HEADER_PWM_08 10
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_08 10
#define CONTROLLINO_SCREW_TERMINAL_PWM_08 10
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_08 10

#define CONTROLLINO_PIN_HEADER_PWM_09 11
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_09 11
#define CONTROLLINO_SCREW_TERMINAL_PWM_09 11
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_09 11

#define CONTROLLINO_PIN_HEADER_PWM_10 12
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_10 12
#define CONTROLLINO_SCREW_TERMINAL_PWM_10 12
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_10 12

#define CONTROLLINO_PIN_HEADER_PWM_11 13
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_11 13
#define CONTROLLINO_SCREW_TERMINAL_PWM_11 13
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_11 13


#define CONTROLLINO_RS485_TX 14

#define CONTROLLINO_RS485_RX 15

#define CONTROLLINO_UART_TX 16

#define CONTROLLINO_UART_RX 17

#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_16 18
#define CONTROLLINO_PIN_HEADER_INT_00 18
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_16 18
#define CONTROLLINO_SCREW_TERMINAL_INT_00 18

#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_17 19
#define CONTROLLINO_PIN_HEADER_INT_01 19
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_17 19
#define CONTROLLINO_SCREW_TERMINAL_INT_01 19

#define CONTROLLINO_PIN_HEADER_SDA 20
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_25 20

#define CONTROLLINO_PIN_HEADER_SCL 21
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_24 21

#define CONTROLLINO_RELAY_00 22

#define CONTROLLINO_RELAY_01 23

#define CONTROLLINO_RELAY_02 24

#define CONTROLLINO_RELAY_03 25

#define CONTROLLINO_RELAY_04 26

#define CONTROLLINO_RELAY_05 27

#define CONTROLLINO_RELAY_06 28

#define CONTROLLINO_RELAY_07 29

#define CONTROLLINO_RELAY_08 30

#define CONTROLLINO_RELAY_09 31

#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_12 42

#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_13 43

#define CONTROLLINO_PIN_HEADER_PWM_12 44
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_14 44

#define CONTROLLINO_PIN_HEADER_PWM_13 45
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_15 45

#define CONTROLLINO_PIN_HEADER_MISO 50
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_29 50

#define CONTROLLINO_PIN_HEADER_MOSI 51
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_28 51

#define CONTROLLINO_PIN_HEADER_SCK 52
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_27 52

#define CONTROLLINO_PIN_HEADER_SS 53
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_26 53

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_00 54
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_00 54
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_00 54 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_00 54
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_00 54
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_00 54

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_01 55
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_01 55
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_01 55 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_01 55
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_01 55
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_01 55

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_02 56
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_02 56
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_02 56 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_02 56
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_02 56
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_02 56

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_03 57
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_03 57
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_03 57 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_03 57
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_03 57
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_03 57

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_04 58
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_04 58
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_04 58 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_04 58
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_04 58
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_04 58

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_05 59
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_05 59
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_05 59 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_05 59
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_05 59
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_05 59

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_06 60
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_06 60
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_06 60 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_06 60
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_06 60
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_06 60

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_07 61
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_07 61
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_07 61 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_07 61
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_07 61
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_07 61

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_08 62
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_08 62
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_08 62 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_08 62
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_08 62
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_08 62

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_09 63
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_09 63
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_09 63 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_09 63
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_09 63
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_09 63

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_10 64
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_10 64
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_10 64

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_11 65
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_11 65
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_11 65

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_12 66
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_12 66
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_12 66

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_13 67
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_13 67
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_13 67

//Controllino MAXI visual aliases

#define CONTROLLINO_D0 2
#define CONTROLLINO_D1 3
#define CONTROLLINO_D2 4
#define CONTROLLINO_D3 5
#define CONTROLLINO_D4 6
#define CONTROLLINO_D5 7
#define CONTROLLINO_D6 8
#define CONTROLLINO_D7 9
#define CONTROLLINO_D8 10
#define CONTROLLINO_D9 11
#define CONTROLLINO_D10 12
#define CONTROLLINO_D11 13

#define CONTROLLINO_A0 54
#define CONTROLLINO_A1 55
#define CONTROLLINO_A2 56
#define CONTROLLINO_A3 57
#define CONTROLLINO_A4 58
#define CONTROLLINO_A5 59
#define CONTROLLINO_A6 60
#define CONTROLLINO_A7 61
#define CONTROLLINO_A8 62
#define CONTROLLINO_A9 63
#define CONTROLLINO_IN0 18
#define CONTROLLINO_IN1 19

#define CONTROLLINO_MINUS 14
#define CONTROLLINO_PLUS 15

#define CONTROLLINO_R0 22
#define CONTROLLINO_R1 23
#define CONTROLLINO_R2 24
#define CONTROLLINO_R3 25
#define CONTROLLINO_R4 26
#define CONTROLLINO_R5 27
#define CONTROLLINO_R6 28
#define CONTROLLINO_R7 29
#define CONTROLLINO_R8 30
#define CONTROLLINO_R9 31


#endif

#ifdef CONTROLLINO_MEGA

#define CONTROLLINO_PIN_HEADER_PWM_00 2
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_00 2
#define CONTROLLINO_SCREW_TERMINAL_PWM_00 2
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_00 2

#define CONTROLLINO_PIN_HEADER_PWM_01 3
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_01 3
#define CONTROLLINO_SCREW_TERMINAL_PWM_01 3
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_01 3

#define CONTROLLINO_PIN_HEADER_PWM_02 4
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_02 4
#define CONTROLLINO_SCREW_TERMINAL_PWM_02 4
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_02 4

#define CONTROLLINO_PIN_HEADER_PWM_03 5
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_03 5
#define CONTROLLINO_SCREW_TERMINAL_PWM_03 5
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_03 5

#define CONTROLLINO_PIN_HEADER_PWM_04 6
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_04 6
#define CONTROLLINO_SCREW_TERMINAL_PWM_04 6
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_04 6

#define CONTROLLINO_PIN_HEADER_PWM_05 7
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_05 7
#define CONTROLLINO_SCREW_TERMINAL_PWM_05 7
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_05 7

#define CONTROLLINO_PIN_HEADER_PWM_06 8
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_06 8
#define CONTROLLINO_SCREW_TERMINAL_PWM_06 8
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_06 8

#define CONTROLLINO_PIN_HEADER_PWM_07 9
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_07 9
#define CONTROLLINO_SCREW_TERMINAL_PWM_07 9
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_07 9

#define CONTROLLINO_PIN_HEADER_PWM_08 10
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_08 10
#define CONTROLLINO_SCREW_TERMINAL_PWM_08 10
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_08 10

#define CONTROLLINO_PIN_HEADER_PWM_09 11
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_09 11
#define CONTROLLINO_SCREW_TERMINAL_PWM_09 11
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_09 11

#define CONTROLLINO_PIN_HEADER_PWM_10 12
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_10 12
#define CONTROLLINO_SCREW_TERMINAL_PWM_10 12
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_10 12

#define CONTROLLINO_PIN_HEADER_PWM_11 13
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_11 13
#define CONTROLLINO_SCREW_TERMINAL_PWM_11 13
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_OUT_11 13


#define CONTROLLINO_RS485_TX 14

#define CONTROLLINO_RS485_RX 15

#define CONTROLLINO_UART_TX 16

#define CONTROLLINO_UART_RX 17

#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_16 18
#define CONTROLLINO_PIN_HEADER_INT_00 18
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_16 18
#define CONTROLLINO_SCREW_TERMINAL_INT_00 18

#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_17 19
#define CONTROLLINO_PIN_HEADER_INT_01 19
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_17 19
#define CONTROLLINO_SCREW_TERMINAL_INT_01 19

#define CONTROLLINO_PIN_HEADER_SDA 20
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_25 20

#define CONTROLLINO_PIN_HEADER_SCL 21
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_24 21

#define CONTROLLINO_RELAY_00 22

#define CONTROLLINO_RELAY_01 23

#define CONTROLLINO_RELAY_02 24

#define CONTROLLINO_RELAY_03 25

#define CONTROLLINO_RELAY_04 26

#define CONTROLLINO_RELAY_05 27

#define CONTROLLINO_RELAY_06 28

#define CONTROLLINO_RELAY_07 29

#define CONTROLLINO_RELAY_08 30

#define CONTROLLINO_RELAY_09 31

#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_12 42

#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_13 43

#define CONTROLLINO_PIN_HEADER_PWM_12 44
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_14 44

#define CONTROLLINO_PIN_HEADER_PWM_13 45
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_15 45

#define CONTROLLINO_PIN_HEADER_MISO 50
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_29 50

#define CONTROLLINO_PIN_HEADER_MOSI 51
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_28 51

#define CONTROLLINO_PIN_HEADER_SCK 52
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_27 52

#define CONTROLLINO_PIN_HEADER_SS 53
#define CONTROLLINO_PIN_HEADER_DIGITAL_OUT_26 53

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_00 54
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_00 54
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_00 54 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_00 54
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_00 54
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_00 54

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_01 55
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_01 55
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_01 55 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_01 55
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_01 55
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_01 55

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_02 56
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_02 56
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_02 56 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_02 56
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_02 56
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_02 56

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_03 57
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_03 57
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_03 57 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_03 57
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_03 57
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_03 57

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_04 58
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_04 58
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_04 58 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_04 58
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_04 58
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_04 58

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_05 59
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_05 59
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_05 59 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_05 59
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_05 59
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_05 59

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_06 60
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_06 60
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_06 60 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_06 60
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_06 60
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_06 60

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_07 61
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_07 61
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_07 61 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_07 61
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_07 61
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_07 61

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_08 62
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_08 62
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_08 62 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_08 62
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_08 62
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_08 62

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_09 63
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_09 63
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_ADC_IN_09 63 
#define CONTROLLINO_SCREW_TERMINAL_ANALOG_ADC_IN_09 63
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_09 63
#define CONTROLLINO_SCREW_TERMINAL_DIGITAL_IN_09 63

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_10 64
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_10 64
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_10 64

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_11 65
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_11 65
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_11 65

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_12 66
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_12 66
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_12 66

#define CONTROLLINO_PIN_HEADER_ANALOG_ADC_IN_13 67
#define CONTROLLINO_PIN_HEADER_DIGITAL_ADC_IN_13 67
#define CONTROLLINO_PIN_HEADER_DIGITAL_IN_13 67

//Controllino MEGA visual aliases

#define CONTROLLINO_D0 2
#define CONTROLLINO_D1 3
#define CONTROLLINO_D2 4
#define CONTROLLINO_D3 5
#define CONTROLLINO_D4 6
#define CONTROLLINO_D5 7
#define CONTROLLINO_D6 8
#define CONTROLLINO_D7 9
#define CONTROLLINO_D8 10
#define CONTROLLINO_D9 11
#define CONTROLLINO_D10 12
#define CONTROLLINO_D11 13
#define CONTROLLINO_D12 42
#define CONTROLLINO_D13 43
#define CONTROLLINO_D14 44
#define CONTROLLINO_D15 45
#define CONTROLLINO_D16 46
#define CONTROLLINO_D17 47
#define CONTROLLINO_D18 48
#define CONTROLLINO_D19 49

#define CONTROLLINO_A0 54
#define CONTROLLINO_A1 55
#define CONTROLLINO_A2 56
#define CONTROLLINO_A3 57
#define CONTROLLINO_A4 58
#define CONTROLLINO_A5 59
#define CONTROLLINO_A6 60
#define CONTROLLINO_A7 61
#define CONTROLLINO_A8 62
#define CONTROLLINO_A9 63
#define CONTROLLINO_A10 64
#define CONTROLLINO_A11 65
#define CONTROLLINO_A12 66
#define CONTROLLINO_A13 67
#define CONTROLLINO_A14 68
#define CONTROLLINO_A15 69
#define CONTROLLINO_I16 38
#define CONTROLLINO_I17 39
#define CONTROLLINO_I18 40
#define CONTROLLINO_IN0 18
#define CONTROLLINO_IN1 19

#define CONTROLLINO_MINUS 14
#define CONTROLLINO_PLUS 15

#define CONTROLLINO_R0 22
#define CONTROLLINO_R1 23
#define CONTROLLINO_R2 24
#define CONTROLLINO_R3 25
#define CONTROLLINO_R4 26
#define CONTROLLINO_R5 27
#define CONTROLLINO_R6 28
#define CONTROLLINO_R7 29
#define CONTROLLINO_R8 30
#define CONTROLLINO_R9 31
#define CONTROLLINO_R10 32
#define CONTROLLINO_R11 33
#define CONTROLLINO_R12 34
#define CONTROLLINO_R13 35
#define CONTROLLINO_R14 36
#define CONTROLLINO_R15 37

#endif

/* This function initializes RTC chip (RV-2123) and prepares communication via SPI using specified pin as chip select. 
WARNING: This function uses 10ms delay, because the RTC chip requires it. */
char Controllino_RTC_init(unsigned char aChipSelect);

/* This function sets the time and date to the connected RTC chip (RV-2123). Return code -1 means RTC chip was not properly initialized before. */
char Controllino_SetTimeDate(unsigned char aDay, unsigned char aWeekDay,unsigned char aMonth, unsigned char aYear, unsigned char aHour, unsigned char aMinute, unsigned char aSecond);

/* This function reads the time and date from the connected RTC chip (RV-2123) and fills supplied variables. Return code -1 means RTC chip was not properly initialized before. */
char Controllino_ReadTimeDate(unsigned char *aDay, unsigned char *aWeekDay, unsigned char *aMonth, unsigned char *aYear, unsigned char *aHour, unsigned char *aMinute, unsigned char *aSecond);

/* This set of functions reads one variable of connected RTC chip and returns it. Return code -1 means RTC chip was not properly initialized before. */
char Controllino_GetDay();
char Controllino_GetWeekDay();
char Controllino_GetMonth();
char Controllino_GetYear();
char Controllino_GetHour();
char Controllino_GetMinute();
char Controllino_GetSecond();

/* This function reads time and date of connected RTC chip and prints it on serial line. This function expects that the serial line was initialized before calling it. Return code -1 means RTC chip was not properly initialized before.
Format is DD/MM/YY   HH:MM:SS */
char Controllino_PrintTimeAndDate();

#if defined(CONTROLLINO_MAXI) || defined(CONTROLLINO_MEGA)
/* RS485 initialization function. Serial3 still needs to be initialized separately. This only inits RE and DE pins. */
char Controllino_RS485Init();

/* RS485 RE pin (PORT J5) switch. Expected values are 0 or 1 of LOW or HIGH. */
char Controllino_SwitchRS485RE(char mode);

/* RS485 DE pin (PORT J6) switch. Expected values are 0 or 1 of LOW or HIGH. */
char Controllino_SwitchRS485DE(char mode);

#endif

/* RTC SS initialization function. */
char Controllino_RTCSSInit();

/* RTC SS switch function. Expected values are 0 or 1 of LOW or HIGH.*/
char Controllino_SetRTCSS(char mode);



#endif