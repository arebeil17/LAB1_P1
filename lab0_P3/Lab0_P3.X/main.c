/* 
 * File:   main.c
 * Author: Andres D. Rebeil
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "switch.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0;
#define INPUT 1;
#define forward 1;
#define backward 0;


//TODO: Define states of the state machine
typedef enum stateTypeEnum{
    LED0, LED1, LED2
} stateType;

//TODO: Use volatile variables that change within interrupts
volatile stateType state = LED0;
volatile int direction = forward;
volatile unsigned int time = 0;
volatile int SW1 = 1;


int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    //Initialization functions
    initLEDs();
    initSwitch();
    //initTimer1();
    initTimer2();
    
    while(1){

        //TODO: Implement a state machine to create the desired functionality
        switch(state){
            case LED0:
                if(direction == 0) state = LED2;
                else if(SW1) state = LED1;
                direction = forward;
                SW1 = 0;
                delayMs(10);
            break;
            case LED1:
                if(direction == 0) state = LED0;
                else if(SW1) state = LED2;
                direction = forward;
                SW1 = 0;
                delayMs(10);
            break;
            case LED2:
                if(direction == 0) state = LED1;
                else if(SW1) state = LED0;
                direction = forward;
                SW1 = 0;
                delayMs(10);
            break;   
           
        }
        
        switch(state){
                case LED0:
                    turnOnLED(0);
                    //turnOffTimer();
                    //direction = forward;
                break;
                case LED1:
                    turnOnLED(1);
                    //turnOffTimer();
                    //direction = forward;
                break;
                case LED2:
                    turnOnLED(2);
                    //turnOffTimer();
                    //direction = forward;
                break;
        }
        
    }
    return 0;
}

//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed
void __ISR(_TIMER_1_VECTOR, IPL7SRS)_T1Interrupt()
{
    IFS0bits.T1IF = 0;
    //LATDbits.LATD0 = LATDbits.LATD0;
    time++;
}

void __ISR(_TIMER_2_VECTOR, IPL7SRS)_T2Interrupt()
{
    IFS0bits.T2IF = 0;
    LATDbits.LATD0 = LATDbits.LATD0;
    
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNInterrupt()
{
    IFS1bits.CNDIF = 0; //Put down flag
    PORTD;
    
    initTimer1();
    
    if((PORTDbits.RD6 == 1) && (time >= 1))    
    {        
        direction = 0;
//             if(state ==  LED0)  state = LT0;
//             else if(state == LED1) state = LT1;
//             else if(state == LED2) state = LT2;
             
    }else if(PORTDbits.RD6 == 1)
    {   SW1 = 1;
        //direction = backward;
//        if(direction == 1)
//        {   if(state ==  LT0) state = LED1;
//            else if(state == LT1) state = LED2;
//            else if(state == LT2)state = LED0;
//        }else
//        {
//            if(state ==  LT0) state = LED2;
//            else if(state == LT1) state = LED0;
//            else if(state == LT2)state = LED1;
//            direction = forward;
//        }
    }
       time = 0;
  
}