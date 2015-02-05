#include "states.h"
#include "initLab0.h"
#include "p24FJ64GA002.h"

// This will prevent the elapsed time from overflowing if the switch is 
// held down for too long
#define greater_than_two_sec 2001

/*****************************************************************************/

void led4State()
{
    elapsed_time = 0;
    previousState = 4;
    turnOnLED(4);
}

/*****************************************************************************/
void led5State()
{
    elapsed_time = 0;
    previousState = 5;
    turnOnLED(5);
}

/*****************************************************************************/

void led6State()
{
    elapsed_time = 0;
    previousState = 6;
    turnOnLED(6);
}

/*****************************************************************************/

void led7State()
{
    elapsed_time = 0;
    previousState = 7;
    turnOnLED(7);
}

/*****************************************************************************/

void buttonPressedState()
{
    if(PORTBbits.RB5 == RELEASED)
    {  
        current_State_Updated_To = changeState;
    }
    else
    {
        if(elapsed_time > two_seconds)
        {
            elapsed_time == greater_than_two_sec;
        }
    }
}

/*****************************************************************************/

void changeStateState()
{
    if(elapsed_time > 2000)
    {
        if(previousState == led4)
        {
            current_State_Updated_To = led7;
        }
        else if(previousState == led5 )
        {
            current_State_Updated_To = led4;
        }
        else if(previousState == led6 )
        {
            current_State_Updated_To = led5;
        }
        else if(previousState == led7 )
        {
            current_State_Updated_To = led6;
        }
    }
    else
    {
        if(previousState == led4)
        {
            current_State_Updated_To = led5;
        }
        else if(previousState == led5 )
        {
            current_State_Updated_To = led6;
        }
        else if(previousState == led6 )
        {
            current_State_Updated_To = led7;
        }
        else if(previousState == led7 )
        {
            current_State_Updated_To = led4;
        }
    }
}

/*****************************************************************************/

void updateTimeState()
{
    elapsed_time+= 1;

    if(PORTBbits.RB5 == PRESSED)
    {
        current_State_Updated_To = button_pressed;
    }
    else
    {
        current_State_Updated_To = changeState;
    }
}

/*****************************************************************************/




