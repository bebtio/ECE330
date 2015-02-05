/* 
* File:   initLab0.h
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#ifndef INITLAB0_H
#define	INITLAB0_H

typedef enum stateTypeEnum{

    //TODO: Define states by name

    led4 = 4,
    led5,
    led6,
    led7,
    button_pressed,
    changeState,
    updateTime

} stateType;

// Global Variables
extern volatile unsigned int elapsed_time;
extern volatile int currentState;
extern volatile int previousState;

//Use defines for pin settings to make your code
#define LED4 LATBbits.LATB15
#define LED5 LATBbits.LATB14
#define LED6 LATBbits.LATB13
#define LED7 LATBbits.LATB12
#define OFF 1;
#define ON 0;

void initLEDs();
void initSW1();
void initTimer1();

void turnOnLED(int led);

#endif	/* INITLAB0_H */

