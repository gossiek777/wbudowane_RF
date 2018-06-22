#include "avr_compiler.h"
#include "avr/sleep.h"
#include "led.h"
#include "rf.h"

#define BOOT_BUTT_bm		3
#define TRANSCIEVER_INT_PIN	2

unsigned char ucMessage = 0;

ISR(PORTC_INT0_vect){ // interrupt service routine 
	rf_clear_int_flags();
	led_toggle();
	rf_send_byte(ucMessage++);
};

int main (void){
	led_init();

	PORTC.DIRCLR = (1<<TRANSCIEVER_INT_PIN);  //set as input pin
	PORTC.PIN2CTRL=  PORT_ISC_FALLING_gc;
	PORTC.INT0MASK=(1<<TRANSCIEVER_INT_PIN); 
	PORTC.INTCTRL= PORT_INT0LVL_LO_gc; 
	PMIC.CTRL=PMIC_LOLVLEN_bm;	
	sei(); // global interrupts enabling

	rf_init_as_tx();
	rf_clear_int_flags();
	rf_send_byte(ucMessage++);
	while(1) {
	}
}

//pobór pr¹du: 
//pkt 4:	ok 2.4 mA gdy Led nie œwieci (z zaœwieconym ledem ok 3mA)
//pkt 5:	ok 1.9 mA gdy Led nie œwieci (z zaœwieconym ledem ok 2.5mA)
