
#include <LPC11xx.h>

void RGBDriver(int red, int green, int blue){

	LPC_TMR16B0->MR3 = 255;
	LPC_TMR16B0->MR0 = 255 - red;
	LPC_TMR16B0->MR1 = 255 - green;
	LPC_TMR16B0->MR2 = 255 - blue;
	LPC_TMR16B0->MCR = 1 << 10;
	LPC_TMR16B0->TCR = 0b11; //enable and reset
	LPC_TMR16B0->TCR = 1;

}


int main (void)
 { 

	LPC_GPIO2->DIR = 3;
	LPC_GPIO2->DATA = 0;
	LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 7;
	LPC_TMR16B0->PR = 12000 - 1; //TC++ evey 0.001 second 
	LPC_TMR16B0->PWMC = 0xF; 
	RGBDriver(1,255,255);
	LPC_IOCON->PIO0_8 = 2;
	LPC_IOCON->PIO0_9 = 2;	
	LPC_IOCON->JTAG_TCK_PIO0_10= 3;


	while(1);
	return 0;
 }   
