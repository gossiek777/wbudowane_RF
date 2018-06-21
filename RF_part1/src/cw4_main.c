#include "avr_compiler.h"
#include "led.h"

#define BOOT_BUTTON_bm	1<<3
#define PIN_OPC_bm		0x18
#define PIN_ISC_bm		0x02


ISR(PORTC_INT0_vect){ // interrupt service routine led_toggle();
};

int main (void){
	led_init();
	PORTC.DIR= ~BOOT_BUTTON_bm;//trzeba wyzerowaæ, tylko który niby bit w tym porcie?!
	PORTC.PIN3CTRL= PIN_OPC_bm | PIN_ISC_bm;
	PORTC.INT0MASK= BOOT_BUTTON_bm;
	PORTC.INTCTRL=
	PMIC.CTRL=
	sei(); // global interrupts enabling
	while(1) {};
}


/* 	? ustawiæ pin do którego pod³¹czony jest przycisk na:
		? wejœciowy
		? z podci¹ganiem do "góry" i wra¿liwy na zbocze opadaj¹ce
	? ustawiæ maskê okreœlaj¹c¹ piny mog¹ce generowaæ przerwanie INT0 portu X na odpowiedni pin
	? w³¹czyæ przerwanie INT0 portu X
*/