/*****************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 *  Description: Header file for lcd driver
 *
 *******************************************************/


#ifndef LCD_H_
#define LCD_H_


#include "STD_types.h"
#include "BIT_math.h"
#include "Atmega32_reg.h"
#include <util/delay.h>


/******************************************************
 *                   Preprocessor Macros
 *****************************************************/

/*LCD data bits mode configuration */

#define DATA_BITS_MODE 4
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif

/* LCD Pins  */
#define RS  1
#define RW  2
#define E   3
#define LCD_CTRL_PORT       PORTC
#define LCD_CTRL_PORT_DIR   DDRC

#define LCD_DATA_PORT       PORTC
#define LCD_DATA_PORT_DIR   DDRC

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_EIGHT_BIT_MODE 0x38
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_FOUR_BITS_MODE 0x28
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define CURSOR_Blink 0x0F
#define SET_CURSOR_LOCATION 0x80

/*******************************************************
 *               Function Prototypes
 * ****************************************************/

void LCD_sendCommand(u8 command);
void LCD_displayCharacter(u8 data);
void LCD_displayString(const char *str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(u8 row,u8 col,const char *str);
void LCD_goToRowColumn(u8 row,u8 col);
void LCD_intgerToString(u8 row,u8 col,int data);
void LCD_FloatToString(u8 row,u8 col,f32 data);
void LCD_Cursor_ON(void);
void LCD_Cursor_Blinking(void);
#endif /* LCD_H_ */
