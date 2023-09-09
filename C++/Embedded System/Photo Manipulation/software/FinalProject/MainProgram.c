#include <stdio.h>
#include <system.h>
#include "sys/alt_stdio.h"
#include <io.h>
#include <altera_up_sd_card_avalon_interface.h>
#include <altera_up_avalon_video_pixel_buffer_dma.h>
#include <sys/alt_irq.h>
#include <altera_avalon_timer_regs.h>
#include "altera_avalon_pio_regs.h"



volatile int i, j, Value;
void pio_init();
void initCard();
void VGA();
void VGA_box(int, int, int, int, int);
void handle_key_interrupts(void*);
void invertPhoto();
int FileSelect = 0;

int main()
{
  printf("Hello from Nios II!\n");
  pio_init();
  VGA();
  initCard();
  printf("out\n");
  while (1){
  }
  return 0;
}

void VGA(){
	printf("VGALOOP");
	VGA_box(0,0, 321, 241, 0x8000);
	//VGA_box(0, 0, 100, 100, 0xF011);
	//VGA_box(20, 20, 300, 200, 0x4002);
	//VGA_box(30,30,600, 1079, 0x4002);

}

void initCard()
	{
		short att1 = 0, att2 = 0, att3 = 0, att;
		int width = 320;
		int height = 240;
		int pixel;
	    alt_up_sd_card_dev *device_reference = NULL;
	    int connected = 0;
	    short int fileHandle;

	    if ((Value & 0xF00) == 0x900){
	    	width = width + (Value & 0x0FF);
	    }

	    device_reference = alt_up_sd_card_open_dev(ALTERA_UP_SD_CARD_AVALON_INTERFACE_0_NAME);
	    if (device_reference != NULL)
	    {
		    if ((connected == 0) && (alt_up_sd_card_is_Present()))
		    {
		        if (alt_up_sd_card_is_FAT16())
		        {
		        	if (FileSelect == 0){
		        		fileHandle = alt_up_sd_card_fopen("smile.bmp",false);
		        	}
		        	else if (FileSelect == 1){
		        		fileHandle = alt_up_sd_card_fopen("tayeb2.bmp",false);
		        	}
		        	else if (FileSelect == 2){
		          		fileHandle = alt_up_sd_card_fopen("buko.bmp",false);
		        	}
			        att = alt_up_sd_card_get_attributes(fileHandle);

			        VGA_box(0,0, 321, 241, 0xFFFF);

			        for (j=0; j<54; j++) //gets past header
			        {
			        	att1 = alt_up_sd_card_read(fileHandle);
			        }
			        i = 0, j = 0;
			        printf("File handle: %i\n", fileHandle);
			        for (i = height; i >= 0; i = i-1){
			        	for (j = 0; j < width; j = j+1){
			        		att1 = (unsigned char)alt_up_sd_card_read(fileHandle);
			        		att2 = (unsigned char)alt_up_sd_card_read(fileHandle);
			        		att3 = (unsigned char)alt_up_sd_card_read(fileHandle);
			        		pixel = ((att3>>3)<<11) | ((att2>>2)<<5) | (att1 >> 3);
			        		//pixel = ((att3)<<16) + ((att2)<<8) + (att1);
			        	VGA_box(j,i,j,i,pixel);
			        	}
			        }
			        if ((Value & 0xF000) == 0x1000){
			        	    	invertPhoto();
			        }
			        alt_up_sd_card_fclose(fileHandle);
			    }
		        else
		        {
			    printf("Unknown file system.\n");
		        }

		        connected = 1;
		    }
		    else if ((connected == 1) && (alt_up_sd_card_is_Present() == false))
		    {
		        printf("Card disconnected.\n");
		        connected = 0;
		    }
	    }
	    else
	    {
		printf("Initialization failed.\n");
	    }

	}

