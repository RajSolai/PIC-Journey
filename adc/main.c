#include <xc.h>

#define _XTAL_FREQ 12000000

#pragma config FOSC = HS        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // code protection is turned off
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)

void main(){
	// configure portb
	TRISB5 = 0;
	RB5 = 0;
	// configure the adcon0 register
	ADCON0bits.ADCS = 0b01;
	ADCON0bits.CHS = 0b000;
	ADCON0bits.ADON = 1;
	// configure the adcon1 register
	ADCON1bits.PCFG = 0b000;

	while(1){
		ADCON0bits.GO = 1;
		while(ADCON0bits.GO == 1);
		short res = ADRES;

		for(int i=0;i<res;i++){
			RB5 = 1;	
		}
	}
}

