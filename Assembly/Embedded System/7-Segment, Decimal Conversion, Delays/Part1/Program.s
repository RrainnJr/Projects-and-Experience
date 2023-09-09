/* Program that converts a binary number to decimal, you can modify the program */ 
     .text   
    .global    _start  
  _start: 
    movia r4, N 
    addi   r8, r4, 4    # r8 points to storage location 
    ldw   r4, (r4)     #r4 loads N 
    call   DIVIDE    #parameter for DIVIDE is in r4 
    stb   r3, 1(r8) 
    stb   r2, (r8)  
  END:  br  END  
 
#Subroutine can be modified if needed*/ 
# Subroutine to perform the integer division r4 / 10 */ 
# Returns: quotient in r3, and remainder in r2 */  
 
  DIVIDE:  
	mov  r2, r4     # will be the remainder       
    movi  r5, 10    #divisor 
    movi  r3, 0    #r3 will be the quotient        
  CONT:   
	blt  r2, r5, DIV_END 
	sub  r2, r2, r5
    addi  r3, r3, 1
    br  CONT 
  DIV_END:  
	ret   
 
  N:   .word  9876      #the decimal number to be converted 
  Digits:  .space 4       #space for storage location 
    .end
