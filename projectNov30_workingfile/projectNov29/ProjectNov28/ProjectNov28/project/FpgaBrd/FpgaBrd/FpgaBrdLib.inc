; ENSC 151 FPGA board library

FirstCmd:	equ	LcdFuncSet | LcdDL | LcdN	; | !LcdF	
		
; Table of initialization commands (see Sharp LCD documentation)
;
;					100uS
;			instruction	delay		
;			byte		periods
InitCmdTbl:	dc.b	FirstCmd,	41	; get the modules attention.
		dc.b	FirstCmd,	1
		dc.b	FirstCmd,	1
		dc.b	FirstCmd,	1	; specify interface width, lines & font.
		dc.b	LcdDispOnOff | !LcdD | !LcdC | !LcdB
		dc.b			1	; turn display off.
		dc.b	LcdDispClr,	17		
		dc.b	LcdEntMdSet | LcdInD | !LcdS
		dc.b			1	; increment cursor, no display scroll.
		dc.b	LcdDispOnOff | LcdD | LcdC | LcdB
		dc.b			1	

; Subroutine to delay for multiples of 100uS.
; Taken from "Programming the Motorola M68HC12 Family" by G. Doughman, 2000
; The number of multiples should be placed in accumulator b.
; Regs Mod:  CCR, X, B

uS100Delay:	ldx	#200		; 100 uS delay constant @ 8MHz E-clock.
Delay:		dex
		bne	Delay
		dbne	b,uS100Delay	; times the number in a	accumulator	        	
		rts
;Inerrupt Service routine for the External IRQ

ExtIsr:
	;send reset pusle to push button(/LCD) flip flop
	bclr PORTE, nRST1
	bset PORTE, nRST1
	
	
;----------------------------------------------------------
	
;	;Check if the interrupt is from the Push Buttons
;	ldaa PORTB
;	; only the four button bits are important
;	anda #(nSw4B | nSw3WG | nSw2RO | nSw1Y)
;	cmpa swStat_old
;	beq daughterChk
;	;deal with push buttons
;	inc swIntCnt
;	staa swStat_old

;---------------------------------------------------------

	
	
	
;brset mem-address,mask, jump add
	;brset PORTB,nSw1Y,check_blue	
	;bset PORTB, #LED1
	
	
check_yellow:
	
	brset PORTB,nSw1Y,endExtIsr
	
	pshd
	ldd TCNT
	addd #1250
	std TC2
	puld
	bset TMSK1,C2I
	
	ldab digit4
	cmpb #$0c
	beq changetoF
	bra changetoC
	

changetoF
	bset PORTB, #LED1
	ldaa #$0f
	staa digit4
	bra endExtIsr
	
	
	
changetoC
	bclr PORTB, #LED1
	ldaa #$0c
	staa digit4
	bra endExtIsr
	
	
;	lbeq celsius
;	lbra fahreinheit	
;	inc count
;	ldd count
;;	ldx #2
;	idiv
;	std tmp
;	ldaa tmp
;	cmpa #1
;	lbeq fahreinheit
		
		
		
		
;	ldaa digit1
;;;;;	ldab #100
;	mul
;	std tmpvalue1
;	ldab digit2
;	ldaa #10
;	mul
;	std tmpvalue2
;	ldaa tmpvalue1
;	ldab tmpvalue2
;	addd digit3
;
	
;check_red:
	
;	brset swStat_new,nSw2RO, endExtIsr
;	pshd
;	ldd TCNT
;	addd #1250
;	std TC2
;	puld
;	bset TMSK1,C2I

	
	
daughterChk:
	brclr PORTE, Status2, endExtIsr
	
;if we get here there is an unexpected interrupt
	bclr PORTE, nRST2
	bset PORTE, nRST2
	
endExtIsr:
	rti

TimerCh2:
	bclr TMSK1, C2I
	ldaa PORTB
	anda #nSw1Y
	cmpa #0
	bne TimeCh2Done

TimeCh2Done:
	rti

