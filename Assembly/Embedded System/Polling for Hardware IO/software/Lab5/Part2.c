/*

#include <stdio.h>
#include <system.h>
#include <alt_types.h>
#include "altera_avalon_pio_regs.h"

int main(){
	alt_u32 outSevenSeg =0;
	int Max8Bitu = 255;
	int Max8Bits = 127;
	int Min8Bits = -127;
	outSevenSeg = 4294967295;

	IOWR(SEVSEG4MSB_BASE, 0, outSevenSeg);


	while(1){
		Display(Max8Bitu);
		IOWR(RED_LEDS_BASE, 0, Max8Bitu);
		delay();
		Display(Max8Bits);
		IOWR(RED_LEDS_BASE, 0, Max8Bits);
		delay();
		Display(Min8Bits);
		IOWR(RED_LEDS_BASE, 0, (0b000000000011111111 & Min8Bits));
		delay();
	}





	printf("complete");
	return 0;
}

void Display(int Value){
	int FourthSeg;
	if (Value < 0){
		Value = abs(Value);
		FourthSeg = 0b0111111;
	}
	else
		FourthSeg = 0b1111111;

	int SEVENSEGLUT[9] = {0b01000000, 0b01111001, 0b00100100, 0b00110000, 0b00011001, 0b00010010, 0b00000010, 0b01111000, 0b00000000, 0b00011000};
	int R;
	int Count = 0;
	int toDisplay = 0;
	int shiftVal = 0;

	while (Value != 0){
	R = Value % 10;
	toDisplay = toDisplay + (SEVENSEGLUT[R] << shiftVal);
	Value = (Value - R) / 10;
	shiftVal = shiftVal + 8;
	}
	toDisplay = toDisplay + (FourthSeg << shiftVal);
	IOWR(SEVSEGMENT_4LSB_BASE, 0, toDisplay);
	return;
}

void delay(){
	int delay = 0;
		while(delay < 2000000)
		{
			delay++;
		}

return;
}
*/

