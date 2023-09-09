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
void display(int Value);

int main()
{
	init_timer_interrupt();
	while(1){

	}
  return 0;
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
	static int Num = 1;
	static int IncDec = 0;

	//clear interrupt
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
	//Do something
	if (count % 1000 == 0){
		display(Num); //Display Num

		if (IncDec == 0){ //Incrementing Check if equal max value begin decrement if so
			Num = Num + 2;
			if (Num == 15) IncDec = 1;
		}
		else if(IncDec == 1){ //Incrementing Check if equal max value begin decrement if so
			Num = Num - 2;
			if (Num == 1) IncDec = 0;
		}

	}

	//Timer Expires
	count ++;
	return;
}

void display(int Value){
	int SEVENSEGLUT[10] = {0b01000000, 0b01111001, 0b00100100, 0b00110000, 0b00011001, 0b00010010, 0b00000010, 0b01111000, 0b10000000, 0b00010000};
	int R;
	int toDisplay = 0;
	int shiftVal = 0;
	int FourthSeg = 0b11111111;
	int toDisplayMask =0;

	while (Value != 0){ //Displays the value on the Hex Masks are for 0 values to not be displayed unless the LSB
	R = Value % 10;
	toDisplay = toDisplay + (SEVENSEGLUT[R] << shiftVal);
	Value = (Value - R) / 10;
	shiftVal = shiftVal + 8;
	}
	toDisplay = toDisplay | 0xFFFF0000;
	toDisplayMask = toDisplay & 0x0000FF00;

	if (toDisplayMask == 0){
		toDisplay = toDisplay | 0xFFFFFF00;
	}
	toDisplayMask = toDisplay & 0x000000FF;
	if (toDisplayMask == 0){
		toDisplay = 0xFFFFFF40;
	}

	IOWR(SEVSEGMENT_4LSB_BASE, 0, toDisplay);
	return;
}
*/
