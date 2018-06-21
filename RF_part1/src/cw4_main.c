#include "avr_compiler.h"
#include "led.h"

#define BOOT_BUTTON_bm	1<<3
#define PIN_OPC_bm		0x18
#define PIN_ISC_bm		0x02


ISR(PORTC_INT0_vect){ // interrupt service routine led_toggle();
};

int main (void){
	led_init();
	PORTC.DIR= ~BOOT_BUTTON_bm;//trzeba wyzerowa�, tylko kt�ry niby bit w tym porcie?!
	PORTC.PIN3CTRL= PIN_OPC_bm | PIN_ISC_bm;
	PORTC.INT0MASK= BOOT_BUTTON_bm;
	PORTC.INTCTRL=
	PMIC.CTRL=
	sei(); // global interrupts enabling
	while(1) {};
}


/* 	? ustawi� pin do kt�rego pod��czony jest przycisk na:
		? wej�ciowy
		? z podci�ganiem do "g�ry" i wra�liwy na zbocze opadaj�ce
	? ustawi� mask� okre�laj�c� piny mog�ce generowa� przerwanie INT0 portu X na odpowiedni pin
	? w��czy� przerwanie INT0 portu X
*/