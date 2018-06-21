#include "led.h"
#include "rf.h"
#include "avr_compiler.h"

#define RF_CH_NUM_bm 12

int main (void){
		
	led_init();
	rf_init_as_tx();
	
	rf_set_output_channel(RF_CH_NUM_bm);
	
	while(1) { 
		static unsigned char ucMsgCtr=0;
		rf_send_byte(ucMsgCtr++);
		rf_wait_until_data_sent();
		led_toggle(); 
	}
}