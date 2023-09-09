#include <stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
int main()
{
int count = 0;
int delay;
printf("Hello from Nios II!\n");
while(1)
{
	int LED_PIO_BASE = 8256;
	IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE, count & 0x01);
	delay = 0;
	while(delay < 2000000)
	{
		delay++;
	}
	count++;
}
return 0;
}
