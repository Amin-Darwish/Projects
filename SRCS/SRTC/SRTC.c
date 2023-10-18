
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "lcd.h"
#include "SRTC.h"
#include <string.h>
#define Run_Time  14400

u32 AC1_Time_Sec;
u32 AC1_Time_Min;
u32 AC1_Time_Hour;

u32 AC2_Time_Sec;
u32 AC2_Time_Min;
u32 AC2_Time_Hour;

f32 AC1_Current=0;
f32 AC2_Current=0;
u16 Temp = 0;
u16 counter1 = 0;
u16 counter2 = 0;
u8 AC1_Status = 0;
u8 AC2_Status = 0;
char AC1_Print_Status[5];
char AC2_Print_Status[5];

char door_Status[10];


void Operation(void)
{
	if ( AC1_Current >= 1.0 )   AC1_Status = 1;
	if ( AC2_Current >= 1.0 )   AC2_Status = 1;
	if ( AC1_Current < 1.0  )   AC1_Status = 0;
	if ( AC2_Current < 1.0  )   AC2_Status = 0;
 	
	if ((AC1_Status == 0)  &&  (AC2_Status == 0) && counter1 == 0 && counter2 == 0 )  // At the beginning 
	{  
        {
			AC1_ON_OFF();	
			_delay_ms(5000);
        }			
	}
	else if ((AC1_Status == 1) && (AC2_Status == 1))
	{
		if ((counter1 >= counter2) && (counter1 < Run_Time))
		{
			AC2_ON_OFF();   //ac2 off 
            _delay_ms(5000);
		}
		else if ((counter1 < counter2)  && (counter2 < Run_Time))
		{
			AC1_ON_OFF();    // ac1 off 
			_delay_ms(5000);
		}
	}

	else if ((counter1 > Run_Time) && (AC1_Status == 1) && (AC2_Status==0 ))  // AC1 > 4 hours
	{
		AC2_ON_OFF();    // ac2 on 
		_delay_ms(2);
		AC1_ON_OFF();    // ac1 off 
		_delay_ms(5000);
	}
	else if ((counter2 > Run_Time) && (AC2_Status == 1) && (AC1_Status==0 ))  //AC2 >  4 hours
	{
		AC1_ON_OFF();      // ac1 on 
		_delay_ms(2);
		AC2_ON_OFF();     // ac2 off 
	} 
}

void Display_Status(void)
{
	
	LCD_displayStringRowColumn(0,0,"AC1:");
	LCD_displayStringRowColumn(0,4,AC1_Print_Status);
	
	LCD_displayStringRowColumn(0,7,"I1:");
	LCD_intgerToString(0,10,AC1_Current);
	
	
	
	LCD_displayStringRowColumn(1,0,"AC2:");
	LCD_displayStringRowColumn(1,4,AC2_Print_Status);
	
	LCD_displayStringRowColumn(1,7,"I2:");
	LCD_intgerToString(1,10,AC2_Current);	
	
	
	
    /* Temperature displaying */
    LCD_displayStringRowColumn(0,12,"T");
    LCD_goToRowColumn(0,13);
    LCD_displayCharacter(0xDF);   // degree sign
    LCD_displayStringRowColumn(0,14,"C:");
    LCD_intgerToString(1,13,Temp);
    LCD_displayCharacter(0xDF);  

	          /* Displaying time  */
   /* counter1 */
  LCD_displayStringRowColumn(2,0,"RT1:");
 
  u32 AC1_Time_Sec = counter1 % 60 ;
  u32 AC1_Time_Min = counter1 / 60 ;
  u32 AC1_Time_Hour= counter1 / 3600 ;
  
  if (AC1_Time_Sec < 10)
  {
	  LCD_displayStringRowColumn(2,10," ");
  }
  
  else if (AC1_Time_Min < 10 )
  {
	  LCD_displayStringRowColumn(2,7," ");
	  
  }
   else if (AC2_Time_Sec < 10)
   {
	   LCD_displayStringRowColumn(3,10," ");
   }
   
   else if (AC2_Time_Min < 10 )
   {
	   LCD_displayStringRowColumn(3,7," ");
   }
	   
  LCD_intgerToString(2,4,AC1_Time_Hour);
  LCD_displayStringRowColumn(2,5,":");
  
  LCD_intgerToString(2,6,AC1_Time_Min);
  LCD_displayStringRowColumn(2,8,":");
 
  LCD_intgerToString(2,9,AC1_Time_Sec);
  
    /* counter2 */
    LCD_displayStringRowColumn(3,0,"RT2:");
    
    u32 AC2_Time_Sec = counter2 % 60 ;
    u32 AC2_Time_Min = counter2 / 60 ;
    u32 AC2_Time_Hour= counter2 / 3600 ;
    
    LCD_intgerToString(3,4,AC2_Time_Hour);
    LCD_displayStringRowColumn(3,5,":");
    
    LCD_intgerToString(3,6,AC2_Time_Min);
    LCD_displayStringRowColumn(3,8,":");
    
    LCD_intgerToString(3,9,AC2_Time_Sec);
    
  
 /* Display door status */
  LCD_displayStringRowColumn(2,12,"Door");
  LCD_displayStringRowColumn(3,12,door_Status);
	
}

