/*
 * File:   main.c
 * Author: share
 *
 * Created on September 15, 2026, 8:35 PM
 */


#include <xc.h>
 #include "matrix_keypad.h"
#include "clcd.h"
#include "adc.h"


void init_config()
{
   
    PORTB=0x00;
     
    init_adc( );
    init_clcd();
    init_matrix_keypad( );
    TRISB0=0;
    TRISB1=0;
    TRISB6=0;
    TRISB7=0;
    clcd_print("RPM",LINE1(0));
    clcd_print("INDICATOR",LINE1(7));
    
}
    
void main(void) {
    
    init_config();
    unsigned int delay=0;
    int key;
    unsigned int RPM;
    while(1)
    {
        RPM=(read_adc(CHANNEL4)*6000)/1023;
        clcd_putch((RPM/1000)+'0', LINE2(0));
        clcd_putch(((RPM/100)/10)+'0', LINE2(1));
        clcd_putch(((RPM %100)/10)+'0', LINE2(2));
        clcd_putch((RPM%10)+'0', LINE2(3));
        
        key=read_switches(LEVEL_CHANGE);
        if(key== MK_SW1)
        {
            clcd_print("<-----",LINE1(7));
            if(++delay<5000)
            {  RB0=1;
               RB1=1;
                
            }else if( delay <10000)
            {
                RB0=0;
               RB1=0;
            }else {
                delay=0;
            }
        }else if(key==MK_SW2)
        {
            RB0=0;
            RB1=0;
        
            clcd_print("<-----",LINE1(7));
            if(++delay<5000)
            {  RB6=1;
               RB7=1;
                
            }else if( delay <10000)
            {
                RB6=0;
               RB7=0;
            }else {
                delay=0;
            }
        }else if(key== MK_SW3)
        {
            RB0=0;
            RB1=0;
             RB6=0;
             RB7=0;
               clcd_print("        ",LINE1(7));
               
        }
        
        
        
        
    }
         
     
}
