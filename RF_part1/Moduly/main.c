// ########## RX pooling !!! wymaga do?aczenia rf_full#############

//#define F_CPU 32000000UL
//#include "avr_compiler.h"
//
//#include <avr/sleep.h>
//#include "rf_full.h"
//#include "led.h"
//#include "usart.h"
//#include <stdio.h>
//
//#define USART USARTD0
//
//char tx_string[30];
//
//int main(void)
//{
	//// 32MHz
	//OSC.CTRL |= OSC_RC32MEN_bm | OSC_RC32KEN_bm;  /* Enable the internal 32MHz & 32KHz oscillators */
	//while(!(OSC.STATUS & OSC_RC32KRDY_bm));       /* Wait for 32Khz oscillator to stabilize */
	//while(!(OSC.STATUS & OSC_RC32MRDY_bm));       /* Wait for 32MHz oscillator to stabilize */
	//DFLLRC32M.CTRL = DFLL_ENABLE_bm ;             /* Enable DFLL - defaults to calibrate against internal 32Khz clock */
	//CCP = CCP_IOREG_gc;                           /* Disable register security for clock update */
	//CLK.CTRL = CLK_SCLKSEL_RC32M_gc;              /* Switch to 32MHz clock */
	//OSC.CTRL &= ~OSC_RC2MEN_bm;                   /* Disable 2Mhz oscillator */
//
	//// usart init
	//PORTD.DIRSET = PIN3_bm;
	//PORTD.DIRCLR = PIN2_bm;
	//USART_Format_Set(&USART, USART_CHSIZE_8BIT_gc, USART_PMODE_DISABLED_gc, false);
	//USART_Baudrate_Set(&USART, 428 , -7); //9600, Baudrate select = (1/(16*(((I/O clock frequency)/Baudrate)-1)
	//USART_Tx_Enable(&USART);
	//
	//led_init();
	//rf_init_as_rx();
	//while(1)
	//{
		//
		//rf_wait_until_data_received();
		//sprintf(tx_string,"%02x\r",rf_get_byte());
		//led_toggle();
		//
		//for(char ctr = 0;tx_string[ctr]!=0;ctr++){
			//while(!USART_IsTXDataRegisterEmpty(&USART));
			//USART_PutChar(&USART, tx_string[ctr]);
		//}
	//}
//}
 
 ////##### Interrupts+LED+Sleep(IDDLE)
//#include "avr_compiler.h"
//#include <avr/sleep.h>
//#include "led.h"
//
//ISR(PORTC_INT0_vect){
	//led_toggle();
//};
//
//int main (void){
//
	//led_init();
	//
	//PORTC.DIR &= ~(1<<3);
	//PORTC.PIN3CTRL	= PORT_OPC_PULLUP_gc | PORT_ISC_FALLING_gc;
	//PORTC.INT0MASK |= 1<<3;
	//PORTC.INTCTRL	= PORT_INT0LVL_LO_gc;
	//PMIC.CTRL|=PMIC_LOLVLEN_bm;
	//
	//sei();
	//
	//set_sleep_mode(SLEEP_MODE_IDLE);
	//sleep_enable();
	//
	//while(1) {
		//sleep_cpu();
	//};
//}

//// ########## TX pooling #############
//#include "avr_compiler.h"
//#include "rf.h"
//#include "led.h"
//#include "usart.h"
//
//int main(void)
//{
	//unsigned char ucMsgCtr=0;
	//led_init();
	//rf_init_as_tx();
	//while(1)
	//{
		//rf_send_byte(ucMsgCtr++);
		//rf_wait_until_data_sent();
		//led_toggle();
	//}
//}

//// ########## TX on interrupts + sleep #############
//
//#include "avr_compiler.h"
//#include <avr/sleep.h>
//#include "rf_full.h"
//#include "led.h"
//
//unsigned char ucMsgCtr=0;
//
//ISR(PORTC_INT0_vect){
	//rf_clear_int_flags();
	//rf_send_byte(ucMsgCtr++);
	//led_toggle();
//};
//
//int main (void){
//
	//led_init();
//
	//PORTC.DIR &= ~(1<<2);
	//PORTC.PIN2CTRL	= PORT_OPC_PULLUP_gc | PORT_ISC_FALLING_gc;
	//PORTC.INT0MASK |= 1<<2;
	//PORTC.INTCTRL	= PORT_INT0LVL_HI_gc;
	//PMIC.CTRL|=PMIC_HILVLEN_bm;
