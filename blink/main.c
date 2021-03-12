#include <xc.h>

#define _XTAL_FREQ 12000000

#pragma config FOSC = HS        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // code protection is turned off
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)

void main(){
	TRISB = 0x00;
	PORTB = 0x00;
	while(1){
		RB2 = 1;
		__delay_ms(400);
		RB2 = 0;
		__delay_ms(400);
	}
	return;
}
