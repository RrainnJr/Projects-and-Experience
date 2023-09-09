#include <stdio.h>
#include <system.h>
#include <alt_types.h>
#include "altera_avalon_pio_regs.h"
#include <stdio.h>
#include <sys/alt_irq.h>
#include <altera_avalon_timer_regs.h>

void init_timer_interrupt ();
static void timer_isr(void* context, alt_u32 id);
void display(int Value);
int Time = 0;
int Score = 0;


void key3_isr(){
	// 1 second Timer
	Time = 0;
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key2_isr(){
	// .5 Second Timer
	Time = 1;

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key1_isr(){
	//.125 s Timer
	Time = 2;
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key0_isr(){
	//Start/Stop
	int SwVal = IORD(SWITCHES_BASE, 0);
	int Status = IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE);
	if (Status != 0){
		IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b1011);
		if (SwVal == IORD(RED_LEDS_BASE, 0)) {
			Score++;
			if (Score > 16){
				Score = 0;
			}
		}
		else Score = 0;
		display(Score);
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
	int LED = IORD(RED_LEDS_BASE, 0);
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
	IOWR(SEVSEGMENT_4LSB_BASE, 0, 0xFFFFFFFF);
	IOWR(SEVSEG4MSB_BASE, 0, 0xFFFFFFFF);
	while(1){

	}
  return 0;
}

void display(int Value){
	int SEVENSEGLUT[16] = {0b01000000, 0b01111001, 0b00100100, 0b00110000, 0b00011001, 0b00010010, 0b00000010, 0b01111000, 0b10000000, 0b00010000, 0b00001000, 0b00000011, 0b01000110 ,0b00100001, 0b00000110, 0b00001110};
	int toDisplay = 0;
	int shiftVal = 0;
	if (Value == 0){
		toDisplay = SEVENSEGLUT[Value];
	}

	while (Value != 0){ //Displays the value on the Hex Masks are for 0 values to not be displayed unless the LSB
	toDisplay = toDisplay + (SEVENSEGLUT[Value] << shiftVal);
	Value = 0;
	shiftVal = shiftVal + 8;
	}
	toDisplay = toDisplay | 0xFFFFFF00;

	IOWR(SEVSEGMENT_4LSB_BASE, 0, toDisplay);
	return;
}
