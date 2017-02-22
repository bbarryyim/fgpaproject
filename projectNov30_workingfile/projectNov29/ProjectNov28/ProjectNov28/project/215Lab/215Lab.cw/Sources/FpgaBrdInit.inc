

	bset  DDRB, #LED1
;LCD Initialization
		bset DDRE, CheckLcdBusy
		bclr PORTE, CheckLcdBusy
		
		clr PORTB
		
		bset DDRB, EClk | Rw | RS
;-----------------------------------------------		

		ldaa #$ff
		staa DDRA
		ldaa #8

		psha
		ldy #InitCmdTbl
		

NextCmd:	ldaa 1,y+
		staa PORTA

		bset PORTB,#EClk		

		bclr PORTB,#EClk
		ldab 1,y+

		jsr uS100Delay
		
		

		dec 0,sp
		bne NextCmd
		pula
;--------------------------------------------------	
; interrupt initialization	
	bset DDRE, nRST1 | nRST2
	;;; bclr DDRE, Status2 ; default setting
	movb #0, swIntCnt ; initialize the interrupt counter
	; initialize switch status variable (swStat_old)
	ldaa PORTB
	; only the four button bits are important
	anda #(nSw4B | nSw3WG | nSw2RO | nSw1Y)
	staa swStat_old
	;Initialize the external interrupt
	movw #ExtIsr, IRQIsrP
	bclr PORTE, nRST1 | nRST2 ; reset flipflops
	;enable external interrupts in default level-sensitive mode
	; (not edge sentitive)
	bset INTCR, IRQEN |!IRQE
	;enable push button interrupt but not daughter brd interrupt
	bset PORTE, nRST1 |!nRST2	