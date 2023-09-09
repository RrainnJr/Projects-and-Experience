.text

.equ	RLEDs,  0x2040

.global _start 
_start:
	movia r3, 0b1111110000000000
	movia r6, 0b11111111111111110000001111111111
	movia r4, RLEDs
	movia r1, 0x3fabedef
	movia r2, 0b0001111110000000000

Loop:
 	and r2, r2, r1
	call count
	and r1, r1, r6
	or r1, r1, r2
	br Loop

count:
	beq  r2, r3, reset
	addi r2, r2, 0x400
	stw r2, (r4)
	ret
reset:
	movia r2, 0x0
	stw r2, (r4)
	ret

END:  
	br  END 

.end 
