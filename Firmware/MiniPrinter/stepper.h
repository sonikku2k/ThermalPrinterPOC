//----------------------------------------------------------------------------------------
//              Header file for stepper.h
//            Stepper motor Driver via BA6845
//----------------------------------------------------------------------------------------

#ifndef STEPPER_H_
#define STEPPER_H_

#define false 0
#define true 1
// Definitions of stepper phase controls
//--------------------------------------
#define IN11 BIT0
#define IN12 BIT1
#define IN21 BIT2
#define IN22 BIT4

// Function Prototypes
//--------------------------------
void InitStepper(void);
void StepperSvc(void);

#endif /* STEPPER_H_ */
