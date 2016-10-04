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


//#include <stdint.h>        /* Includes uint16_t definition                    */
//#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

volatile unsigned int Buf1[10];
volatile unsigned char indexBuffer = 0;
volatile char newData = 0;

int main(void)
{

   // char lastBufferRead = 0;
    
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();

    PORTA = 0x0000;

    PORTAbits.RA1 = 1;
    
    while(1)
    {
       // writeSPI1('a');;
         writeSPI1('a');
       // PORTAbits.RA0 = !PORTAbits.RA0;
        
       // if( newData == 1){
            
            
            
       // }
        
        
    }

}
