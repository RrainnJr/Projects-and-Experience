/*
#include <stdio.h>
#include <system.h>
#include <alt_types.h>
#include "altera_avalon_pio_regs.h"
#include <stdio.h>
#include <sys/alt_irq.h>
#include <altera_avalon_timer_regs.h>

void init_timer_interrupt ();
static void timer_isr(void* context, alt_u32 id);
int Time = 0;

void key3_isr(){
	// 1 second Timer
	Time = 0;
	printf("Key 3 Int");
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key2_isr(){
	// .5 Second Timer
	Time = 1;

	printf("Key 2 Int");
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key1_isr(){
	//.125 s Timer
	Time = 2;
	printf("Key 1 Int");
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key0_isr(){
	//Start/Stop
	printf("Key 0 Int");
	int Status = IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE);
	if (Status != 0){
		IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b1011);
	}
	else if (Status == 0){
		IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b0111);
	}

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void handle_key_interrupts(void* context){
	volatile int *edge_capture_ptr = (volatile int*) context;
	*edge_capture_ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	if (*edge_capture_ptr & 0x8){
		key3_isr();
	}
	else if (*edge_capture_ptr & 0x4){
		key2_isr();
		}
	else if (*edge_capture_ptr & 0x2){
		key1_isr();
	}
	else if (*edge_capture_ptr & 0x1){
		key0_isr();
	}
	return;
}

void pio_init(){
	void* edge_capture_ptr = KEYS_EDGE_TYPE;
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0xF);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0x0);
	alt_irq_register(KEYS_IRQ, edge_capture_ptr, handle_key_interrupts);

	return;
	}


void init_timer_interrupt (){
	//Register ISR
	alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ, (void *)timer_isr, NULL, 0x0);
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, ALTERA_AVALON_TIMER_CONTROL_CONT_MSK
													| ALTERA_AVALON_TIMER_CONTROL_START_MSK
													| ALTERA_AVALON_TIMER_CONTROL_ITO_MSK);
}

static void timer_isr(void* context, alt_u32 id){
	static int count = 0;
	static int LR = 0;

	//clear interrupt
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
	//Do something
	int LED = IORD(RED_LEDS_BASE, 0);;
	if (LED == 1)LR = 0;
	if (LED == 131072) LR =1;
	switch(Time){
		case 0:
			if (count % 1000 == 0){
				if (LR == 0)LED = LED * 2;
				else LED = LED / 2;
			}
			break;
		case 1:
			if (count % 500 == 0){
				if (LR == 0)LED = LED * 2;
				else LED = LED / 2;
			}

			break;
		case 2:
			if (count % 125 == 0){
				if (LR == 0)LED = LED * 2;
				else LED = LED / 2;
			}
			break;
		default:

			break;
	}
	IOWR(RED_LEDS_BASE, 0, LED);
	//Timer Expires
	count ++;
	return;
}

int main(){
	init_timer_interrupt();
	pio_init();
	IOWR(RED_LEDS_BASE, 0, 1);
	while(1){

	}
  return 0;
}
*/
