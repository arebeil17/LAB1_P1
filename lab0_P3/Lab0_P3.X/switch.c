/* 
 * File:   switch.c
 * Author: Andres D. Rebeil
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "switch.h"

#define INPUT 1;
#define ENABLED 1;

void initSwitch()
{
    TRISDbits.TRISD6 = INPUT;
    CNPUDbits.CNPUD6 = ENABLED;
    CNCONDbits.ON = 1;
    CNENDbits.CNIED6 = 1;
    CNPUDbits.CNPUD6 = ENABLED; // PULLUP RESISTOR
    IFS1bits.CNDIF = 0;
    IPC8bits.CNIP = 7;
    //IPC8bits.CNIS = 3;
    IEC1bits.CNDIE = 1;
   
}
