; Completed assignment submitted by:
;
; Student #1 -- Name: _________________  Student #: ______________
;
; Student #2 -- Name: _________________  Student #: ______________
;

;*** Note:  we may have introduced one or more errors in this file.

;A subroutine that calculates the remainder of a division between a dividend 
;and a divisor. The divisor is a one byte unsigned number and it's address is
;provided by the Y register. The dividend is a multiple byte unsigned number with
;maximum length of 4 bytes (maximum value of $FFFF,FFFF) and the address of it is 
;derived from the X register. The X register points at the dividend 
;length byte which is followed by the "value" bytes of the dividend (check the TestTbl).
;The subroutine returns in accumulator A the remainder of the division.  In 
;addition, the subroutine returns in accumulator B the value 0 if the quotient,
;as an unsigned value, would fit in an 8-bit byte (i.e. the quotient would be 255 or 
;less).  Otherwise, the subroutine returns in accumulator B the value 1.
;
;********************************** Method *************************************
;The remainder subroutine is written in an easy way and uses
;a "multiple byte" subtraction subroutine which subtracts a single byte unsigned  
;number from a multiple-byte unsigned number. By doing multiple
;subtractions and checking the "borrow flag", we easily obtain the remainder of 
;the "multiple byte" division.  This is not processor efficient in general, but we 
;are not concerned with processor efficiency for this subroutine.  
;

;************* Remainder subroutine input and output data summary ****************
;Entry:	X = address of dividend (length plus value bytes); Y = address of divisor
;Exit:  A = remainder; B = 0 if quotient would fit in 8-bit byte, 1 otherwise
;Regs Modified:  X,Y,CCR
;Global Variables Modified:  Scratch, QuotientLSB, QuotientIsBig
;NOTE:  does not modify the dividend at the address passed in through X
		
Remainder:	
		; initialize variables
		; copy dividend to scratch area

		pshy
		ldy	#Scratch
		ldab	X		; copy dividend length to b.
		stab	Y		;	and store it
		

DLoop1:
		movb	B,X,B,Y		; both arguments use indexed addressing
		dbne	B,DLoop1

		; initialize other variables
		
		movb	#0,QuotientLSB
		movb	#0,QuotientIsBig
		
		pulx			; now X has address of divisor
		
		; subtract in loop until borrow
DLoop2:
		bsr	BigSubtract
		bcs	Cont

		inc	QuotientLSB
		bne	DLoop2
		movb	#1,QuotientIsBig	; quotient is non-zero multiple of 256.
		bra	DLoop2

Cont:		
		; add back divisor

		ldab	Y	; put dividend length in b
		ldaa	B,Y	; load a with least significant byte
		adda	X	; remainder in A
		
		ldab	QuotientIsBig
		
		rts
EndRemainder:	
	
;************* BigSubtract subroutine input and output data summary **************
;Entry:	Y = address of minuend (length plus value bytes); X = address of subtrahend
;Exit:  C = borrow status 
;Regs Modified:  A,B,CCR
;Variables Modified:  minuend value bytes are modified to become the difference
		
BigSubtract:	
		ldab	y	; load b with minuend length

		;first do subtraction on Least Significant Byte (LSB)		
		ldaa	B,Y	; move byte to a
		sbca	X	
		staa	B,Y	; move a back to memory
		dbeq	B,BSEnd	
		
		;then loop doing borrowing if needed
		;this has been optimized to detect when no (more) borrowing is needed
BSLoop:		
		bcc	BSEnd
		ldaa	B,Y			
		sbca	#0
		staa	B,Y	 
		dbne	B,BSLoop
		
BSEnd:
		rts
		