/* 
 * File:   keypad.h
 * Author: VV
 *
 * Created on September 18, 2023, 6:00 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#include"../MCAL_LAYER/GPIO/hal_gpio.h"

#define rows 4
#define columns 4
typedef struct{
    port_details keypad_row[rows];
    port_details keypad_columns[columns];
}keypad_type;
void keypad_initial( keypad_type*k);
void keypad_get_value( keypad_type*k,char* val);

#endif	/* KEYPAD_H */