void invertPhoto(){
	short att1 = 0, att2 = 0, att3 = 0, att;
	int pixel;
	int width = 320;
	alt_up_sd_card_dev *device_reference = NULL;
    int connected = 0;
    short int fileHandle;

    	if ((Value & 0xF00) == 0x900){
		    width = width + (Value & 0x0FF);
		}

		    device_reference = alt_up_sd_card_open_dev(ALTERA_UP_SD_CARD_AVALON_INTERFACE_0_NAME);
		    if (device_reference != NULL)
		    {
			    if ((connected == 0) && (alt_up_sd_card_is_Present()))
			    {
			        if (alt_up_sd_card_is_FAT16())
			        {
			        	if (FileSelect == 0){
			           		fileHandle = alt_up_sd_card_fopen("smile.bmp",false);
			        		}
  			        	else if (FileSelect == 1){
   			        		fileHandle = alt_up_sd_card_fopen("tayeb2.bmp",false);
       			        	}
   			        	else if (FileSelect == 2){
   			          		fileHandle = alt_up_sd_card_fopen("buko.bmp",false);
   			        	}

				        att = alt_up_sd_card_get_attributes(fileHandle);

				        VGA_box(0,0, 321, 241, 0xFFFF);

				        for (j=0; j<54; j++) //gets past header
				        {
				        	att1 = alt_up_sd_card_read(fileHandle);
				        }
				        i = 0, j = 0;
				        printf("File handle: %i\n", fileHandle);
				        for (i = 0; i <= 240; i = i+1){
				        	for (j = 0; j < width; j = j+1){
				        		att1 = (unsigned char)alt_up_sd_card_read(fileHandle);
				        		att2 = (unsigned char)alt_up_sd_card_read(fileHandle);
				        		att3 = (unsigned char)alt_up_sd_card_read(fileHandle);
				        		pixel = ((att3>>3)<<11) | ((att2>>2)<<5) | (att1 >> 3);
				        		//pixel = ((att3)<<16) + ((att2)<<8) + (att1);
				        	VGA_box(j,i,j,i,pixel);
				        	}
				        }
				        alt_up_sd_card_fclose(fileHandle);
				    }
			        else
			        {
				    printf("Unknown file system.\n");
			        }

			        connected = 1;
			    }
			    else if ((connected == 1) && (alt_up_sd_card_is_Present() == false))
			    {
			        printf("Card disconnected.\n");
			        connected = 0;
			    }
		    }
		    else
		    {
			printf("Initialization failed.\n");
		    }

}

void VGA_box(int x1, int y1, int x2, int y2, int Color){
	int offset, row, col, StateFlag, NewValue;
	int R, G, B;
	StateFlag = Value & 0xF00; //Get State Flag
	NewValue = Value & 0x0001F; //Remask Value

	R = Color & (0b1111100000000000);
	G = Color & (0b0000011111000000);
	B = Color & (0b0000000000011111);
	switch (StateFlag >> 8){
		case(1):
				R = R + (NewValue << 11);
				G = (Color & 0b0000011111100000) + (NewValue << 6);
				B = B + NewValue;
				if (R >= 0b10000000000000000){
					R = 0b11111 << 11;
				}
				if (G >= 0b0000100000000000){
					G = 0b111111 << 5;
				}
				if (B >= 0b100000){
					B = 0b11111;
				}
				Color = R | G | B;
				break;
		case(2): //Red becomes Blue, Blue Becomes Green, Green Becomes Red
				Color = ((R >> 11) | (G << 5) | (B << 6));
				break;
		case(3): //Red becomes Green, Green becomes Blue, Blue becomes Red
				Color = ((R >> 5) | (G >> 5) | (B << 11));
				break;
		case(4):
				Color = Color & 0b1111100000000000;
				break;
		case(5):
				Color = Color & 0b0000011111100000;
				break;
		case(6):
				Color = Color & 0b0000000000011111;
				break;
		default:
			break;
	}

	volatile short *pixel_buffer = (short *) 0x00200000;
	for (row = y1; row <= y2; row++){
		col = x1;
		while (col <= x2){
			offset = (row << 9) + col;
			*(pixel_buffer + offset) = Color;
			++col;
		}

	}
}

void key3_isr(){
	// Reload Image if switch 1 is high change to next photo
	int Sw = IORD(SWITCHES_BASE, 0);
	if ((Sw & 0x1) == 1){
		if (FileSelect == 0){
			FileSelect = 1;
		}
		else if (FileSelect == 1){
			FileSelect = 2;
		}
		else FileSelect = 0;
	}
	printf("KEY 3");
	initCard();
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key2_isr(){
	//Just Red Values, Just Blue Values, Just Green Values
	if (Value == 0x400){
		Value = 0x500;
	}
	else if (Value == 0x500){
		Value = 0x600;
	}
	else Value = 0x400;

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key1_isr(){
	//INVERT RGB
	printf("KEY 2\n");
	if (Value == 0x200){
		Value = 0x300;
	}
	else if(Value == 0x300){
		Value = 0x000;
	}
	else Value = (0x200);

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	return;
}

void key0_isr(){
	//Brightness, Increase Pixel Color by Switch Value
	printf("KEY 0");
	Value = IORD(SWITCHES_BASE, 0);
	if ((Value & 0b100000000000000000) > 0){
		//If Value of 17 is high, Width Adjustment go crazy
		Value = Value & 0x001F;
		Value = Value + 0x900;
	}
	else if ((Value & 0b010000000000000000) > 0){ //Switch 16 is high, Mirror the image up and down
		Value = Value & 0x001F;
		Value = Value + 0x1000;
	}
	else if ((Value & 0b001000000000000000) > 0) { //Switch 15 is high brightness changes
	Value = Value & (0x001F);
	Value = Value + (0x100); //Add the State Flag
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

