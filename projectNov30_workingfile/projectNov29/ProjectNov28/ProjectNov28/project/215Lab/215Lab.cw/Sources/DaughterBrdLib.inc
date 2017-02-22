;
DispDigit:	cmpb	#$ff	; blank the display?
		bne	NoBlank	; no. check for valid hex digit.
		incb
		stab	PORTDLC	; yes. store $ff to turn off all segments.
		rts
NoBlank:	cmpb	#$0f	; b greater than max. hex digit?
		bhi	Error	; yes. don't change display.
		ldx	#LEDTable	; no. point to translation table.
		ldaa	PORTDLC	; get value of segments
		anda	#$80	; mask off all but decimal point.
		oraa	b,x	; OR in info from seg. table.
		staa	PORTDLC	; update display data.
Error:		rts		; return.
;
LEDTable:	dc.b	%00111111	; zero
		dc.b	%00000110	; one
		dc.b	%01011011	; two
		dc.b	%01001111	; three
		dc.b	%01100110	; four
		dc.b	%01101101	; five
		dc.b	%01111101	; six
		dc.b	%00000111	; seven
		dc.b	%01111111	; eight
		dc.b	%01100111	; nine
		dc.b	%01110111	; A
		dc.b	%01111100	; b
		dc.b	%00111001	; C
		dc.b	%01011110	; d
		dc.b	%01111001	; E
		dc.b	%01110001	; F
;
