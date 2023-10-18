#ifndef F_CPU  
#define F_CPU 16000000UL
#endif
#include <util/delay.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "lcd.h"
#include "SRTC.h"


int main(void)
{   
	
	PORT_voidInit();
	LCD_init();
	ADC_voidInit();
    
	
    while (1) 
    {  
		Timer1();
		Timer2() ;
		ADC_Current_Read();
		ADC_Temp_Read();
		Door_ReadSignal();
		AC1_PrintStatus();
		AC2_PrintStatus();
		Operation();
		Display_Status();
		Alarm_ON();
    }
}

