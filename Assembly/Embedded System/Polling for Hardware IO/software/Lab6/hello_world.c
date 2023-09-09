// Program for Generating an Interrupt
/*
#include <stdio.h>
#include <system.h>
#include <alt_types.h>
#include "altera_avalon_pio_regs.h"
#include <stdio.h>


void incr(){
	int LEDVal = 0;
	LEDVal = IORD(GREEN_LEDS_BASE, 0);

	for (int i = LEDVal; i <= 9; i++){
		IOWR(GREEN_LEDS_BASE, 0, i);
		delayfn();
	}
	return;
}

void decr(){
	int LEDVal = 0;
		LEDVal = IORD(GREEN_LEDS_BASE, 0);

		for (int i = LEDVal; i >= 1; i--){
			IOWR(GREEN_LEDS_BASE, 0, i);
			delayfn();
		}
		return;
}

void delayfn(){
	int delay = 0;
		while(delay < 2000000)
		{
			delay++;
		}
}



void key3_isr(){
	// Program
	int Sw0 = 0;
		Sw0 = IORD(SWITCHES_BASE, 0);

	if (Sw0 == 0){
		decr();
	}
	else if (Sw0 == 1){
		incr();
	}

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key2_isr(){
	// Program
	IOWR(GREEN_LEDS_BASE, 0, 0x1);

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
	return;
}

void pio_init(){
	void* edge_capture_ptr = KEYS_EDGE_TYPE;
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0xC);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0x0);
	alt_irq_register(KEYS_IRQ, edge_capture_ptr, handle_key_interrupts);

	return;
	}

int main(){
	pio_init();
	printf("Key3: \n     Sw0 High: Increment to 9\n     Sw0 Low: Decrement to 1\nKey2: Set to 1\n");
	IOWR(GREEN_LEDS_BASE, 0, 0b00001010);
	while(1){

	}
  return 0;
}

*/
