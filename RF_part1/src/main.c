#include "avr_compiler.h"
#include "led.h"

#define BOOT_BUTT_bm	3

ISR(PORTC_INT0_vect){ // interrupt service routine 
	led_toggle();
};

int main (void){
	led_init();

	PORTC.DIR = 0;  //input port
	PORTC.PIN3CTRL= (1<<1) | (1<<3) | (1<<4); //OPC = 011 ISC = 010
	PORTC.INT0MASK=(1<<BOOT_BUTT_bm); 
	PORTC.INTCTRL= (1<<0); //Low-level interrupt
	PMIC.CTRL=(1<<0);	//Low-level Interrupt Enable
	sei(); // global interrupts enabling

	while(1) {};
}
//pob�r pr�du: ok 2,4 mA gdy Led nie �wieci (z za�wieconym ledem ok 3mA)