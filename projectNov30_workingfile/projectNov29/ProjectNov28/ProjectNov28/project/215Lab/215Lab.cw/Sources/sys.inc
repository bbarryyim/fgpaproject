; this file contains the "system-level" code.  
; It may include a "run loop" and calls to subroutines
; defined in other files.

		ldx	#N150007
		ldy	#divisor
		jsr	Remainder

RunLoop:

;		wai			; wait for interrupt
		bra	RunLoop	

;System-related Global Variables


;System-related Constants

N150007:	dc.b	$3,$15,$00,$07
divisor:	dc.b	$5