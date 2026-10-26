#include <xc.h>
#include "can_1.h"
#include "msg_id_1.h"
#include "clcd.h"

 
void init_config(void)
{
	 init_clcd();
    
    init_can();
    
    clcd_print("GR", LINE1(0));
    clcd_print("SP", LINE1(3));
    clcd_print("RPM", LINE1(6));
    clcd_print("indicator", LINE1(11));
    
}
uint8_t data[10];
 
void dispaly(int ind,uint8_t lenght)
{
    for(int i=0;i<lenght;i++)
    {
        clcd_putch((char)data[i],LINE2(ind+i));
        
    }
}
    
  
void main(void)
{
	init_config();
	 
    uint16_t msg_id;
    
    uint8_t len=0;
	while(1)
	{
        
        can_transmit(ENG_TEMP_MSG_ID, "working", 7);
        
        can_receive(&msg_id, data, &len);
        
        if(len>0 && msg_id==ENG_TEMP_MSG_ID)
        {
            clcd_print("working",LINE2(0));
        }
        
        if(len>0 && msg_id == SPEED_MSG_ID)
        {
            dispaly(3,len);
            
        }else if(len>0 && msg_id == GEAR_MSG_ID)
        {
            dispaly(0,len);
            
        }else if(len>0 && msg_id == RPM_MSG_ID)
        {
            dispaly(6,len);
            
        }else if(len>0 && msg_id == INDICATOR_MSG_ID)
        {
            dispaly(11,len);
            
        }
		 
	}
}