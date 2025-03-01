//------------------------------------------------------------------------------------------------
//                      stepper.c
//                  Stepper motor driver via BA6845 dual 1/2 H bridge
//
//          Notes: IN12 and IN22 are technically used to enable/disable the H-bridge, the driver uses
//                 a single pin to toggle the coil between FWD and REVERSE
//------------------------------------------------------------------------------------------------

#include <msp430.h>
#include "stepper.h"
#include "printhead.h"


unsigned char stepsequence;
unsigned char stepper_enable;
unsigned char stepper_hold;
unsigned char line_marker;
unsigned char print_enabled;


//--------------------------------------------------------------------------------------
// Name: InitStepper
// Function: Initialise Stepper driver and variables
//--------------------------------------------------------------------------------------
void InitStepper(void){
    stepsequence = 0x00;
    stepper_enable = false;
    line_marker = false;
    stepper_hold = false;
    print_enabled = false;


}

//--------------------------------------------------------------------------------------
// Name: StepperSvc
// Function: Routine called in a timer interrupt to generate motor step logic
// Parameters: void
// Returns: void
//--------------------------------------------------------------------------------------
void StepperSvc(void){

    if(stepper_hold == true){
        return;
    }
    if(stepper_enable == true){
        // Run in 1-2 phase excitation mode
        switch(stepsequence){
        case 0x00:
            P1OUT &= ~IN11;
            P1OUT |= IN12;
            P1OUT &= ~IN21;
            P1OUT &= ~IN22;
            break;

        case 0x01:
            P1OUT &= ~IN11;
            P1OUT |= IN12;
            P1OUT &= ~IN21;
            P1OUT |= IN22;
            break;

        case 0x02:
            P1OUT &= ~IN11;
            P1OUT &= ~IN12;
            P1OUT &= ~IN21;
            P1OUT |= IN22;
            break;

        case 0x03:
            P1OUT |= IN11;
            P1OUT |= IN12;
            P1OUT &= ~IN21;
            P1OUT |= IN22;
            line_marker = true;
            break;

        case 0x04:
            P1OUT |= IN11;
            P1OUT |= IN12;
            P1OUT &= ~IN21;
            P1OUT &= ~IN22;
            break;

        case 0x05:
            P1OUT |= IN11;
            P1OUT |= IN12;
            P1OUT |= IN21;
            P1OUT |= IN22;
            break;

        case 0x06:
            P1OUT &= ~IN11;
            P1OUT &= ~IN12;
            P1OUT |= IN21;
            P1OUT |= IN22;
            break;

        case 0x07:
            P1OUT &= ~IN11;
            P1OUT |= IN12;
            P1OUT |= IN21;
            P1OUT |= IN22;
            line_marker = true;
            break;

        }
        stepsequence--;
        if(stepsequence == 0xFF){
            stepsequence = 0x07;
        }
    } else {
        P1OUT &= ~IN11;
        P1OUT &= ~IN12;
        P1OUT &= ~IN21;
        P1OUT &= ~IN22;
    }


}
