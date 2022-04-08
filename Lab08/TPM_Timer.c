

#include <LPC11xx.h>

void toggle(int delayMs){

	if(LPC_TMR16B0->TC >= delayMs){// 1000 is a second 
		LPC_GPIO2->DATA ^= 1;
		LPC_TMR16B0->TCR = 0b11; 
		LPC_TMR16B0->TCR = 1;
	}

}
int main (void)
{

	SysTick->LOAD = 12000000/2;
	SysTick->CTRL = 0b101; //enable and clksource

	LPC_GPIO2->DIR = 1;
	LPC_GPIO2->DATA = 0;
	LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 7;
	LPC_TMR16B0->PR = 12000 - 1; //TC++ evey 0.001 second 
	LPC_TMR16B0->TCR = 0b11; //enable and reset
	LPC_TMR16B0->TCR = 1;
	while(1){
		toggle(1000);
	}


	return 0;
}    
