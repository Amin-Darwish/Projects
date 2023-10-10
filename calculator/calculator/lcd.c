/*****************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 *  Description: Source file for LCD driver
 *
 ******************************************************/

#include "lcd.h"

/*******************************************************
 *                      Function Definitions
 ********************************************************/

void LCD_init(void)
{
	LCD_CTRL_PORT_DIR |=(1<<E) |(1<<RS)|(1<<RW); ///configure the control pins (E,RS,RW)
    #if (DATA_BITS_MODE ==4)
        #ifdef UPPER_PORT_PINS
	      LCD_DATA_PORT_DIR |= 0xF0; /// configure the highest 4 bits of the data port as output port
        #else
	     LCD_DATA_PORT_DIR |= 0x0F; /// configure the highest 4 bits of the data port as output port
        #endif
	     LCD_sendCommand(FOUR_BITS_DATA_MODE);
	     LCD_sendCommand(TWO_LINE_LCD_FOUR_BITS_MODE);
    #elif (DATA_BITS_MODE == 8)
	 	LCD_DATA_PORT_DIR = 0xFF; /// configure the data port as output port
	    LCD_sendCommand(TWO_LINE_LCD_EIGHT_BIT_MODE); /* use 2-line lcd and 8 bit Data Mode */
    #endif

	LCD_sendCommand(CURSOR_OFF); /* cursor off */
	LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */

}

void LCD_sendCommand(u8 command)
{
    CLEAR_BIT(LCD_CTRL_PORT,RS); /* Instruction Mode RS=0 */
	CLEAR_BIT(LCD_CTRL_PORT,RW); /* Write data to LCD RW =0 */
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT,E);  /* Enable LCD E=1 */
	_delay_ms(1);
#if (DATA_BITS_MODE ==4)

#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F)|(command & 0xF0);
#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0)|((command & 0xF0) >> 4);
#endif
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT,E); /* Disable LCD E=0 */
	_delay_ms(1);
	 SET_BIT(LCD_CTRL_PORT,E);  /* Enable LCD E=1 */
	_delay_ms(1);
#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F)|((command & 0x0F) <<4);
#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0)|(command & 0x0F);
#endif
	   _delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT,E); /* Disable LCD E=0 */
	   _delay_ms(1);
#elif (DATA_BITS_MODE ==8)
	LCD_DATA_PORT = command; /* Out the command instruction to LCD */

	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT,E); /* Disable LCD E=0 */
	_delay_ms(1);
#endif
}

void LCD_displayCharacter(u8 data)
{
	    SET_BIT(LCD_CTRL_PORT,RS); /* Data Mode RS=0 */
		CLEAR_BIT(LCD_CTRL_PORT,RW); /* Write data to LCD RW =0 */
		_delay_ms(1);
		SET_BIT(LCD_CTRL_PORT,E);  /* Enable LCD E=1 */
		_delay_ms(1);
#if (DATA_BITS_MODE == 4)

#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F)|(data & 0xF0);
#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0)|((data & 0xF0) >> 4);
#endif
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT,E); /* Disable LCD E=0 */
	_delay_ms(1);
	 SET_BIT(LCD_CTRL_PORT,E);  /* Enable LCD E=1 */
	_delay_ms(1);
#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F)|((data & 0x0F) <<4);
#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0)|(data & 0x0F);
#endif
	   _delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT,E); /* Disable LCD E=0 */
	   _delay_ms(1);
#elif (DATA_BITS_MODE ==8)
	LCD_DATA_PORT = data; /* Out the data instruction to LCD */

	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT,E); /* Disable LCD E=0 */
	_delay_ms(1);
#endif
}

void LCD_displayString(const char *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		LCD_displayCharacter(str[i]);
		i++;
	}
}

void LCD_goToRowColumn(u8 row,u8 col)
{
	u8 address;

	switch(row)
	{
	 case 0:
		    address = col;
		    break;
	 case 1:
			address = col+0x40;
			break;
	 case 2:
			address = col+0x10;
			break;
	 case 3:
			address = col+0x50;
			break;
	}

	LCD_sendCommand(address | SET_CURSOR_LOCATION);

}

void LCD_displayStringRowColumn(u8 row,u8 col,const char *str)
{
	LCD_goToRowColumn(row,col); //go to require LCD position
	LCD_displayString(str); // Display the string

}

void LCD_intgerToString(int data)
{
	char buff[16]; // string to hold ASCII result
	itoa(data,buff,10); // 10 base for decimal
	LCD_displayString(buff);
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); // clear display
}

void LCD_Cursor_ON(void)
{
	LCD_sendCommand(CURSOR_ON);
	
}
void LCD_Cursor_Blinking(void)
{
  		LCD_sendCommand(CURSOR_Blink);
		
}