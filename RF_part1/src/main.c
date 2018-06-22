#include "avr_compiler.h"
#include "avr/sleep.h"
#include "led.h"

#define BOOT_BUTT_bm	3

ISR(PORTC_INT0_vect){ // interrupt service routine 
	led_toggle();
};

int main (void){
	led_init();

	PORTC.DIR = 0;  //input port
	PORTC.PIN3CTRL= PORT_OPC_PULLUP_gc | PORT_ISC_FALLING_gc;
	PORTC.INT0MASK=(1<<BOOT_BUTT_bm); 
	PORTC.INTCTRL= PORT_INT0LVL_LO_gc; 
	PMIC.CTRL=PMIC_LOLVLEN_bm;	
	sei(); // global interrupts enabling

	while(1) {
	};
}
//pob�r pr�du: 
//pkt 4:	ok 2.4 mA gdy Led nie �wieci (z za�wieconym ledem ok 3mA)
