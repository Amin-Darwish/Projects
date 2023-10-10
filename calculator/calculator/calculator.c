/*
 * calculator.c
 *
 * Created: 9/5/2023 11:10:20 PM
 *  Author: amind
 */ 
#include "calculator.h"
char key;
char result;
char number;
char op1,op2;

char operator;
void Calc_init()
{
	LCD_init();
	LCD_displayStringRowColumn(0,4," Welcome ");
	_delay_ms(100);
	LCD_clearScreen();	
}
void detect_number()
{  
	switch(key)
	{
		case 0 :
		if (number == 0)
		number = 0;
		else
		number = (number*10)+0;
		break;
		case 1 :
		if (number == 0)
		number = 1;
		else
		number = (number*10)+1;
		break;
		case 2 :
		if (number == 0)
		number = 2;
		else
		number = (number*10)+2;
		break;
		case 3 :
		if (number == 0)
		number = 3;
		else
		number = (number*10)+3;
		break;
		case 4 :
		if (number == 0)
		number = 4;
		else
		number = (number*10)+4;
		break;
		case 5 :
		if (number == 0)
		number = 5;
		else
		number = (number*10)+5;
		break;
		case 6 :
		if (number == 0)
		number = 6;
		else
		number = (number*10)+6;
		break;
		case 7 :
		if (number == 0)
		number = 7;
		else
		number = (number*10)+7;
		break;
		case 8 :
		if (number == 0)
		number = 8;
		else
		number = (number*10)+8;
		break;
		case 9 :
		if (number == 0)
		number = 9;
		else
		number = (number*10)+9;
		break;			
	}
      if (operator == 0) op1 = number;
	  if (operator != 0) op2 = number;		
}
void Arth_op(void)
{   
    key =  keypad_getPressedkey();
   switch (key)
   {
	   case 0: case 1: case 2: case 3: case 4:
	   case 5: case 6: case 7: case 8: case 9:
	   if ((number == 0) && (operator == 0)) LCD_clearScreen();
	   detect_number();
	   LCD_intgerToString(key);	   	   	  	   
	   break;
	   
	   case '/': case '*': case '+': case '-':
	   if ((number == 0) && (operator == 0)) LCD_clearScreen();
	   LCD_displayCharacter(key);	   
	   number  = 0 ;
       operator= key;
	   break;
	   
	   case '=' :
	   calculate();
	   LCD_goToRowColumn(1,0);
	   LCD_intgerToString(result);
	   number   = 0 ;
	   operator = 0 ;
	   break;
	   
       case 13 :
       LCD_clearScreen();
	   break;
   }

}
void calculate(void)
{		
			if (operator == '/')
			      result = op1 / op2 ; 
			else if (operator == '*')
			      result = op1 * op2 ;
			else if (operator == '-')
			      result = op1 - op2 ;
			else if (operator == '+')
			      result = op1 + op2 ;	
		op1 =result;		  		
}
