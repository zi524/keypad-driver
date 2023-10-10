/* 
 * File:   application.c
 * Author: VV
 *
 * Created on August 17, 2023, 12:46 AM
 */

#include"application.h"
#define _XTAL_FREQ  8000000UL
char x;
keypad_type key1={
.keypad_row[0].pin=pin1,
.keypad_row[0].port=portC,
.keypad_row[0].logic=off_button,
.keypad_row[0].state=OUTPUT,

.keypad_row[1].pin=pin2,
.keypad_row[1].port=portC,
.keypad_row[1].logic=off_button,
.keypad_row[1].state=OUTPUT,

.keypad_row[2].pin=pin3,
.keypad_row[2].port=portC,
.keypad_row[2].logic=off_button,
.keypad_row[2].state=OUTPUT,

.keypad_row[3].pin=pin4,
.keypad_row[3].port=portC,
.keypad_row[3].logic=off_button,
.keypad_row[3].state=OUTPUT,

.keypad_columns[0].pin=pin5,
.keypad_columns[0].port=portC,
.keypad_columns[0].logic=off_button,
.keypad_columns[0].state=INPUT,

.keypad_columns[1].pin=pin6,
.keypad_columns[1].port=portC,
.keypad_columns[1].logic=off_button,
.keypad_columns[1].state=INPUT,

.keypad_columns[2].pin=pin7,
.keypad_columns[2].port=portC,
.keypad_columns[2].logic=off_button,
.keypad_columns[2].state=INPUT,

.keypad_columns[3].pin=pin8,
.keypad_columns[3].port=portC,
.keypad_columns[3].logic=off_button,
.keypad_columns[3].state=INPUT,


};
int main() {
    while(1){
    //colum_check=0;    
    keypad_initial(&key1);
    keypad_get_value(&key1,&x);
    }
    return (EXIT_SUCCESS);
}