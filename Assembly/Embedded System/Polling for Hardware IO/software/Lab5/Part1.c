


#include <stdio.h>
#include <system.h>
#include <alt_types.h>
#include "altera_avalon_pio_regs.h"

int main()
{
  printf("Options:\n1. Turn on the first green LED\n2. Turn on the second green LED\n");
  printf("3. Turn on the third green LED\n3\4. Turn on the fourth green LED\n");
  printf("5. Scroll Left\n6. Scroll Right\n");
  int* userin = 0;
  int option = 0;
  alt_u8 out = 00000000;
  while(1){
	  printf("\nSelect an Option:");
	  scanf("%d", userin);
	  option = *userin;
	  switch(option){
	  case 1:
		  out = 1;
		  IOWR(GREEN_LEDS_BASE, 0, out);
		  break;

	  case 2:
		  out = 2;
		  IOWR(GREEN_LEDS_BASE, 0, out);
		  break;

	  case 3:
		  out = 4;
		  IOWR(GREEN_LEDS_BASE, 0, out);
		  break;

	  case 4:
		  out = 8;
		  IOWR(GREEN_LEDS_BASE, 0, out);
		  break;

	  case 5:
		  if (out == 8)
			  out = 1;
		  else
			  out = out + out;
		  IOWR(GREEN_LEDS_BASE, 0, out);
		  break;

	  case 6:
		  if (out == 1)
			  out = 8;
		  else
			  out = out - (out/2);
		  IOWR(GREEN_LEDS_BASE, 0, out);
		  break;

	  default:
		  return 0;
	  }


  }

  return 0;
}

