.data 
LUT: 
	.byte 0b11000000#0
 	.byte 0b11111001#1
	.byte 0b10100100#2
	.byte 0b10110000#3
	.byte 0b10011001#4
	.byte 0b10010010#5
	.byte 0b10000010#6
	.byte 0b11111000#7
	.byte 0b10000000#8
	.byte 0b10010000#9
	.byte 0b10001000#A
	.byte 0b10000011#b
	.byte 0b11000110#C
	.byte 0b10100001#d
	.byte 0b10000110#E
	.byte 0b10001110#F

.text
.equ	RLEDs,  0x2040
.equ	SWITCHES, 0x2010
.equ	GLEDs, 0x2030
.equ	HexLSB, 0x2020
.equ	HexMSB, 0x2000
.global _start

_start:
	movia	r2, RLEDs		#LED Add         
	movia	r3, SWITCHES	#Switch Add
	#movia	r5, GLEDs		#Green LEDs
	movia	r6, HexLSB		#LSB Hex Bits
	movia	r5, 0x500		#LUT
	movia 	r13, 0x1
	br		LOOP

DELAY: 
	
	movia r11, 0x0        #Initialize R11, our iterator 
	movia r10, 0x04C4B40     #what we have to iterate to

Delay2:
	bgt r11, r10, LOOP2 #Compares iteration 1 instructino
	add r11 ,r11, r13 #1 #Adds one to the iteration, 2 instructions
	movia r12, 0x0 # 3 instructions (Filler code)
	add r12, r12, r12 # 4 instructions (FIller Code)
	br Delay2


LOOP:
	ldbio	r4, (r3)		#Switch State into R4
	andi	r4, r4, 0b00001111
	add 	r4, r4, r5
	ldbio	r7, (r4)
	stwio	r7, (r6)
	br DELAY
LOOP2:
	ldbio 	r4, (r3)
	mul		r4, r4, r4
	stwio	r4, (r2)
	br	LOOP
.end
