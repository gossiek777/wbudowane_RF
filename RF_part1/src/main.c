#include "led.h"
#include "rf.h"
#include "avr_compiler.h"

int main (void){
	
	led_init();
	rf_init_as_tx();
	
	while(1) {
		static unsigned char ucMsgCtr=0;
		//led_toggle();
		led_set();
		rf_send_byte(ucMsgCtr++);
		led_clear();
		//led_toggle();
		rf_wait_until_data_sent();
	}
}