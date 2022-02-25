/*
 *
 * Created:   Sat Feb 19 2022
 * Processor: LPC1114FBD48/301
 * Compiler:  GCC for ARM
 */

#include <LPC11xx.h>

#define GPIO2DIR (*((volatile unsigned long *)0x50028000))
#define GPIO2DATA (*((volatile unsigned long *)0x50023FFC))

void main () { 
    GPIO2DIR |= 0b10000;
    int i ;
     while (1){
        GPIO2DATA ^= 0b10000;

        for(i = 0 ; i<100000; i++);
     }
}
