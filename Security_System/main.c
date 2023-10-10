/*
 *  Amin Darwish
 */ 

#include <util/delay.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "Atmega32_reg.h"





int main()
{


	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN1, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN2, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN4, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN5, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN6, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN7, DIO_U8_OUTPUT);

	DIO_voidSetPinDir(DIO_U8_PORTC, DIO_U8_PIN2, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTC, DIO_U8_PIN7, DIO_U8_OUTPUT);

	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN0, DIO_U8_INPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN2, DIO_U8_INPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN6, DIO_U8_INPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN3, DIO_U8_OUTPUT);


	DIO_voidSetPinVal(DIO_U8_PORTD, DIO_U8_PIN0, DIO_U8_LOW);
	DIO_voidSetPinVal(DIO_U8_PORTD, DIO_U8_PIN2, DIO_U8_LOW);
	DIO_voidSetPinVal(DIO_U8_PORTD, DIO_U8_PIN6, DIO_U8_LOW);


 //   u8 default_password = 49;

	 u8 toggleledState1=0;
	  u8 toggleledState2=1;

	    u8 counter_ones = 0;
		u8 counter_Tens= 0 ;
	while(1)
	{
		DIO_voidSetPinVal(DIO_U8_PORTB, DIO_U8_PIN1, DIO_U8_LOW);
        DIO_voidSetPinVal(DIO_U8_PORTB, DIO_U8_PIN2, DIO_U8_HIGH);
		DIO_voidSetPortVal(DIO_U8_PORTB, (0b1101|(counter_ones<<4)));
		_delay_ms(5);

    	DIO_voidSetPinVal(DIO_U8_PORTB, DIO_U8_PIN2, DIO_U8_LOW);
        DIO_voidSetPinVal(DIO_U8_PORTB, DIO_U8_PIN1, DIO_U8_HIGH);
		DIO_voidSetPortVal(DIO_U8_PORTB, (0b1011|(counter_Tens<<4)));
		_delay_ms(5);

        if(DIO_u8GetPinVal(DIO_U8_PORTD,DIO_U8_PIN0))
	    {

			if (counter_ones == 9)
			{
				counter_ones = 0;
			}
			else
			{
				counter_ones ++ ;
			}

			while(DIO_u8GetPinVal(DIO_U8_PORTD,DIO_U8_PIN0)){};

	    }

        else if(DIO_u8GetPinVal(DIO_U8_PORTD,DIO_U8_PIN6))
	    	    {
    			 if (counter_Tens==9)
	    			{
	    				counter_Tens=0;
	    			}
	    			else
	    			{
	    				counter_Tens++;
	    			}
    			while(DIO_u8GetPinVal(DIO_U8_PORTD,DIO_U8_PIN6)){};


	    	    }



	     else if(DIO_u8GetPinVal(DIO_U8_PORTD,DIO_U8_PIN2))
	     {
	    	 if ((counter_ones==9)&(counter_Tens==4))
	    	 {
	    			DIO_voidSetPinVal(DIO_U8_PORTD, DIO_U8_PIN3, DIO_U8_HIGH);
	    	 }
	    	 else
	    	 {
	    		 DIO_voidSetPinVal(DIO_U8_PORTD, DIO_U8_PIN3, DIO_U8_LOW);
                while(1)
                {
	    		    DIO_voidSetPinVal(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_HIGH);
	    			TOGGLE_BIT(toggleledState1,0);
                    DIO_voidSetPinVal(DIO_U8_PORTC, DIO_U8_PIN2, toggleledState1);
                        _delay_ms(30);
	    			TOGGLE_BIT(toggleledState2,0);
                    DIO_voidSetPinVal(DIO_U8_PORTC, DIO_U8_PIN7, toggleledState2);
                       _delay_ms(20);

                       if(DIO_u8GetPinVal(DIO_U8_PORTD,DIO_U8_PIN1))
                       	    {
                              CLEAR_BIT(MCUCSR,DIO_U8_PIN4);
                       	    }
                }

	    	 }
	           	 while(DIO_u8GetPinVal(DIO_U8_PORTD,DIO_U8_PIN6)){};
	     }




	}


}
