/* 
*
* File:     initLab0.h
* Author:   Alberto Heras 
* Date:     04Feb2015     
* 
*/

#ifndef INITLAB0_H
#define	INITLAB0_H

typedef enum stateTypeEnum{

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
extern volatile int current_State_Updated_To;
extern volatile int previousState;

//Use defines for pin settings to make your code
#define LED4 LATBbits.LATB15
#define LED5 LATBbits.LATB14
#define LED6 LATBbits.LATB13
#define LED7 LATBbits.LATB12
#define OFF 1;
#define ON 0;
#define PRESSED 0;
#define RELEASED 1;
#define UP 1;
#define DOWN 0;

// Functions that will be used
void initLEDs();
void initSW1();
void initTimer1();
void turnOnLED(int led);

#endif	/* INITLAB0_H */

