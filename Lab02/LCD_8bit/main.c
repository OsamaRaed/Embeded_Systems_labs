/* Main.c file generated by New Project wizard
 *
 * Created:   Fri Mar 4 2022
 * Processor: LPC1114FBD48/301
 * Compiler:  GCC for ARM
 */


#include "displaylib.h"


#define GPIO0DIR (*((volatile unsigned long *)0x50008000))
#define GPIO0DATA (*((volatile unsigned long *)0x50003FFC))


#define GPIO2DIR (*((volatile unsigned long *)0x50028000))
#define GPIO2DATA (*((volatile unsigned long *)0x50023FFC))

void delay1(int c){
    c = 43 * c / 10;
    for ( int i = 0; i < c ;i++);
}


int main (void)
{ 
      // Write your code here
    GPIO2DIR |= 0b11111111;
    GPIO0DIR |= 0b110;
    LCD_CMD = 0;
    LCD_DATA = 0;
    
    delay1(15000);
    send_cmd(0b00110000);
    delay1(4100);
    send_cmd(0b00110000);
    delay1( 100);
    send_cmd(0b00110000);
    send_cmd(0x38);
    send_cmd(0x0F); // display on/off  - cursor - cursor blinking
    send_cmd(0x01); //clear display
    delay1( 1600); 
    send_cmd(0x06); //entity mode set => cursor direction
     

   
   
    //send_str("120181499");


      while (1){
	 if(LCD_CMD & 0b1000){
	     send_cmd(0x01); //clear display
	     delay1( 1600); 
	    
	    send_str("OSAMA");

	     while(LCD_CMD & 0b1000);
	   }
  
	   if(LCD_CMD & 0b1000){
	     send_cmd(0x01); //clear display
	     delay1( 1600); 
	      send_str("120181499");

	      while(LCD_CMD & 0b1000);
	   }
	    
     }
    return 0;
}   