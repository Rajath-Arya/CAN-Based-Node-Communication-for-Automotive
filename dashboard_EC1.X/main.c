#include <xc.h>
#include "clcd.h"
#include "adc.h"
#include "matrix_keypad.h"
#include "can.h"
#include "msg_id.h"

const uint8_t *gear[] = {
    (const uint8_t *)"ON",
    (const uint8_t *)"GN",
    (const uint8_t *)"G1",
    (const uint8_t *)"G2",
    (const uint8_t *)"G3",
    (const uint8_t *)"G4",
    (const uint8_t *)"G5",
    (const uint8_t *)"GR"
};
static void init_config(void)
{
    init_clcd();
   init_adc();
   init_matrix_keypad();
   init_can();
    
  clcd_print("gear", LINE1(0));
  clcd_print("Speed", LINE1(9));
  
}
uint8_t speed_str[3];
uint8_t data[5];
int speed;
unsigned gear_ind;
 void speed_convert( )
 {
     speed_str[0]=(speed /10)+'0';
     speed_str[1]=(speed %10)+'0';
     speed_str[2]='\0';
     
 }
 void get_speed()
 {
     speed=((unsigned long )read_adc(CHANNEL4)*99)/1023;
      speed_convert();
        clcd_print(speed_str,LINE2(0));  
     
    // can_transmit(SPEED_MSG_ID,speed_str, 2);
 }
 void  get_gear()
 {
     int key=read_switches(STATE_CHANGE);
           if(key==MK_SW1)
           {
               
               if(gear_ind<7)
               {
                   gear_ind++;
               }
           }else if( key==MK_SW2)
           {
               if(gear_ind>1)
               {
                   gear_ind--;
               }
           }
 clcd_print(gear[gear_ind],LINE2(0));
     
    //can_transmit(GEAR_MSG_ID,gear[gear_ind], 2);
 }
void main(void)
{
    init_config();
    
    uint16_t msg_id;
    
    uint8_t len=0;
     
     
    while (1)
    {
        
        
        //can_transmit(ENG_TEMP_MSG_ID, "working", 7);
        get_speed();
       get_gear();
        can_receive(&msg_id, data, &len);
        
       if(len>0 && msg_id==SPEED_MSG_ID)
       {
           
          clcd_print((const char *)speed_str,LINE2(9));
          
        }else if(len>0 && msg_id==GEAR_MSG_ID)
       {
           
          clcd_print((const char *)gear[gear_ind],LINE2(0));
                 
        }     
    }
}