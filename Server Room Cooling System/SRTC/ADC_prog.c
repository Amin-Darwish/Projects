/*****************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 *  Description: Source file for ADC driver
 *
 ******************************************************/
#include "STD_types.h"
#include "BIT_math.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"


/*******************************************************
 *                      Function Definitions
 ********************************************************/

void ADC_voidInit(void)
{
	/* SET AREF as reference voltage */

	/*Select the voltage reference*/
	#if ADC_VREF == AREF
	CLEAR_BIT(ADMUX , ADMUX_REFS0) ;
	CLEAR_BIT(ADMUX , ADMUX_REFS1) ;

	#elif ADC_VREF == AVCC
	SET_BIT(ADMUX , ADMUX_REFS0) ;
	CLEAR_BIT(ADMUX , ADMUX_REFS1) ;

	#elif ADC_VREF == INTERNAL_2_56
	SET_BIT(ADMUX , ADMUX_REFS0) ;
	SET_BIT(ADMUX , ADMUX_REFS1) ;

	#else
	#error "Wrong ADC_VREF config"

	#endif

	/* Activate left adjust result */
	
	#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
	CLEAR_BIT(ADMUX , ADMUX_ADLAR) ;

	#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT(ADMUX , ADMUX_ADLAR) ;

	#else
	#error "Wrong ADC_ADJUSTMENT config"
	
	#endif
	

	
	/* Setting  prescaler */
	
	ADCSRA &= 0b11111000;      //clear first 3 bit
	ADCSRA |= ADC_U8_PRESCALER;
	
	/*Enable ADC Peripheral*/
	#if ADC_STATUS == ADC_DISABLE
	CLEAR_BIT(ADCSRA , ADCSRA_ADEN) ;
	#elif ADC_STATUS == ADC_ENABLE
	SET_BIT(ADCSRA , ADCSRA_ADEN) ;
	#else
	#error "Wrong ADC_STATUS config"
	#endif
	
	
	 /*Enable ADC Interrupt*/
	#if INT_STATUS == INT_DISABLE
		CLEAR_BIT(ADCSRA , ADCSRA_ADIE) ;
	#elif INT_STATUS == INT_ENABLE
		SET_BIT(ADCSRA , ADCSRA_ADIE) ;
	#else
	#error "Wrong INT_STATUS config"
	#endif 
	
}


u16 ADC_ReadChannel(u8 Copy_u8Channel)
{
	/*Set the required channel*/
	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8Channel;
	
	/* Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	
	/* Busy waiting on conversion complete flag */
	while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);
	
	/* Clear interrupt flag BY writing 1 */
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	/*return Conversation result */
	#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
	return (ADCL | (ADCH << 8)) ;
	#elif  ADC_ADJUSTMENT == LEFT_ADJUSTMENT
	return ADCH;
	#endif 
}

