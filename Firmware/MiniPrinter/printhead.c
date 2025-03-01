//------------------------------------------------------------------------------------------------
//
//                          printhead.c
//                  Driver for printer head Fujitsu FTP-628M series
//                               Author: Sonikku
//
//------------------------------------------------------------------------------------------------

#include <msp430.h>
#include "printhead.h"
#include "timer.h"

unsigned char bitcount;
unsigned char bytecount;
unsigned int dataoffset;

char pix[48];

//----------------------------------------------------------------------------------------------
// Name: LoadLine
// Function: Load a line of pixel data into the print head shift register
// Parameters: Pointer to array holding 48 bytes (384 bits) of pixel data
// Returns: void
//----------------------------------------------------------------------------------------------
void LoadLine(char *pixeldata){

    unsigned char pixelbuffer;
    for(bytecount = 0; bytecount < 48; bytecount++){
        pixelbuffer = pixeldata[bytecount + dataoffset];
        for(bitcount = 0; bitcount < 8; bitcount++){

            if((pixelbuffer & 0x80) == 0x80){
            // Load a bit onto the dataline
                P1OUT |= DATA;
            } else {
                P1OUT &= ~DATA;
            }
            pixelbuffer = pixelbuffer << 1;
            // Bit is loaded onto dataline, now generate clock
            P1OUT |= CLK;
            P1OUT &= ~CLK;

        }
    }
    P1OUT &= ~LATCH;
    P1OUT |= LATCH;

}

//-----------------------------------------------------------------------------------------------
// Name: Fuse
// Function: Sequence the thermal print heads on to mark the paper
//-----------------------------------------------------------------------------------------------
void Fuse(void){
    // Only one strobe can be switched at a time, any more than that, and the VH pins are already drawing 1.3A
    P2OUT |= STROBE1;
    Delay(PrintDensity + 1);
    P2OUT &= ~STROBE1;
    //Delay(4);
    P2OUT |= STROBE2;
    Delay(PrintDensity - 1);
    P2OUT &= ~STROBE2;
    //Delay(4);
    P2OUT |= STROBE3;
    Delay(PrintDensity);
    P2OUT &= ~STROBE3;
    //Delay(4);
    P2OUT |= STROBE4;
    Delay(PrintDensity);
    P2OUT &= ~STROBE4;
    //Delay(4);
    P2OUT |= STROBE5;
    Delay(PrintDensity);
    P2OUT &= ~STROBE5;
    //Delay(4);
    P2OUT |= STROBE6;
    Delay(PrintDensity);
    P2OUT &= ~STROBE6;
    Delay(PrintDensity);
    //Delay(4);
}


//-----------------------------------------------------------------------------------------------
// Name: LineBufferLoad
// Function: Fill the line buffer with pixel data (384 pixels)
//-----------------------------------------------------------------------------------------------
void LineBufferLoad(char *pixeldata){

/*        pix[0] = 0xFF;
        pix[1] = 0x00;
        pix[2] = 0xFF;
        pix[3] = 0x00;
        pix[4] = 0xFF;
        pix[5] = 0x00;
        pix[6] = 0xFF;
        pix[7] = 0x00;
        pix[8] = 0xFF;
        pix[9] = 0x00;
        pix[10] = 0xFF;
        pix[11] = 0x00;
        pix[12] = 0xFF;
        pix[13] = 0x00;
        pix[14] = 0xFF;
        pix[15] = 0xFF;
        pix[16] = 0xFF;
        pix[17] = 0xFF;
        pix[18] = 0xFF;
        pix[19] = 0xFF;
        pix[20] = 0xFF;
        pix[21] = 0xFF;
        pix[22] = 0xFF;
        pix[23] = 0xFF;
        pix[24] = 0xFF;
        pix[25] = 0xFF;
        pix[26] = 0xFF;
        pix[27] = 0xFF;
        pix[28] = 0xFF;
        pix[29] = 0xFF;
        pix[30] = 0xFF;
        pix[31] = 0xFF;
        pix[32] = 0xFF;
        pix[33] = 0xFF;
        pix[34] = 0xFF;
        pix[35] = 0xFF;
        pix[36] = 0xFF;
        pix[37] = 0xFF;
        pix[38] = 0xFF;
        pix[39] = 0xFF;
        pix[40] = 0xFF;
        pix[41] = 0xFF;
        pix[42] = 0xFF;
        pix[43] = 0xFF;
        pix[44] = 0xFF;
        pix[45] = 0xFF;
        pix[46] = 0xFF;
        pix[47] = 0xFF; */
//        LoadLine(pix);
    LoadLine(pixeldata);

}


