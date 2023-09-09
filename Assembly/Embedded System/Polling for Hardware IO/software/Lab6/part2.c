
#include <stdio.h>
#include <system.h>
#include <alt_types.h>
#include "altera_avalon_pio_regs.h"
#include <stdio.h>

int IncDec = 0;

void delayfn(){
	int delay = 0;
		while(delay < 2000000)
		{
			delay++;
		}
}



void key3_isr(){
	// Decrement the Num to 0
	IncDec = 2; //Turns IncDec to 2 in order to run Decrement in main

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key2_isr(){
	// Increment to 99
	IncDec = 1; //Turns IncDec to 1 in order to run in main

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key1_isr(){
	// Set to 0
	IOWR(SEVSEGMENT_4LSB_BASE, 0, 0xFFFFFF40); //Sets to 0
	IncDec = 0; //Stops inc or dec

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
	return;
}

void pio_init(){
	void* edge_capture_ptr = KEYS_EDGE_TYPE;
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0xE);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0x0);
	alt_irq_register(KEYS_IRQ, edge_capture_ptr, handle_key_interrupts);

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

int DecodeHex(int Val){ //Decodes the HEX from the Seven Seg into an Integer, Used as Starting Point for Inc and Dec
	int SEVENSEGLUT[10] = {0b01000000, 0b01111001, 0b00100100, 0b00110000, 0b00011001, 0b00010010, 0b00000010, 0b01111000, 0b00000000, 0b00010000};
	int i;
	int MASK = 0b01111111;
	int Output = 0;
	int Lookup = Val & MASK;
	int ShiftAmt = 0;
	int Count = 1;

	while (Lookup != 0b1111111){
	for (i = 0; Lookup != SEVENSEGLUT[i]; i++){};
	Output = Output + (i*Count);
	Count = Count * 10;
	ShiftAmt = ShiftAmt + 8;
	Lookup = Val & (MASK << ShiftAmt);
	Lookup = Lookup >> ShiftAmt;
	}
	return Output;
}

void incr(){ //Increments from where the Hex Display is to 99
	int HexVal = 0;
	HexVal = IORD(SEVSEGMENT_4LSB_BASE, 0);
	HexVal = DecodeHex(HexVal);
	for (int i = HexVal; i <= 99 && IncDec == 1; i++){
		display(i);
		delayfn();
	}
	return;
}

void decr(){ //Decrements from Current val of hex display to 0
	int HexVal = 0;
	HexVal = IORD(SEVSEGMENT_4LSB_BASE, 0);
	HexVal = DecodeHex(HexVal);
	for (int i = HexVal; i >= 0 && IncDec == 2; i--){
		display(i);
		delayfn();
	}
	return;
}

int main(){ //Initializes the 7 Segment
	pio_init();
	int outSevenSeg = 0xFFFFFFFF;
	IOWR(SEVSEG4MSB_BASE, 0, outSevenSeg);
	IOWR(SEVSEGMENT_4LSB_BASE, 0, outSevenSeg);

	printf("Key3: Decrement\nKey2: Increment\nKey1: Set to 0");
	while(1){ //Loops through Calling Incr function if IncDec changes to 1 and Decr if to 0. Doing this here allows for these fns to be interrupted.
		if (IncDec == 1) incr();
		else if (IncDec == 2) decr();
	}

  return 0;
}