;TimerCh2:
;	bclr TMSK1, C2I
;	ldaa PORTB
;	anda #nSw2RO
;	cmpa #0
;	bne TimeCh2Done
;	ldab #'R'
;	jsr putchar
	
;TimeCh2Done:
;	rti


;	LCD Module Commands (taken from Doughman Textbook)
;
; Subroutine SetCursPos is used to place the cursor at a specific
; character location on the display.  To simplify the task of displaying
; text messages, this subroutine accepts a number from $00 through $1F
; in the B accumulator as a cursor position.  Line one contains 
; character positions $00 through $0F while line two contains character
; positions $10 through $1F.
SetCursPos:	cmpb	#$0f		; first row ($00 - $0f)?
		bls	FirstLine		; yes. go send command.
		cmpb	#$1f		; no. second row ($10 - $1f)?
		bhi	BadCursPos		; no. bad position.
		addb	#$30		; yes. module cursor addr. is $40 - $4f.
FirstLine:	addb	#$80		; msb is cursor command.
		bsr	SendCmd		; move the cursor.
BadCursPos:	rts			; return.
;
; Subroutine which accepts a pointer to a null (zero) terminated string
; in the X index register and one of the constants Line1 or Line2 in 
; the B accumulator.  The entry point at DispLine will display the 
; string on the indicated line. The entry point at DispLineE will first 
; erase the line before displaying the string
DispLineE:	pshx			; save pointer to the message.
		pshb			; save 'line number'.
		bsr	SendCmd		; place cursor at start of line.
		ldx	#ClrLine		; point to spaces string.
		bsr	OutStr		; clear the line.
		pulb			; restore line number.
		pulx			; restore the message pointer.
DispLine:	bsr	SendCmd		; place cursor at start of line.
		bsr	OutStr		; display the message.
		rts	
;
ClrLine:	dc.b	"                ", 0
;
; Subroutine to send null terminated strings to the display module.
; On entry the X index register should point to a null terminated string.
OutStr:		ldab	1,x+		; get next character. Done?
		beq	MsgDone		; yes. return.
		bsr	putchar		; no. send it to the display.
		bra	OutStr		; send next character.
MsgDone:	rts			; return.
;
; The SendCmd subroutine transmits one LCD instruction, passed in the
; B accumulator, to the display module.
SendCmd:	bsr	IsBusy		; is the module busy?
		bne	SendCmd		; yes. keep checking until it's not.
		bclr	PORTB,RS+Rw		; RS & R/w = 0.
		ldaa	#$ff		; change port a to outputs.
		staa	DDRA
		stab	PORTA		; put command on module data bus.
		bset	PORTB,#EClk		; latch command into module.
		bclr	PORTB,#EClk
		clr	DDRA		; return port a to inputs.
		rts
;
; Subroutine IsBusy returns with the Z condition code register bit 
; set if the module's busy bit was clear indicating that the module
; is idle and ready to accept another command.
IsBusy:		clr	DDRA		; make port a inputs.
		bclr	PORTB,RS		; RS = 0 for commands.
		bset	PORTB,Rw		; set R/w for read.
		bset	PORTB,#EClk		; data output 160 nS after rising
		nop			; edge of E.
		ldaa	PORTA		; get status data from module.
		bclr	PORTB,#EClk		; put E-clock back low.
		bita	#BUSY		; busy bit set if module is busy.
		rts
		;
; Subroutine putchar allows writing a single 8-bit ASCII character
; in the B accumulator to the LCD display.
putchar:	bsr	IsBusy		; is the module busy?
		bne	putchar		; yes. must wait until it's not.
		bclr	PORTB,Rw		; set R/w for write.
		bset	PORTB,RS		; set RS = 1 for data write.
		ldaa	#$ff		; make port a outputs.
		staa	DDRA
		stab	PORTA		; put character on module's data bus.
		bset	PORTB,#EClk		; clock it into the module.
		bclr	PORTB,#EClk
		clr	DDRA		; make port a inputs.
		rts			; return.
;