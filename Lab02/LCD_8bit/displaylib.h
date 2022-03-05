

#define LCD_CMD (*((volatile unsigned long *)0x50003FFC))
#define LCD_DATA (*((volatile unsigned long *)0x50023FFC))

#define LCD_RS 0b10
#define LCD_E 0b100


void send_cmd (unsigned int cmd);
void send_char (char c);
void send_str(char * str );
void setup();
