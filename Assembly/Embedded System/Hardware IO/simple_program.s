.text
.equ	LEDs,  0x10000000
.equ	SWITCHES, 0x10000040
.global _start

_start:
	movia	r2, LEDs		#LED Add         
	movia	r3, SWITCHES	#Switch Add
LOOP:
	ldwio	r4, (r3)		#Switch State into R4
	xori r4, r4, 0b11110000 # Toggles first 4 MSbits and sets last 4 LSB
	stwio	r4, (r2)		
	br	LOOP
.end
