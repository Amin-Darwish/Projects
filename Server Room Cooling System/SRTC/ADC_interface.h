/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******   Layer        MCAL       ********/                 
/*******   Module:      ADC        ********/       
/*******   Version:     1.0        ********/                     
/******************************************/                               
/******************************************/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "BIT_math.h"
#include "STD_types.h"

#define ADC_DISABLE             0
#define ADC_ENABLE              1

#define INT_DISABLE             0
#define INT_ENABLE              1

#define AREF                    0
#define AVCC                    1
#define INTERNAL_2_56           3


#define RIGHT_ADJUSTMENT        0
#define LEFT_ADJUSTMENT         1

#define ADC_CHANNEL0            0
#define ADC_CHANNEL1            1
#define ADC_CHANNEL2            2
#define ADC_CHANNEL3            3
#define ADC_CHANNEL4            4
#define ADC_CHANNEL5            5
#define ADC_CHANNEL6            6
#define ADC_CHANNEL7            7

#define ADC_SINGLE_CONVERSION   0
#define ADC_FREE_RUNNING        1
#define ADC_ANALOG_COMPARATOR   2
#define ADC_EXTI0               3
#define ADC_TIM0_CTC            4
#define ADC_TIM0_OVF            5
#define ADC_TIM1_CTC_CHANNEL_B  6
#define ADC_TIM1_OVF            7
#define ADC_TIM1_ICU            8

#define DEIVISION_BY_2          1
#define DEIVISION_BY_4	        2
#define DEIVISION_BY_8	        3
#define DEIVISION_BY_16	        4
#define DEIVISION_BY_32	        5
#define DEIVISION_BY_64	        6
#define DEIVISION_BY_128        7


/*******************************************************
 *               Function Prototypes
 * ****************************************************/

/*
 *
 * function responsible for initialize the ADC driver
 *
 */
void ADC_voidInit(void);



// Function responsible for read analog data from a certain channel

u16 ADC_ReadChannel(u8 Copy_u8Channel);


#endif /* ADC_INTERFACE_H_ */
