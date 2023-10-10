/* 
 * File:   hal_gpio.c
 * Author: VV
 *
 * Created on August 17, 2023, 12:46 AM
 */

#include"hal_gpio.h"


void direcrtion_set_port(port_details*portN){
    if((portN->state)==OUTPUT)
    {
        CLEAR_BIT(*tris[portN->port],portN->pin);
    }
    else
    {
         SET_BIT(*tris[portN->port],portN->pin);
    }
    
}
void SET_LOGIC_BY_BUTTON(port_details*portN,port_details*portM){
    if(((READ_BIT(*port[portN->port],portN->pin)))==1)
    {   
        SET_BIT(*lat[portM->port],portM->pin);
    }
    else
    {   
        CLEAR_BIT(*lat[portM->port],portM->pin);
    }
    
}

void SET_LOGIC_ON(port_details*portN){
    if(((READ_BIT(*port[portN->port],portN->pin)))==0)
    {   
        SET_BIT(*lat[portN->port],portN->pin);
    }
    else
    {   
        CLEAR_BIT(*lat[portN->port],portN->pin);
    }
    
}
void SET_LOGIC_OFF(port_details*portN){
    if(((READ_BIT(*port[portN->port],portN->pin)))==0)
    {   
        CLEAR_BIT(*lat[portN->port],portN->pin);
    }
    else
    {   
        SET_BIT(*lat[portN->port],portN->pin);
    }
    
}

void READ_LOGIC(port_details*portN,char*c){
    if(((READ_BIT(*port[portN->port],portN->pin)))==1)
    {   
        *c=1;
        return;
    }
    else
    {   *c=0;
        return;
    }
}

