; Created by Craig Scratchley, Summer 2008
; Copyright (C) 2008 School of Engineering Science, SFU, Burnaby, BC, Canada
; You can modify this software under the terms of the GNU General Public License

; Additional memory map equate (equates fixed for the chip are in b32regs\configsc.asm)
Dbg12Ram	EQU	$0A00	; absolute address for D-Bug12 variable/scratch RAM

; D-Bug12's RAM-based interrupt vector table
; A table of pointers to user Interrupt Service Routines

; Consider an ISR such as:
;
; ExtIsr:	...	; External ISR code here
;		RTI
;
; Normally, a user would set a user ISR using the D-Bug12
; SetUserVector() subroutine (possibly by using the SetUserVector
; macro:  e.g. SetUserVector #UserIRQ,#ExtIsr)
;
; However, the version of D-Bug12 which we are using does not properly
; "Step Over" a call to a subroutine located in Flash ROM.  For this
; reason, we are recommending to directly place the pointer to the ISR
; in the RAM-based table.  This can be done as follows:
;
; 		MOVW	#ExtIsr,IRQIsrP
;
; Alternatively, one could consider putting lines like the following 
; in, say, port-var.inc:
;
; 		ORG	IRQIsrP
;		dc.w	ExtIsr

AtoDIsrP: 	equ 	$0B12 	; A-to-D user interrupt
;SCI0IsrP: 	equ 	 	; SCI #0 user interrupt
SPI0IsrP: 	equ 	$0B18 	; SPI #0 user interrupt
PAccEdgeIsrP:	equ 	$0B1A 	; Pulse Accumulator Edge user interrupt
PAccOvfIsrP: 	equ 	$0B1C	; Pulse Accumulator Overflow user interrupt
TimerOvfIsrP:	equ 	$0B1E 	; Timer counter overflow user interrupt
TimerCh7IsrP:	equ 	$0B20 	; Timer Channel #7 user interrupt
TimerCh6IsrP:	equ 	$0B22	; Timer Channel #6 user interrupt
TimerCh5IsrP:	equ 	$0B24 	; Timer Channel #5 user interrupt
TimerCh4IsrP:	equ 	$0B26 	; Timer Channel #4 user interrupt
TimerCh3IsrP:	equ 	$0B28	; Timer Channel #3 user interrupt
TimerCh2IsrP:	equ 	$0B2A	; Timer Channel #2 user interrupt
TimerCh1IsrP:	equ 	$0B2C	; Timer Channel #1 user interrupt
TimerCh0IsrP:	equ 	$0B2E	; Timer Channel #0 user interrupt
RTIIsrP: 	equ 	$0B30 	; Real Time Interrupt user interrupt
IRQIsrP: 	equ 	$0B32 	; CPU Maskable Interrupt request user interrupt
XIRQIsrP: 	equ 	$0B34 	; CPU Non-maskable Interrupt request user interrupt
SWIIsrP: 	equ 	$0B36 	; Software Interrupt user interrupt
;TrapIsrP: 	equ 	 	; Instruction Trap user interrupt
