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
	movia	r5, GLEDs		#Green LEDs
	movia	r6, HexLSB		#LSB Hex Bits
	movia	r7, HexMSB		#MSB Hex Bits
	movia 	r11, 0b1000
LOOP:
	ldwio	r4, (r3)		#Switch State into R4
	stwio	r4, (r2)	
	stwio	r4, (r5)

	ldbio 	r9, (r3)
	ldbio	r10, (r3)
	sll 	r10, r10, r11
	add		r9, r9, r10
	sll		r10, r10, r11
	add		r9, r9, r10
	sll		r10, r10, r11
	add		r9, r9, r10

	stwio	r9,	(r6)
	stwio	r9,	(r7)
	br	LOOP
.end
