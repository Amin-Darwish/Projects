/*
 * calculator.h
 *
 * Created: 9/5/2023 11:07:23 PM
 *  Author: amind
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "lcd.h"
#include "keypad.h"

void Calc_init();
void calc_writing();
void Arth_op(void);
void detect_number();
void calculate(void);
#endif /* CALCULATOR_H_ */