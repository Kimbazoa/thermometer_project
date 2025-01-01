/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.5
        Device            :  PIC24FJ1024GB610
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#define FCY 2000000

//#pragma config ICS = PGD2
//#pragma config JTAGEN = OFF
//#pragma config BTSWP = OFF


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libpic30.h>
#include "../Micro_projet.X/mcc_generated_files/adc1.h"
#include "../Micro_projet.X/mcc_generated_files/mcc.h"
#include "../Micro_projet.X/mcc_generated_files/pin_manager.h"
#include "../Micro_projet.X/mcc_generated_files/system.h"
#include "../Micro_projet.X/lcd/lcd.h"
#include "../Micro_projet.X/lcd/print_lcd.h"
#include "../Micro_projet.X/mcc_generated_files/rtcc.h"


/*
 * 
 */

uint16_t adcvalue; 
bcdTime_t currentTime;

void ADC1_CallBack(void)
{
    adcvalue = ADC1BUF0;
}



void RTCC_CallBack(void)
{
    RTCC_TimeGet(&currentTime); 
}

int main(void) {
     //AD1CHSbits.CH0SA=4;
    SYSTEM_Initialize();
    LCD_Initialize();
    
    
    char str[16];
    char hour[32];
        
    while(1){
        
        
   float temp = ((float)adcvalue*3.3)/1024;
    temp=(temp-0.5)/0.01;
    
    //AD1CON1bits.SAMP=1;
   // __delay_ms(10);
    //AD1CON1bits.SAMP=0;
    
   // while(!AD1CON1bits.DONE);
             
//     sprintf(str, "temp:%.1fC\r", temp);
//     
//     LCD_PutString(str,16);
     
     sprintf(hour, "\rtemp:%.1fC\nhour:%2d:%2d:%2d\r",temp, currentTime.tm_hour,currentTime.tm_min,currentTime.tm_sec);
     LCD_PutString(hour,32);
    
    }
    return 0;
}
