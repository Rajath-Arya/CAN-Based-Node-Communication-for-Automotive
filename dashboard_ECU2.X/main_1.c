#include <xc.h>
#include "dkps.h"
#include "ssd_display.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "clcd.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
void init_config(void)
{
	init_ssd_control();
    init_adc( );
    //initdkps();
    init_can();
    init_clcd();
    
    
    clcd_print("RPM", LINE1(0));
    clcd_print("INDICATOR",LINE1(7));
   //TRISB=0x00;
    //PORTB=0x00;
}
uint8_t data[5];
uint8_t rpm_str[5];
void convert_rpm(unsigned rpm)
{
    rpm_str[0]=(rpm/1000)+'0';
    rpm_str[1]=((rpm/100)%10)+'0';
    rpm_str[2]=((rpm/10)%10)+'0';
    rpm_str[3]=(rpm %10)+'0';
    rpm_str[4]='\0';
}
 void get_rpm()
 {
    unsigned  RPM= ((unsigned long)read_adc(CHANNEL4)*6000)/1023;
        
//   		ssd[0] = digit[RPM/1000];
//   		ssd[1] = digit[(RPM /100)%10];
//   		ssd[2] = digit[(RPM /10)%10];
//   		ssd[3] = digit[RPM%10];
//        
//		display(ssd); 
    //convert_rpm(RPM);
        //can_transmit(RPM_MSG_ID, rpm_str, 4);
        
        //can_receive(&msg_id, data, &len);
        
//        if(len>=4 && msg_id==RPM_MSG_ID)
//        {
//             clcd_putch(data[0] ,LINE2(0));
//             clcd_putch(data[1],LINE2(1));
//             clcd_putch(data[2] ,LINE2(2));
//              clcd_putch(data[3],LINE2(3)); 
//        }
 }

void main(void)
{
	init_config();
	int key;
     
    int left_indicator=1;
    int right_indicator=0;
    unsigned int delay=0;
    uint16_t msg_id;
    
    uint8_t len=0;
	while(1)
	{
        
        RPM= ((unsigned long)read_adc(CHANNEL4)*6000)/1023;
        
   		ssd[0] = digit[RPM/1000];
   		ssd[1] = digit[(RPM /100)%10];
   		ssd[2] = digit[(RPM /10)%10];
   		ssd[3] = digit[RPM%10];
        
		display(ssd);
        key=dkps(EDGE);
        if(key== SW1)
        {
            left_indicator=1;
            right_indicator=0;
            delay=0;
        }else if(key== SW2)
        {
            left_indicator=0;
            right_indicator=1;
            delay=0;
        }else if( key== SW3)
        {
            left_indicator=0;
            right_indicator=0;
            PORTB=0x00;
            
            delay=0;
        }
        
        if(left_indicator)
        {
            if(++delay<=5000)
            {
                PORTB=0x03;
            }else if(delay<=10000)
            {
                PORTB=0x00;
            }else {
                delay=0;
            }
        }
        if(right_indicator)
        {
            if(++delay<=5000)
            {
                PORTB=0xC0;
            }else if(delay<=10000)
            {
                PORTB=0x00;
            }else {
                delay=0;
            }
        }
        //convert_rpm(RPM);
        //can_transmit(RPM_MSG_ID, rpm_str, 4);
        
        //can_receive(&msg_id, data, &len);
        
//        if(len>=4 && msg_id==RPM_MSG_ID)
//        {
//             clcd_putch(data[0] ,LINE2(0));
//             clcd_putch(data[1],LINE2(1));
//             clcd_putch(data[2] ,LINE2(2));
//              clcd_putch(data[3],LINE2(3)); 
//        }
//        if(left_indicator)
//        {
//               can_transmit(INDICATOR_MSG_ID,"<----", 5);
//        }else if(right_indicator)
//        {
//               can_transmit(INDICATOR_MSG_ID,"---->", 5);
//        }else 
//        {
//            can_transmit(INDICATOR_MSG_ID,"     ", 5);
//        }
//        can_receive(&msg_id, data, &len);
//        
//        if(len>=5 && msg_id== INDICATOR_MSG_ID)
//        {
//            clcd_putch(data[0] ,LINE2(10));
//             clcd_putch(data[1],LINE2(11));
//             clcd_putch(data[2] ,LINE2(12));
//              clcd_putch(data[3],LINE2(13)); 
//              clcd_putch(data[4],LINE2(14));      
//        }
            
        get_rpm();
	}
}