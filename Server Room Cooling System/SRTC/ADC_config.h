/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******   Layer        MCAL       ********/
/*******   Module:      ADC        ********/
/*******   Version:     1.0        ********/
/******************************************/
/******************************************/


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*
 Options:-
 	      1-ADC_ENABLE
 	      2-ADC_DISABLE

 */

#define ADC_STATUS   ADC_ENABLE
/*
 Options:-
 	      1-INT_ENABLE
 	      2-INT_DISABLE

 */

#define INT_STATUS   INT_DISABLE
/*
 Options:-
 	      1-AREF
 	      2-AVCC
 	      3-INTERNAL_2_56

 */

#define ADC_VREF  AREF

/*
  Options :
 	        1-RIGHT_ADJUSTMENT   for 10 bit
 	         2-LEFT_ADJUSTMENT   for 8 bit

  */

#define ADC_ADJUSTMENT RIGHT_ADJUSTMENT

/*
 Options of channel of input of ADC_ReadChannel FUNCTION:-
 	  
	        1-ADC_CHANNEL0
 	        2-ADC_CHANNEL1
 	        3-ADC_CHANNEL2
 	        4-ADC_CHANNEL3
 	        5-ADC_CHANNEL4
 	        6-ADC_CHANNEL5
 	        7-ADC_CHANNEL6
 	        8-ADC_CHANNEL7
	        

 */

#define ADC_CHANNEL  ADC_CHANNEL0

/*
 Options:-
 	       1-ADC_SINGLE_CONVERSION
 	       2-ADC_FREE_RUNNING
 	       3-ADC_ANALOG_COMPARATOR
 	       4-ADC_EXTI0
 	       5-ADC_TIM0_CTC
 	       6-ADC_TIM0_OVF
 	       7-ADC_TIM1_CTC_CHANNEL_B
 	       8-ADC_TIM1_OVF
 	       9-ADC_TIM1_ICU

 */

#define ADC_TRIGGERING_SOURCE   ADC_SINGLE_CONVERSION


/* options are:
*               1- DEIVISION_BY_2
*               2- DEIVISION_BY_4
*               3- DEIVISION_BY_8
*               4- DEIVISION_BY_16
*               5- DEIVISION_BY_32
*	            6- DEIVISION_BY_64
*               7- DEIVISION_BY_128
*	   
*/

#define ADC_U8_PRESCALER  DEIVISION_BY_128



#endif /* ADC_INTERFACE_H_ */
