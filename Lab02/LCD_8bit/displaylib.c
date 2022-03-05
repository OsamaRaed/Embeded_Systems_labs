

#include "displaylib.h"


void delay(int c){
    c = 43 * c / 10;
    for ( int i = 0; i < c ;i++);
}



void send_cmd (unsigned int cmd){
    LCD_CMD = 0;
    LCD_DATA = cmd;
    LCD_CMD = LCD_E;
    delay(1);
    LCD_CMD = 0b000;
    delay(37);
}

void send_char (char c){
    LCD_CMD = LCD_RS;
    LCD_DATA = c;
    LCD_CMD = LCD_RS | LCD_E;
    delay(1);
    LCD_CMD = LCD_RS;
    delay(37);
}

void send_str(char * str ){
   while( *str != '\0' ){
      send_char(* str );
      str++;
   }
}

void setup(){
   
    delay(15000);
    send_cmd(0x30);
    delay(4100);
    send_cmd(0x30);
    delay(100);
    send_cmd(0x30);
    send_cmd(0x38);
    send_cmd(0x0F);
    send_cmd(0x01);
    delay(1600);
    send_cmd(0x06);
   
   

   
}
