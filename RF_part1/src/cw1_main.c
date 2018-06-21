#include "led.h"
#include "rf.h"
#include "avr_compiler.h"

int main (void){
		
	led_init();
	rf_init_as_tx();
	
	while(1) { 
		static unsigned char ucMsgCtr=0;
		//delay_ms(200);
		delay_us(200000);
		rf_send_byte(ucMsgCtr++);
		led_toggle(); 
	}
}