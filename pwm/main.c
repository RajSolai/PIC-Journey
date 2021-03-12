#include <xc.h>

#define _XTAL_FREQ 12000000

#pragma config FOSC = HS        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // code protection is turned off
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)

void main(){
	TRISC2 = 0; // the ccp is set a out
	CCPR1L = 1; // cppr1low is set 1
	PR2 = 599; // period value
	T2CON = 0; // timer2 mode/control 
	CCP1CON = 0X0C; // cpp mode/control
	TMR2 = 0; // clear timer2
	TMR2ON = 1; // turn on timer2 

	for(int i = 0; i < 599; i++){
			CCPR1L = i;
			__delay_ms(200);
	}
}
