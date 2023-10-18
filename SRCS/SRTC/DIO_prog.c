/**********************************
*     Author: Amin Darwish        *
*     Date: 9/8/2022              *
*     Version: 1.0                *
*     Module: DIO            *
*                                 *
*                                 *
**********************************/
#include "BIT_math.h"
#include "STD_types.h"
#include "DIO_interface.h"
#include "DIO_private.h"


void DIO_voidSetPinDir(u8 Copy_u8Port, u8 copy_u8Pin, u8 copy_u8Dir)
{
	switch(Copy_u8Port)
	{          // PORTA
	   /*   case DIO_U8_PORTA:
		  if (copy_u8Dir == DIO_U8_OUTPUT)
		  {
			  SET_BIT(DDRA, copy_u8Pin );
		  }
		  else if (copy_u8Dir == DIO_U8_INPUT)
		  {
			  CLEAR_BIT(DDRA, copy_u8Pin );
		  }
		  break;
		  */
		            // PORTB
		  case DIO_U8_PORTB:
		  if (copy_u8Dir == DIO_U8_OUTPUT)
		  {
			  SET_BIT(DDRB, copy_u8Pin );
		  }
		  else if (copy_u8Dir == DIO_U8_INPUT)
		  {
			  CLEAR_BIT(DDRB, copy_u8Pin );
		  }
		  break;
		           // PORTC
		  case DIO_U8_PORTC:
		  if (copy_u8Dir == DIO_U8_OUTPUT)
		  {
			  SET_BIT(DDRC, copy_u8Pin );
		  }
		  else if (copy_u8Dir == DIO_U8_INPUT)
		  {
			  CLEAR_BIT(DDRC, copy_u8Pin );
		  }
		  break;
		           // PORTD
		  case DIO_U8_PORTD:
		  if (copy_u8Dir == DIO_U8_OUTPUT)
		  {
			  SET_BIT(DDRD, copy_u8Pin );
		  }
		  else if(copy_u8Dir == DIO_U8_INPUT)
		  {
			  CLEAR_BIT(DDRD, copy_u8Pin );
         }
		  break;
	}
}
void DIO_voidSetPinVal(u8 Copy_u8Port, u8 copy_u8Pin, u8 copy_u8val)
{
              //PORTA
	switch(Copy_u8Port)
	{
      /*    case DIO_U8_PORTA:
		  if (copy_u8val == DIO_U8_HIGH)
		  {
			  SET_BIT(PORTA, copy_u8Pin );
		  }
		  else if (copy_u8val == DIO_U8_LOW)
		  {
			  CLEAR_BIT(PORTA, copy_u8Pin );
		  }
		  break;  */
		          //PORTB
		  case DIO_U8_PORTB:
		  if (copy_u8val == DIO_U8_HIGH)
		  {
			  SET_BIT(PORTB, copy_u8Pin );
		  }
		  else if (copy_u8val == DIO_U8_LOW)
		  {
			  CLEAR_BIT(PORTB, copy_u8Pin );
		  }
		  break;
		             //PORTC
		  case DIO_U8_PORTC:
		  if ( copy_u8val == DIO_U8_HIGH)
		  {
			  SET_BIT(PORTC, copy_u8Pin );
		  }
		  else if(copy_u8val == DIO_U8_LOW)
		  {
			  CLEAR_BIT(PORTC, copy_u8Pin );
		  }
		  break;
		             //PORTD
		  case DIO_U8_PORTD:
		  if ( copy_u8val == DIO_U8_HIGH)
		  {
			  SET_BIT(PORTD, copy_u8Pin );
		  }
		  else if (copy_u8val == DIO_U8_LOW)
		  {
			  CLEAR_BIT(PORTD, copy_u8Pin );
		  }
		  break;
	}

}
void DIO_voidSetPortVal(u8 Copy_u8Port, u8 copy_u8val)
{
    //PORTA
      switch(Copy_u8Port)
      {
        /*  case DIO_U8_PORTA:
	      PORTA = copy_u8val;
	      break;  */
	          //PORTB
          case DIO_U8_PORTB:
    	  PORTB = copy_u8val;
    	  break;
	             //PORTC
          case DIO_U8_PORTC:
    	  PORTC = copy_u8val;
    	  break;
	             //PORTD
          case DIO_U8_PORTD:
    	  PORTD = copy_u8val;
    	  break;
     }
}

u8 DIO_u8GetPinVal(u8 Copy_u8Port, u8 copy_u8Pin)
{
	u8 Local_u8Val =0;
	switch (Copy_u8Port)
	{
	/*       //PORTA
	  case DIO_U8_PORTA:
	   Local_u8Val= GET_BIT (PINA , copy_u8Pin);
	  break;  */
	        //PORTB
	  case DIO_U8_PORTB:
	   Local_u8Val= GET_BIT (PINB , copy_u8Pin);
	  break;
	        //PORTC
	  case DIO_U8_PORTC:
	   Local_u8Val= GET_BIT (PINC , copy_u8Pin);
	  break;
	         //PORTD
	  case DIO_U8_PORTD:
	   Local_u8Val= GET_BIT (PIND , copy_u8Pin);
	  break;


	}
	return Local_u8Val;
}


