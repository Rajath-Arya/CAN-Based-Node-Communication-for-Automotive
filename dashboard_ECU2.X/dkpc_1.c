/*
 * File:   dkpc.c
 * Author: share
 *
 * Created on September 15, 2026, 8:16 PM
 */


#include <xc.h>
#include "dkps.h"


void initdkps()
{
    TRISC=0x0F;
}

char dkps(int trigger)
{
    if(trigger== LEVEL)
    {
        return PORTC & 0x0F;
    }
    if(trigger==EDGE)
    {
        static unsigned int sw_pressed=0;
        if(PORTC & 0x0F !=0x0F && sw_pressed==0)
        {
            sw_pressed=1;
            return PORTC & 0x0F;
        }else if(PORTC & 0x0F ==0x0F)
        {
            sw_pressed=0;
        }
        return 0x0F;
    }
}
            
        
    
