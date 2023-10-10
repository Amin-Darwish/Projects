/*****************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 *  Description: Source file for keypad driver
 *
 ******************************************************/

#include "keypad.h"

/*******************************************************
 *               Function Prototypes(Privates)
 * ****************************************************/

#if (N_COL==3)
/*
 * Function responsible for mapping the switch number in the keypad
 * to its corresponding functional number in Proteus for 4x3 keypad
 */
static u8 keypad_4x3_adjustkeyNumber(u8 button_number);


#elif (N_COL==4)
/*
 * Function responsible for mapping the switch number in the keypad
 * to its corresponding functional number in Proteus for 4x4 keypad
 */
static u8 keypad_4x4_adjustkeyNumber(u8 button_number);
#endif

/*******************************************************
 *                      Function Definitions
 ********************************************************/

u8 keypad_getPressedkey(void)
{
	u8 col,row;
	while(1)
	{
		for(col=0;col<N_COL;col++)  //loop for columns

		{

			KEYPAD_PORT_DIR = (0b00010000<<col);
			/*
			 * 1>>output  , 0>>input
	        * 0b 0001 0000 (0b columns rows)
	        * the loop move at columns by shifting the  1  0001>>0010>>0100>>1000
		    */
            KEYPAD_PORT_OUT = (~(0b00010000<<col)); //11101111  pull up

            for(row=0;row<N_ROW;row++)
            {
            	if(!(GET_BIT(KEYPAD_PORT_IN,row))) /* if switch is pressed in this row*/
            	{  while (!(GET_BIT(KEYPAD_PORT_IN,row)));
                  #if(N_COL==3)
            		  return keypad_4x3_adjustkeyNumber((row*N_COL)+col+1);
                  #elif(N_COL==4)
            		  return keypad_4x4_adjustkeyNumber((row*N_COL)+col+1);
                  #endif

            	}
            }
		}
	}
}

#if(N_COL==3)
static u8 keypad_4x3_adjustkeyNumber(u8 button_number)
{
	switch(button_number)
	{
	      case 10: return '*'; //ASCII Code of *
	               break;
	      case 11: return 0;
		           break;
	      case 12: return '#'; //ASCII Code of #
	      	       break;
	      default: return button_number;


	}
}

#elif (N_COL==4)
static u8 keypad_4x4_adjustkeyNumber(u8 button_number)
{
	switch(button_number)
	{
	case 1: return 7;
	        break;
	case 2: return 8;
		    break;
	case 3: return 9;
		    break;
	case 4: return '/'; //ASCII Code of %
		    break;
	case 5: return 4;
		    break;
	case 6: return 5;
		    break;
	case 7: return 6;
		    break;
	case 8: return '*'; //ASCII Code of *
		    break;
	case 9: return 1;
		    break;
	case 10: return 2;
		     break;
	case 11: return 3;
		     break;
	case 12: return'-';   //ASCII Code of -
			 break;
	case 13: return 13;   //ASCII Code of Enter
		     break;
	case 14: return 0;
			 break;
	case 15: return '=';
			 break;
	case 16: return '+' ;  //ASCII Code of +
			 break;
	default:  return button_number;

	}
}

#endif
