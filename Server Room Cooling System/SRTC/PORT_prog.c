#include "STD_types.h"

#include "PORT_Config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_reg.h"


void PORT_voidInit(void)
{
	DDRA_Register = PORTA_DIR;
	DDRB_Register = PORTB_DIR;
	DDRC_Register = PORTC_DIR;
	DDRD_Register = PORTD_DIR;
	
	
	PORTA_Register = PORTB_INITIAL_VALUE;
	PORTB_Register = PORTB_INITIAL_VALUE;
	PORTC_Register = PORTB_INITIAL_VALUE;
	PORTD_Register = PORTB_INITIAL_VALUE;
	
}







