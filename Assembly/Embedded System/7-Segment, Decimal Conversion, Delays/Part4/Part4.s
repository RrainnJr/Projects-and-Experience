.text
.global _start 
	

_start:
    	movia  r9, TEST_NUM 
    	mov  r10, r0 
		movia	 r6, 0
		movia	 r2, 0
main:
		ldw	r4, (r9)
		bgt r6, r2, skip
		mov r6, r2
skip:	
		movia	r2, 0
		beq	r4, r0, end
		call ONES
		addi r9, r9, 4
		br main

ONES:
		beq  r4, r0, ENDONES 
    	srli  r11, r4, 0x01 
    	and  r4, r4, r11 
    	addi  r2, r2, 0x01 
    	br  ONES 

ENDONES:  
	ret

end:
	movia r1, 0x10000020
	movia r7, LUT
	add r7, r7, r6
	ldb r6, (r7)
	stb	r6, (r1)
ENDLOOP:
	br ENDLOOP

TEST_NUM:  
	.word 0x3fabedef 
	.word 0xFF12384F
	.word 0x99FCAB94
	.word 0x10219341
	.word 0xFCABEFCA
	.word 0x12345678
	.word 0xFFF00000
	.word 0xF1231112
	.word 0x00FEABCA
	.word 0xF1234F87
	.word 0x00000000

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
	.byte 0b10111001#C
	.byte 0b10100001#d
	.byte 0b10000110#E
	.byte 0b10001110#F

.end 
