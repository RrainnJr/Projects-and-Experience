.equ LIST, 0x500       
.global _start 
_start:
	movia  r4, LIST   #moves the value of LIST 0x500 to R4   
	ldw  r5, 4(r4)    #Load word sized data addressed at R4 + sign extended 4 into R5
  	addi  r6, r4, 8   #Adds R4, and 8 sign extended stores into R6
   	ldw  r7, (r6)     #Load word from address R6 into R7
LOOP:
	subi  r5, r5, 1    #Subtract R5 by sign extended 1, and stores into R5
  	beq  r5, r0, DONE   #If R5 = R0 branch to DONE
  	addi  r6, r6, 4    #Add R6 to sign extended 4, store into R6
  	ldw  r8, (r6)     #Load word from address of R6 into R8
  	bge  r7, r8, LOOP   #If R8 is greater than or Equal to R7, LOOP
  	add  r7, r8, r0    #ADDs R8 and R0, Stores in R7
  	br  LOOP 			#Branch to LOOP
DONE:
  	stw  r7, (r4)     #Str the word sized R7 into R4
STOP: 
  	br  STOP       #Inf loop
	.org  0x500 
RESULT: 
	.skip  4         
N:
	.word 7        
NUMBERS: 
	.word  7, 8, 3, 6 ,7, 6, 2 
.end 
