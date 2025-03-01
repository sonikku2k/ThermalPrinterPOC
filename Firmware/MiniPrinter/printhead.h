//--------------------------------------------------------------------------------------------------------------
//
//          printhead.h
//      Driver for thermal print head
//--------------------------------------------------------------------------------------------------------------

#ifndef PRINTHEAD_H_
#define PRINTHEAD_H_

// Signal Definitions
//--------------------
#define CLK BIT5        // P1.5
#define DATA BIT6       // P1.6
#define LATCH BIT7      // P1.7

#define STROBE1 BIT0    // P2.0
#define STROBE2 BIT1    // P2.1
#define STROBE3 BIT2    // P2.2
#define STROBE4 BIT3    // P2.3
#define STROBE5 BIT4    // P2.4
#define STROBE6 BIT5    // P2.5

// Print Parameter Definitions
#define PrintDensity    12   // 10 is light.. 40 is dark but then media sticks to print head    // 11 light print

// Function Prototypes
//---------------------
void Fuse(void);
void LineBufferLoad(char *pixeldata);

#endif /* PRINTHEAD_H_ */
