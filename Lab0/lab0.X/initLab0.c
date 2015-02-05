/*
* File:   initLab0.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24FJ64GA002.h"
#include "initLab0.h"
#define FCY 14745600.0
#define two_seconds 2000
#define waitTime .001 // 1 millisecond

// GLobal Variables
 volatile unsigned int elapsed_time;
 volatile int current_State_Updated_To;
 volatile int previousState;

void initLEDs(){
    //TODO: Initialize the pin connected to the LEDs as outputs
    TRISBbits.TRISB15 = ON;
    TRISBbits.TRISB14 = ON;
    TRISBbits.TRISB13 = ON;
    TRISBbits.TRISB12 = ON;

    //TODO: Turn each LED OF
    LED4 = OFF;
    LED5 = OFF;
    LED6 = OFF;
    LED7 = OFF;
}

void initSW1(){
    //TODO: Initialize the pin connected to the switch as an input.
    TRISBbits.TRISB5 = 1;
    IFS1bits.CNIF = 0;
    IEC1bits.CNIE = 1;
    CNEN2bits.CN27IE = 1;
     

}


void initTimer1(){
    //TODO: Initialize the timer

    // This is so that we do not have to calculate PR by hand.
    unsigned int prVal = (FCY*waitTime)/256.0 - 1.0;
    PR1 = prVal;
    T1CONbits.TCKPS = 0b11; //prescalar 256
    IEC0bits.T1IE = 1; // Enable the interrupt
    IFS0bits.T1IF = 0; // Put the interrupt flag down
    T1CONbits.TON = 1; // Turn the timer 1 on


}

void turnOnLED(int led)
{
    if(led == 4)
    {
        LED4 = ON;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = OFF;
    }
    else if(led == 5)
    {
        LED4 = OFF;
        LED5 = ON;
        LED6 = OFF;
        LED7 = OFF;
    }
    else if(led == 6)
    {
        LED4 = OFF;
        LED5 = OFF;
        LED6 = ON;
        LED7 = OFF;
    }
    else if(led == 7)
    {
        LED4 = OFF;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = ON;
    }

}
