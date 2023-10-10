/*
 * calculator.c
 *
 * Created: 9/5/2023 8:35:09 PM
 * Author : amind
 */ 

#include "BIT_math.h"
#include "STD_types.h"
#include "keypad.h"
#include "calculator.h"
int main(void)
{
   
	Calc_init();
	
    while (1) 
    { 
		Arth_op();
		
    }
}