void AC1_PrintStatus(void)
{
	if (AC1_Current > 1) 
	{
		  strcpy(AC1_Print_Status,"ON") ;
		  LCD_displayStringRowColumn(0,6," ");
	}
	else  strcpy(AC1_Print_Status,"OFF") ;
}
void AC2_PrintStatus(void)
{
	if (AC2_Current > 1)  
	{
		 strcpy(AC2_Print_Status,"ON") ;
		 LCD_displayStringRowColumn(1,6," ");
	}
	else  strcpy(AC2_Print_Status,"OFF") ;
}

/* Output */
void AC1_ON_OFF(void)
{  
      DIO_voidSetPinVal(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_HIGH);
      _delay_ms(10);
      DIO_voidSetPinVal(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_LOW);		
}

void AC2_ON_OFF(void)
{
	DIO_voidSetPinVal(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_HIGH);
	_delay_ms(10);
	DIO_voidSetPinVal(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_LOW);
}


void Door_ReadSignal(void)
{
	if (DIO_u8GetPinVal(DIO_U8_PORTB,DIO_U8_PIN1))
	{ 
		while(DIO_u8GetPinVal(DIO_U8_PORTB,DIO_U8_PIN1))
		
		
		strcpy(door_Status,"Close");
	}
	else 
	{
		strcpy(door_Status,"Open");
		
	}
}
void ADC_Temp_Read(void)
{   
	u32 Temp_read = (ADC_ReadChannel(0)*5000UL )/1024;
	Temp = Temp_read/10;
	
}
void ADC_Current_Read(void)
{  
	 
     f32 Analog1 = ((f32)ADC_ReadChannel(1) * 10000UL) /1024;
	 f32 Analog2 = ((f64)ADC_ReadChannel(2)* 10000UL) /1024;
	
	 AC1_Current = Analog1 /1000;
	 AC2_Current = Analog2 /1000;   
}

void Timer1(void)
{   if (AC1_Status == 1)
	{
		counter1 ++;
		
		_delay_ms(700);
	}
	else
	{
		counter1 = 0;
		
	}
}
void Timer2(void)
{
	if (AC2_Status == 1)
	{
		counter2++;
		
		_delay_ms(700);
	}
	else
	{
		counter2 = 0;
	}
}

void Alarm_ON(void)
{
	if (Temp > 28 )
	{
		DIO_voidSetPinVal(DIO_U8_PORTD,DIO_U8_PIN2,DIO_U8_HIGH);
	}
	else
	{
		DIO_voidSetPinVal(DIO_U8_PORTD,DIO_U8_PIN2,DIO_U8_LOW);
	}
}
