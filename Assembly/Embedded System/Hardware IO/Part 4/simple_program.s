.text
.equ	LEDs,  0x10000000
.equ	SWITCHES, 0x10000040
.global _start

_start:
	movia	r2, LEDs		# LEDs Address         
	movia	r3, SWITCHES	# Switches Address
LOOP:
	ldbio	r4, (r3)		# Read the state of switches.

#Do the Twos Complement of the Switches
	xori r4, r4, 0b11111111 #Invert
	addi r4, r4, 1			#Add 1
	stbio	r4, (r2)		/* Display the state on LEDs. */
	br	LOOP
.end
