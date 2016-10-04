/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
   
    INTCON2bits.GIE = 0;
    
    initIO();
    initTimer1();
    initSPI();

    INTCON1bits.NSTDIS = 0;
    INTCON2bits.GIE = 0;
    

}

void initTimer1(){
    
    TMR1 = 0x0;
    
    T1CONbits.TON = 0;
    T1CONbits.TSIDL = 0;
    T1CONbits.TCKPS = 0b10; 
    T1CONbits.TGATE = 0;
    T1CONbits.TSYNC = 0;
    T1CONbits.TCS = 0;
    
    IPC0bits.T1IP = 2;
    IFS0bits.T1IF = 0;
    IEC1bits.CNIE = 1;
    IEC0bits.T1IE = 1;
    
    T1CONbits.TON = 0;
    
}

void initIO(){
    
    ANSELA = 0x0000;
    ANSELB = 0x0000;
    
    TRISA = 0xfffc;
    TRISB = 0xffff;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    
}

void initSPI(){
    
    // stop spi1 and 2
    SPI1STATbits.SPIEN = 0;
    SPI2STATbits.SPIEN = 0;
    
    // clean flag and init interrupt
  //  SPI1BUF = 0;
    IFS0bits.SPI1IF = 0; 
    IEC0bits.SPI1IE = 0;
    IPC2bits.SPI1IP = 5;
    
    
    // set SPI as master
    SPI1CON1bits.DISSCK = 0;
    SPI1CON1bits.DISSDO = 0;
    SPI1CON1bits.MODE16 = 0;
    SPI1CON1bits.SSEN = 0;
    SPI1CON1bits.CKP = 0;
    SPI1CON1bits.MSTEN = 1;
    SPI1CON1bits.SPRE = 0b111;
    SPI1CON1bits.PPRE = 0b11;
    
    
    //  clean framed mode
    
//    SPI1CON2bits.FRMEN = 0;
//    SPI1CON2bits.SPIFSD = 0;
//    SPI1CON2bits.FRMPOL = 0;
//    SPI1CON2bits.FRMDLY = 0;
//    SPI1CON2bits.SPIBEN = 0;

    SPI1CON2 = 0x0000;
    
    // clean status
    
    SPI1STATbits.SPISIDL = 0;
    SPI1STATbits.SPIBEC = 0b00;
    SPI1STATbits.SRMPT = 0;
    SPI1STATbits.SPIROV = 0;
    SPI1STATbits.SRXMPT = 0;
    SPI1STATbits.SISEL = 0b111;
//    SPI1STATbits.SPIEN = 1;
    
    SPI1STAT = 0x0000;
    
    
    SPI1CON1bits.SMP = 0;
    SPI1CON1bits.CKE = 0;

    // restart spi1
    SPI1CON1bits.SSEN = 0;
    SPI1STATbits.SPIROV = 0;
 
    SPI1STATbits.SPIEN = 1; 
    
}

unsigned char writeSPI1(unsigned char data){
    
PORTAbits.RA0 = !PORTAbits.RA0;
//SPI1STATbits.SPITBF = 0;
//while(!SPI1STATbits.SPITBF);
SPI1BUF = data;    
while(!SPI1STATbits.SPITBF);



return SPI2BUF;
}