/* 
 * File:   timer.c
 * Author: Andres D. Rebeil
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>

#define PRESCALAR_256_T1 3;
#define PRESCALAR_256_T2 7;

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 = 0;
    T1CONbits.TCKPS = PRESCALAR_256_T1;
    PR1 = 39061; 
    T1CONbits.ON = 1;
    
    IEC0bits.T1IE = 1; //enable TIMER interrupts
    IPC1bits.T1IP = 7;
    IFS0bits.T1IF = 0;
}
