/*
 *  Amin Darwish
 */ 

#include <util/delay.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#define INITIAL_STATE  (char)0

int main()
{

	                   //Direction PORTA
	  DIO_voidSetPinDir(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTA,DIO_U8_PIN1,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTA,DIO_U8_PIN3,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTA,DIO_U8_PIN4,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTA,DIO_U8_PIN5,DIO_U8_OUTPUT);


                      //Direction PORTB
      DIO_voidSetPinDir(DIO_U8_PORTB,DIO_U8_PIN0,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTB,DIO_U8_PIN1,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTB,DIO_U8_PIN2,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTB,DIO_U8_PIN3,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTB,DIO_U8_PIN4,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTB,DIO_U8_PIN5,DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_OUTPUT);

                  //Direction PORTC
      DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN3,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN4,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN5,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN6,DIO_U8_OUTPUT);



      //Direction PORTA
      DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN2,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN3,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN4,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_OUTPUT);
      DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN6,DIO_U8_OUTPUT);

      u8 Display[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

      u8 sec0  = INITIAL_STATE;
      u8 sec1  = INITIAL_STATE;
      u8 min0  = INITIAL_STATE;
      u8 min1  = INITIAL_STATE;
      u8 hour0 = INITIAL_STATE;
      u8 hour1 = INITIAL_STATE;

      //DIO_voidSetPortVal(DIO_U8_PORTA, 0X00);
      DIO_voidSetPortVal(DIO_U8_PORTB, Display[sec0]);
      DIO_voidSetPortVal(DIO_U8_PORTC, Display[min0]);
      DIO_voidSetPortVal(DIO_U8_PORTD, Display[hour0]);




    while (1) 
    {


    	for(u8 counter=0; counter <10 ; counter++)
    	   {

   		 sec0 = counter;

    		 CLEAR_BIT(PORTA,0);
    		 SET_BIT(PORTA,1);
             PORTB = Display[sec0];
             _delay_ms(10);

    		 CLEAR_BIT(PORTA,1);
    		 SET_BIT(PORTA,0);
             PORTB = Display[sec1];
             _delay_ms(10);

    		 CLEAR_BIT(PORTA,2);
    		 SET_BIT(PORTA,3);
             PORTC = Display[min0];

             _delay_ms(10);
    		 CLEAR_BIT(PORTA,3);
    		 SET_BIT(PORTA,2);
             PORTC = Display[min1];
             _delay_ms(10);

    		 CLEAR_BIT(PORTA,4);
    		 SET_BIT(PORTA,5);
             PORTD = Display[hour0];
             _delay_ms(10);

    		 CLEAR_BIT(PORTA,5);
    		 SET_BIT(PORTA,4);
             PORTD = Display[hour1];
             _delay_ms(10);






    	        	    if((sec0==9)&(sec1<5))
    	        	    {


    	        		    if(sec1==5)
    	        		    {

    	        		            if((min0==9)&(min1<5))
    	        		            {

    	        		            	    if(min1==5)
    	        		            	    {

    	        		            	        if((hour0==9)&(hour1<24))
    	        		            	        {
    	        		            	            if(hour1==24)
    	        		            	              {
    	        		            	            	 sec0=0;
    	        		            	            	 sec1=0;
    	        		            	            	 min0=0;
    	        		            	            	 min1=0;
    	        		            	    	   	     hour0=0;
    	        		            	            	hour1=0;
    	        		            	              }
    	        		            	              else
    	        		            	              {
    	        		            	        	   hour1++;
    	        		            	              }
    	        		                       	}
    	        		            	        else
    	        		            	       	{
    	        		            	    	hour0++;
    	        		            	        }
    	        		            	    }
    	        		                    else
    	        		                    {
    	        		            	     min1++;
    	        		            	    }
    	        		            }
    	        	                else
    	        		            {
    	        	                min0++;
    	        		            }
    	        	         }
    	        	         else
    	        	         {
    	        	         sec1++;
    	        	         }
    	        	    }



    	   }

    }
}
