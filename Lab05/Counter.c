

#define GPIO3DIR (*((volatile unsigned long *)0x50038000))
#define GPIO3DATA (*((volatile unsigned long *)0x50033FFC))


#define GPIO2DIR (*((volatile unsigned long *)0x50028000))
#define GPIO2DATA (*((volatile unsigned long *)0x50023FFC))


const unsigned char digitPattern[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};



void delay(int c){
    c = 43 * c / 10;
    for ( int i = 0; i < c ;i++);
}



 void display(int i, int j){
    for (int k = 0;k < 100;k++){
         if( k % 2 == 0){
	    GPIO3DATA |= 0b001;
	    GPIO3DATA &= 0b001;
	    GPIO2DATA = digitPattern[j];
	    delay(100);

	 } else {
	    GPIO3DATA |= 0b100;
	    GPIO3DATA &= 0b100;
	    GPIO2DATA = digitPattern[i];
	    delay(100);
	 }
    }
 }

int main (void)
 { 
    
    GPIO2DIR |= 0xFF;
    GPIO3DIR |= 0b101;
    
    
    for(int i = 0;i < 10;i++){
       for(int j = 0;j < 10;j++){
	     display(9,9);       
       }
    }
    
   return 0;
 }   
 
 

 
 
