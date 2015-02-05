

// ******************************************************************************************* //
//
// File:            lab0.c
// Date:            04Feb2015 
// Authors:         Alberto Heras
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24FJ64GA002.h"
#include "initLab0.h"
#include "states.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

/*********************************************************************************************/


/*********************************************************************************************/

int main(void)
{

    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();

    // This will let me change the value of state, from anywhere

     current_State_Updated_To = led4;
     previousState = led4;

    while(1)
    {

        //Use a switch statement to define the behavior based on the state
        switch(current_State_Updated_To)
        {
            case led4: led4State(); break;
            case led5: led5State(); break;
            case led6: led6State(); break;
            case led7: led7State(); break;
            case button_pressed: buttonPressedState(); break;
            case changeState: changeStateState(); break;
            case updateTime: updateTimeState(); break;
        }
    }
    return 0;
}

/*********************************************************************************************/

void _ISR _CNInterrupt(void)
{
    IFS1bits.CNIF = DOWN;
    
    if(PORTBbits.RB5 == PRESSED)
    {
        current_State_Updated_To = button_pressed;
    }
}

/*********************************************************************************************/

void _ISR _T1Interrupt()
{
    IFS0bits.T1IF = DOWN;

    if(PORTBbits.RB5 == PRESSED)
    {
        current_State_Updated_To = updateTime;
    }
}

/*********************************************************************************************/

