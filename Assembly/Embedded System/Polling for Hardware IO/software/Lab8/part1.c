
#include <stdio.h>
#include <system.h>
#include <alt_types.h>
#include "altera_avalon_pio_regs.h"
#include <stdio.h>
#include <sys/alt_irq.h>
#include <altera_avalon_timer_regs.h>

void init_timer_interrupt ();
static void timer0_isr(void* context, alt_u32 id);
static void timer1_isr(void* context, alt_u32 id);
void display(int Value);

/*Three Push Button Interrupts Clear, Start, Stop.
	Red LEDS flash on and off //Every count ++ %10 = .01 s
	Timer Create Delays as well as Keep track of time //Begin timer after Start
	Clear Initially display START with no LEDs // No LEDs
	Start is pushed, Turns off 7-Segment and LEDR // 7 Seg Turned off
		Rand Interval 2-15 seconds flashes on and off //.01 second flash
		Timer Counts
	Stop button pressed, 0000 Milliseconds Displayed on 7
	If Stop pressed after 1 second, Fail, if Pressed before OOPS

	State 0: Not Started
	State 1: Clear Pressed
	State 2: Start is pressed Before Flashing
	State 3: After Flashing
	State 4: time Expired
	State 5: Stop is Pressed In time
*/
int MSTODELAY = 0;
int TIME = 0;
int state = 0;

void key3_isr(){
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key2_isr(){
	//Clear
	TIME = 0;
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b1011);
	//Display "START"
	IOWR(SEVSEGMENT_4LSB_BASE, 0, 0b00010010000011110010111100001111);
	IOWR(RED_LEDS_BASE, 0, 0b000000000000000000);
	state = 1;
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key1_isr(){
	//Start
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_1_BASE, 0b0111);
	MSTODELAY = ((rand() % 14) + 2) * 1000;
	//COUNT TILL MSTODELAY
	//When reach MSTODELAY being LED Flashing, and Reset Count
	//Count 1 every ms and Display that value to Display when STOP is pressed
	if (state == 1){
		state = 2;
		IOWR(SEVSEGMENT_4LSB_BASE, 0, 0xFFFFFFFF);
	}
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key0_isr(){
	//Stop
	int OOPS = 0b01000000010000000000110000010010;
	int FAIL = 0b00001110000010000111100101000111;
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_1_BASE, 0b1011);
	if (state == 2){
		IOWR(SEVSEGMENT_4LSB_BASE, 0, OOPS);
	}
	else {
		display(TIME);
		state = 5;
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
	alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ, (void *)timer0_isr, NULL, 0x0);
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, ALTERA_AVALON_TIMER_CONTROL_CONT_MSK
													| ALTERA_AVALON_TIMER_CONTROL_START_MSK
													| ALTERA_AVALON_TIMER_CONTROL_ITO_MSK);
	alt_ic_isr_register(TIMER_1_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_1_IRQ, (void *)timer1_isr, NULL, 0x0);
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_1_BASE, ALTERA_AVALON_TIMER_CONTROL_CONT_MSK
													| ALTERA_AVALON_TIMER_CONTROL_START_MSK
													| ALTERA_AVALON_TIMER_CONTROL_ITO_MSK);
}

static void timer1_isr(void* context, alt_u32 id){
	static int count = 0;
	static int LR = 0;

	//clear interrupt
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_1_BASE, 0);
	//Do something
	if (state == 2){
		if (MSTODELAY == 0){
			state = 3;
		}
		MSTODELAY--;
	}
	if (state == 3){
		TIME++;
		if (TIME % 25 == 0) IOWR(RED_LEDS_BASE, 0, 0b111111111111111111);
		if (count % 50 == 0) IOWR(RED_LEDS_BASE, 0, 0b000000000000000000);
	}
		if (TIME == 1000){
			state = 4;
			IOWR(SEVSEGMENT_4LSB_BASE, 0, 0b00001110000010000111100101000111);
	}
	//Timer Expires
	count ++;
	return;
}

static void timer0_isr(void* context, alt_u32 id){
	static int count = 0;

	//clear interrupt
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
	//Do something

	//Timer Expires
	count ++;
	return;
}

int main(){
	init_timer_interrupt();
	pio_init();
	IOWR(SEVSEGMENT_4LSB_BASE, 0, 0xFFFFFFFF);
	IOWR(SEVSEG4MSB_BASE, 0, 0xFFFFFFFF);
	while(1){
		if (MSTODELAY == 0){

		}
	}
  return 0;
}

void display(int Value){
	int SEVENSEGLUT[10] = {0b01000000, 0b01111001, 0b00100100, 0b00110000, 0b00011001, 0b00010010, 0b00000010, 0b01111000, 0b10000000, 0b00010000};
	int R;
	int toDisplay = 0;
	int shiftVal = 0;
	IOWR(SEVSEGMENT_4LSB_BASE, 0, 0xFFFFFFFF);

	while (Value != 0){ //Displays the value on the Hex Masks are for 0 values to not be displayed unless the LSB
	R = Value % 10;
	toDisplay = toDisplay + (SEVENSEGLUT[R] << shiftVal);
	Value = (Value - R) / 10;
	shiftVal = shiftVal + 8;
	}
	IOWR(SEVSEGMENT_4LSB_BASE, 0, toDisplay | 0xFF000000);
	return;
}

