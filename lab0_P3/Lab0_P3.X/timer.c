/* 
 * File:   timer.c
 * Author: Andres D. Rebeil
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#include "timer.h"
#define PRESCALAR_256_T1 3;
#define PRESCALAR_256_T2 7;
#define DISABLE 0;
#define ENABLE 1;

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 = 0;
    T1CONbits.TCKPS = PRESCALAR_256_T1;
    PR1 = 39061; 
    T1CONbits.ON = ENABLE; // enable timer
    
    IEC0bits.T1IE = 1; //enable TIMER interrupts
    IPC1bits.T1IP = 7;
    IFS0bits.T1IF = 0;
}

//void initTimer2()
//{
//    //TODO: Initialize Timer 2 to have a period of
//    // 1 second. Enable its interrupt
//    TMR2 = 0;
//    T2CONbits.TCKPS = PRESCALAR_256_T2;
//    PR2 = 39061; 
//    T2CONbits.ON = 1;
//    
//    IEC0bits.T2IE = 1; //enable TIMER interrupts
//    IPC2bits.T2IP = 7;
//    IFS0bits.T2IF = 0;
//}

void turnOffTimer()
{
    TMR1 = 0;
    T1CONbits.ON = DISABLE; //disable timer
}

void initTimer2(){
    TMR2 = 0;
    T2CONbits.TCKPS = 0;
    T2CONbits.TCS = 0;
    IFS0bits.T2IF = 0;
}

void delayMs(unsigned int delay){
    TMR2 = 0;
    PR2 = delay*624;
    IFS0bits.T2IF = 0;
    T2CONbits.ON = 1;
    while(IFS0bits.T2IF == 0);
    T2CONbits.ON = 0;
}
