/* 
 * File:   led.c
 * Author: Andres D. Rebeil
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"

#define OUTPUT 0;
#define OFF 0;
#define ON 1;

void initLEDs(){
    
    //TODO: Initialize LEDs
    TRISDbits.TRISD0 = OUTPUT;
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;
}

void turnOnLED(int led){
    
    //TODO: You may choose to write this function
    // as a matter of convenience
    if(led == 0)
    {
        LATDbits.LATD0 = ON;
        LATDbits.LATD1 = OFF;
        LATDbits.LATD2 = OFF;
    }else if(led == 1)
    {
        LATDbits.LATD0 = OFF;
        LATDbits.LATD1 = ON;
        LATDbits.LATD2 = OFF;
    }else if(led == 2)
    {
        LATDbits.LATD0 = OFF;
        LATDbits.LATD1 = OFF;
        LATDbits.LATD2 = ON;
    }else
    {
        LATDbits.LATD0 = ON;
        LATDbits.LATD1 = ON;
        LATDbits.LATD2 = ON;
    }
    
}