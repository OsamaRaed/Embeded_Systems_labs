 

#define SYSPLLCLKSEL (* ((volatile unsigned long *) 0x40048040))
#define MAINCLKSEL (* ((volatile unsigned long *) 0x40048070))

#define CLKOUTCLKSEL (* ((volatile unsigned long *) 0x400480E0))
#define CLKCLKUEN (* ((volatile unsigned long *) 0x400480E4))
#define CLKOUTCLKDIV (* ((volatile unsigned long *) 0x400480E8))

#define IOCON_PIOG0_1 (* ((volatile unsigned long *) 0x40044010))


#define IOCON_PIOG0_6 (* ((volatile unsigned long *) 0x400440A4))
#define IOCON_PIOG0_7 (* ((volatile unsigned long *) 0x400440A8))


#define SYSAHBCLKCTRL (* ((volatile unsigned long *) 0x40048080))
#define UARTCLKDIV (* ((volatile unsigned long *) 0x40048098))

#define U0LCR (* ((volatile unsigned long *) 0x4000800C))

#define U0DLL (* ((volatile unsigned long *) 0x40008000))
#define U0DLM (* ((volatile unsigned long *) 0x40008004))
#define U0FDR  (* ((volatile unsigned long *) 0x40008028))

#define U0THR  (* ((volatile unsigned long *) 0x40008000))

void send_string (char* string);

int main(void)
{
    CLKOUTCLKSEL = 0x3;
    CLKCLKUEN = 0;
    CLKCLKUEN = 1;
    CLKOUTCLKDIV = 1;
    IOCON_PIOG0_1 = 1;

    IOCON_PIOG0_6  = 1;
    IOCON_PIOG0_7 = 1;
    SYSAHBCLKCTRL |= 1 << 12;

    U0LCR |= 1 << 7 | 3;
    U0DLL = 4;
    U0DLM = 0;
    U0FDR = 5 | (8 << 4);
    UARTCLKDIV = 1;

    U0LCR &= ~(1 << 7);
    U0THR = 'H';
    U0THR = 'E';
    U0THR = 'L';
    U0THR = 'L';
    U0THR = 'O';
    while (1);

    return 0;
}


void send_string (char* string){
	while (*string != 0){
		  U0THR  = *string;
		  string++ ;
	}
}

