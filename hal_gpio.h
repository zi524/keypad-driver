/* 
 * File:   hal_gpio.h
 * Author: VV
 *
 * Created on August 17, 2023, 12:50 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
/*libraries*/
#include <../proc/pic18f4620.h>
#include"../mcal_std_types.h"
#include"../device_config.h"
/*macro define*/

#define pointer_toLATC (((volatile acsses*)0XF8B)) 
#define accses_toTRISC (((volatile acsses*)0XF94))
/*macro functions*/

#define SET_BIT(NUM,BIT_POSITION) (NUM|=(1<<BIT_POSITION))
#define CLEAR_BIT(NUM,BIT_POSITION) (NUM&=~(1<<BIT_POSITION))
#define TOGGLE_BIT(NUM,BIT_POSITION) (NUM^=(1<<BIT_POSITION))
#define READ_BIT(NUM,BIT_POSITION) ((NUM>>BIT_POSITION)&1)
/*data types*/
volatile unsigned char* tris[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};

volatile unsigned char* lat[]={&LATA,&LATB,&LATC,&LATD,&LATE};
 
volatile unsigned char* port[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

typedef union{
    struct{
        unsigned bit0:1;
        unsigned bit1:1;
        unsigned bit2:1;
        unsigned bit3:1;
        unsigned bit4:1;
        unsigned bit5:1;
        unsigned bit6:1;
        unsigned bit7:1;
    };
    char byte_direct;
}acsses;

typedef enum{
    off_button=0,
    on_button
}logic_t;

typedef enum{
    R_NOK=0,
    R_OK
}check;

typedef enum{
    OUTPUT=0,
    INPUT
}state_direction;

typedef enum{
    portA=0,
    portB,
    portC,
    portD,
    portE        
}PORT;

typedef enum{
    pin1=0,
    pin2,
    pin3,
    pin4,
    pin5,  
    pin6,
    pin7,
    pin8,         
}PIN;



typedef struct{
    unsigned pin:3;
    unsigned port:3;
    unsigned state:1;
    unsigned logic:1;
    
}port_details;

typedef struct{
port_details motor[2];
}motor;

/*declerations/prototybes*/
void direcrtion_set_port(port_details*portN);
void SET_LOGIC_BY_BUTTON(port_details*portN,port_details*portM);
void SET_LOGIC_ON(port_details*portN);
void SET_LOGIC_OFF(port_details*portN);
void READ_LOGIC(port_details*portN,char*);
#endif	/* HAL_GPIO_H */