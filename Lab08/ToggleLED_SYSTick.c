
#include <LPC11xx.h>

int main (void)
{

	SysTick->LOAD = 12000000/2;
	SysTick->CTRL = 0b101; //enable and clksource

	LPC_GPIO2->DIR = 1;
	LPC_GPIO2->DATA = 0;
	while(1){
		if(SysTick->CTRL & (1 << 16)){ //overflow flag
			LPC_GPIO2->DATA ^= 1;
			SysTick->CTRL = 0;
			SysTick->CTRL = 0b101;
		}
		
	}


	return 0;
}   
