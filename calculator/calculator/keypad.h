/*****************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 *  Description: Header file for keypad driver
 *
 ******************************************************/

#ifndef KEYPAD_H
#define KEYPAD_H

#include "STD_types.h"
#include "BIT_math.h"

/* keypad configuration for number of rows and columns */
#define N_ROW 4
#define N_COL 4

/* keypad port configuration */
#define KEYPAD_PORT_OUT PORTD
#define KEYPAD_PORT_IN  PIND
#define KEYPAD_PORT_DIR DDRD

/*******************************************************
 *               Function Prototypes
 * ****************************************************/

/* Function responsible for getting the pressed key */

u8 keypad_getPressedkey(void);

#endif
