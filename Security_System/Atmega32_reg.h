/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******                           ********/                 
/*******   Module:  ATMEGA32 reg   ********/       
/*******   Version:     1.0        ********/                     
/******************************************/                               
/******************************************/

#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

#define SREG   *((volatile unsigned char* const)0X5F)
#define SPH    *((volatile unsigned char* const)0X5E)
#define SPL    *((volatile unsigned char* const)0X5D)
#define OCR0   *((volatile unsigned char* const)0X5C)
#define GICR   *((volatile unsigned char* const)0X5B)
#define GIFR   *((volatile unsigned char* const)0X5A)
#define TIMSK  *((volatile unsigned char* const)0X59)
#define TIFR   *((volatile unsigned char* const)0X58)
#define SPMCR  *((volatile unsigned char* const)0X57)
#define TWCR   *((volatile unsigned char* const)0X56)
#define MCUCR  *((volatile unsigned char* const)0X55)
#define MCUCSR *((volatile unsigned char* const)0X54)
#define TCCR0  *((volatile unsigned char* const)0X53)
#define TCNT0  *((volatile unsigned char* const)0X52)
#define OSCCAL *((volatile unsigned char* const)0X51)
#define OCDR   *((volatile unsigned char* const)0X51)
#define SFIOR  *((volatile unsigned char* const)0X50)
#define TCCR1A *((volatile unsigned char* const)0X4F)
#define TCCR1B *((volatile unsigned char* const)0X4E)
#define TCNT1H *((volatile unsigned char* const)0X4D)
#define TCNT1L *((volatile unsigned char* const)0X4C)
#define OCR1AH *((volatile unsigned char* const)0X4B)
#define OCR1AL *((volatile unsigned char* const)0X4A)
#define OCR1BH *((volatile unsigned char* const)0X49)
#define OCR1BL *((volatile unsigned char* const)0X48)
#define ICR1H  *((volatile unsigned char* const)0X47)
#define ICR1L  *((volatile unsigned char* const)0X46)
#define TCCR2  *((volatile unsigned char* const)0X45)
#define TCNT2  *((volatile unsigned char* const)0X44)
#define OCR2   *((volatile unsigned char* const)0X43)
#define ASSR   *((volatile unsigned char* const)0X42)
#define WDTCR  *((volatile unsigned char* const)0X41)
#define UBRRH  *((volatile unsigned char* const)0X40)
#define UCSRC  *((volatile unsigned char* const)0X40)
#define EEARH  *((volatile unsigned char* const)0X3F)
#define EEARL  *((volatile unsigned char* const)0X3E)
#define EEDR   *((volatile unsigned char* const)0X3D)
#define EECR   *((volatile unsigned char* const)0X3C)

#define PORTA  *((volatile unsigned char* const)0X3B)
#define DDRA   *((volatile unsigned char* const)0X3A)
#define PINA   *((volatile unsigned char* const)0X39)
#define PORTB  *((volatile unsigned char* const)0X38)
#define DDRB   *((volatile unsigned char* const)0X37)
#define PINB   *((volatile unsigned char* const)0X36)
#define PORTC  *((volatile unsigned char* const)0X35)
#define DDRC   *((volatile unsigned char* const)0X34)
#define PINC   *((volatile unsigned char* const)0X33)
#define PORTD  *((volatile unsigned char* const)0X32)
#define DDRD   *((volatile unsigned char* const)0X31)
#define PIND   *((volatile unsigned char* const)0X30)

#define SPDR   *((volatile unsigned char* const)0X2F)
#define SPSR   *((volatile unsigned char* const)0X2E)
#define SPCR   *((volatile unsigned char* const)0X2D)
#define UDR    *((volatile unsigned char* const)0X2C)
#define UCSRA  *((volatile unsigned char* const)0X2B)
#define UCSRB  *((volatile unsigned char* const)0X2A)
#define UBRRL  *((volatile unsigned char* const)0X29)
#define ACSR   *((volatile unsigned char* const)0X28)
#define ADMUX  *((volatile unsigned char* const)0X27)
#define ADCSRA *((volatile unsigned char* const)0X26)
#define ADCH   *((volatile unsigned char* const)0X25)
#define ADCL   *((volatile unsigned char* const)0X24)
#define TWDR   *((volatile unsigned char* const)0X23)
#define TWAR   *((volatile unsigned char* const)0X22)
#define TWSR   *((volatile unsigned char* const)0X21)
#define TWBR   *((volatile unsigned char* const)0X20)


#endif /* ATMEGA32_REGISTERS_H_ */