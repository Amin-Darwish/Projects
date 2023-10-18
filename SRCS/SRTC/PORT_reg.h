/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******                           ********/                 
/*******   Module:  PORT REG    ********/       
/*******   Version:     1.0        ********/                     
/******************************************/                               
/******************************************/

#ifndef PORT_REG_H_
#define PORT_REG_H_


#define PORTA_Register  *((volatile unsigned char* const)0X3B)
#define DDRA_Register   *((volatile unsigned char* const)0X3A)
#define PINA_Register   *((volatile unsigned char* const)0X39)
#define PORTB_Register  *((volatile unsigned char* const)0X38)
#define DDRB_Register   *((volatile unsigned char* const)0X37)
#define PINB_Register   *((volatile unsigned char* const)0X36)
#define PORTC_Register  *((volatile unsigned char* const)0X35)
#define DDRC_Register   *((volatile unsigned char* const)0X34)
#define PINC_Register   *((volatile unsigned char* const)0X33)
#define PORTD_Register  *((volatile unsigned char* const)0X32)
#define DDRD_Register   *((volatile unsigned char* const)0X31)
#define PIND_Register   *((volatile unsigned char* const)0X30)


#endif