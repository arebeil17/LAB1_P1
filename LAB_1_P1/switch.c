/*
 * File:   switch.c
 * Author: Garrett
 *
 * Created on September 19, 2015, 10:46 AM
 */
#include "switch.h"
#define INPUT 1
#define OUTPUT 0

void initSW2(){
    //TODO: Initialize the appropriate pins to work with the external switch using a
    //change notification interrupt.
    
    TRISAbits.TRISA7 = INPUT; //INPUT ON EXP. BOARD PIN TRD3/RA7
}