//
	//sei();
//
	//set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	//sleep_enable();
//
	//rf_init_as_tx();
//
	//rf_clear_int_flags();
	//rf_send_byte(ucMsgCtr++);
//
	//while(1) {
		//sleep_cpu();
	//};
//}

//// ### RTC+LED, ok. 13.mA
////// !!! koniecznie wz wypietymi modulamia
//#include "avr_compiler.h"
//#include "led.h"
//
//ISR(RTC_OVF_vect) {
	//led_set();
//}
//
//ISR(RTC_COMP_vect) {
	//led_clear();
//}
//
//int main (void) {
	//led_init();
//
	//// RTC init
	//RTC.PER = 1000;
	//RTC.CNT = 0;
	//RTC.COMP = 50;
	//RTC.CTRL = ( RTC.CTRL & ~RTC_PRESCALER_gm ) | RTC_PRESCALER_DIV1_gc;
	//RTC.INTCTRL = ( RTC.INTCTRL & ~( RTC_COMPINTLVL_gm | RTC_OVFINTLVL_gm ) ) | RTC_COMPINTLVL_LO_gc | RTC_OVFINTLVL_LO_gc ;
	//CLK.RTCCTRL = CLK_RTCSRC_ULP_gc | CLK_RTCEN_bm;
//
	//// interrupts init
	//PMIC.CTRL |= PMIC_LOLVLEN_bm;
	//sei();
//
	//while(1){
	//}
//}

//// ### RTC+SLEEP+LED, max 70uA
//// !!! koniecznie wz wypietymi modulamia
//#include "avr_compiler.h"
//#include <avr/sleep.h>
//#include "led.h"
//
//ISR(RTC_OVF_vect) {
	//led_set();
//}
//
//ISR(RTC_COMP_vect) {
	//led_clear();
//}
//
//int main (void) {
	//led_init();
	//
	//// RTC init
	//RTC.PER = 1000;
	//RTC.CNT = 0;
	//RTC.COMP = 50;
	//RTC.CTRL = ( RTC.CTRL & ~RTC_PRESCALER_gm ) | RTC_PRESCALER_DIV1_gc;
	//RTC.INTCTRL = ( RTC.INTCTRL & ~( RTC_COMPINTLVL_gm | RTC_OVFINTLVL_gm ) ) | RTC_COMPINTLVL_LO_gc | RTC_OVFINTLVL_LO_gc ;
	//CLK.RTCCTRL = CLK_RTCSRC_ULP_gc | CLK_RTCEN_bm;
	//
	//// interrupts init
	//PMIC.CTRL |= PMIC_LOLVLEN_bm;
//
	//// sleep mode init
	//set_sleep_mode(SLEEP_MODE_PWR_SAVE);
	//sleep_enable();
	//
	//sei();
	//
	//while(1){
		//sleep_cpu();
	//}
//}

// ### RTC+SLEEP+RF+ACC, 1Hz- 50uA, 10Hz-80uA
#include "avr_compiler.h"
#include <avr/sleep.h>
#include "rf_full.h"
#include "led.h"
#include "acc.h"

unsigned char ucMsgCtr=0;

ISR(RTC_OVF_vect) {
	char acc=acc_read();
	rf_send_byte(acc);//ucMsgCtr++);//
	led_toggle();
}

ISR(RTC_COMP_vect) { }

int main (void) {
	led_init();
	rf_init_as_tx();
	acc_init();

	RTC.PER = 50;
	RTC.CNT = 0;
	RTC.COMP = 1;
	RTC.CTRL = ( RTC.CTRL & ~RTC_PRESCALER_gm ) | RTC_PRESCALER_DIV1_gc;
	RTC.INTCTRL = ( RTC.INTCTRL & ~( RTC_COMPINTLVL_gm | RTC_OVFINTLVL_gm ) ) | RTC_COMPINTLVL_LO_gc | RTC_OVFINTLVL_LO_gc ;
	CLK.RTCCTRL = CLK_RTCSRC_ULP_gc | CLK_RTCEN_bm;

	// interrupts init
	PMIC.CTRL |= PMIC_LOLVLEN_bm;

	set_sleep_mode(SLEEP_MODE_PWR_SAVE);
	sleep_enable();

	sei();

	while(1){
		sleep_cpu();
	}
}

