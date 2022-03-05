

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
    LCD_DATA = 3;
    LCD_CMD = LCD_RS | LCD_E;
    delay(1);
    LCD_CMD = LCD_RS;
    delay(37);
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
     delay(1000);
    send_cmd(0b0011);
    delay(4100);
    send_cmd(0b0011);
    delay(100);
    send_cmd(0b0011);
    delay(100);
    send_cmd(0b0010);
    delay(100);
    send_cmd(0b0010);
    send_cmd(0b1111);
    delay(37);
    send_cmd(0b0000);
    send_cmd(0b1000);
    delay(37);
    send_cmd(0b0000);
    send_cmd(0b0001);
    delay(3000);
    send_cmd(0b0000);
    send_cmd(0b0110);
    delay(37);
    send_cmd(0b0000);
    send_cmd(0b1111);
     delay(37);
}
