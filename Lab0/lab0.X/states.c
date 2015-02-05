#include "states.h"
#include "initLab0.h"
#include "p24FJ64GA002.h"


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
    

    if(PORTBbits.RB5 == 1)
    {  
        currentState = changeState;
    }
    else
    {
        if(elapsed_time > 2000)
        {
            elapsed_time == 2001;
        }
        
    }
    


    /*while(PORTBbits.RB5 == 0)
    {
        
    }*/

}

/*****************************************************************************/

void changeStateState()
{
    if(elapsed_time > 2000)
    {
        if(previousState == led4)
        {
            currentState = led7;
        }
        else if(previousState == led5 )
        {
            currentState = led4;
        }
        else if(previousState == led6 )
        {
            currentState = led5;
        }
        else if(previousState == led7 )
        {
            currentState = led6;
        }
    }
    else
    {
        if(previousState == led4)
        {
            currentState = led5;
        }
        else if(previousState == led5 )
        {
            currentState = led6;
        }
        else if(previousState == led6 )
        {
            currentState = led7;
        }
        else if(previousState == led7 )
        {
            currentState = led4;
        }
    }
}

void updateTimeState()
{
    elapsed_time+= 1;

    if(PORTBbits.RB5 == 0)
    {
        currentState = button_pressed;
    }
    else
    {
        currentState = changeState;
    }
}



