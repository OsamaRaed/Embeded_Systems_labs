#include <LPC11xx.h>

void delay(int c){
	for(int i = 0;i < c * 7000;i++);
}

int Advertising_LED_matrix[8][30] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,0,0},
	{0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1,1,1,0,0},
	{0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0},
	{0,0,1,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};



void setup_SPI0(){
	LPC_IOCON->PIO0_2 = 0x1;
	LPC_IOCON->PIO0_9 = 0x1; 
	LPC_IOCON->JTAG_TCK_PIO0_10 = 0x2; 
	LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 11; 
	LPC_SYSCON->SSP0CLKDIV = 0x1; 
	LPC_SYSCON->PRESETCTRL = 0x1; 
	LPC_SSP0->CR0 = 0x7;        
	LPC_SSP0->CPSR = 0x2; 
	LPC_SSP0->CR1 = 0x2;
	
}
void Write_Data(uint16_t x){
	LPC_SSP0->DR = x;
	while((LPC_SSP0->SR & 1) == 0);
}
void display_colour(int r,int g, int b){
	Write_Data(0xFF);
	Write_Data(b);
	Write_Data(g);
	Write_Data(r);
}
void start(){
	Write_Data(0);
	Write_Data(0);
	Write_Data(0);
	Write_Data(0);
}

void display(int option){
	int count = 0;
	while(1){	
		start();
		for(int i = 0;i<8;i++){
			for(int j = 0;j < 30;j++){
				if((option == 0 && Advertising_LED_matrix[i][j] == 0)
					|| (option == 1 && Advertising_LED_matrix[i][(j + count) % 30] == 0)
					|| (option == 2 && Advertising_LED_matrix[(i + count) % 8][j] == 0)
					|| (option == 3 && Advertising_LED_matrix[(i + count) % 8][(j + count) % 30] == 0))
				{
					display_colour(50,50,50);
				} 
				else display_colour(175,255,0);
			}
		}
		count = (count + 1) % 30;
		delay(5);
	}
}
int main(){
	setup_SPI0();
	start();
	display(3);
	while (1);
	return 0;
 }   
