;****************************************************************
;* This is a simple absolute assembly project                    *
;* Portions Copyright © 2008 W. Craig Scratchley
;* School of Engineering Science, SFU, BC, Canada  V5A 1S6
;* ENSC 215, May 2008
;* Copying and distribution of this file, with or without modification,
;*     are permitted in any medium without royalty provided the copyright
;*     notice and this notice are preserved.
;*****************************************************************
		NOLIST
; Available RAM for the 151 Hardware kit is in locations 
; $0800 to $09ff inclusive.
; For the simulator the stack pointer is initialzed to
; $0a00 (this is valid).

; Prepared for Metrowerks Codewarrior v3.x
; optimized for tab width of 8 spaces, where a tab does NOT insert spaces
; It is recommended to untick "Enable Virtual Space" in the
; "Editor Settings" pane of the "Preferences..." window in the Edit menu.
; Also, untick "Use Automatic Code Formatting" in "Formatting" pane.
; These preferences should be the defaults in the ENSC labs.

		include preamble.inc	; Do not change this line.
		NOLIST
		INCLUDE "hc912b32.inc"
		INCLUDE "db12.inc"
		INCLUDE "fpgaBrdEqu.inc"
		INCLUDE "DaughterBrdEqu.inc"
		
		LIST
		
; port-var.inc can be included to get ports to the debugger's data window, etc.
;		INCLUDE "portVar.inc"

		ORG 	RAMBase
		
StackRes	EQU	40	; amount of stack space to reserve


; variable definitions for unit tests can be conditionally included here




; code space
; For this project, the label ENTRY must be used for the beginning of
;	the program.
		INCLUDE "FpgaBrdVar.inc"
		INCLUDE "remainderVar.inc"

ENTRY:
; stack grows down, so location #Dbg12Ram will not be modified.
		lds	#Dbg12Ram	;set up stack pointer
		INCLUDE "FpgaBrdInit.inc"
		INCLUDE "DaughterBrdInit.inc"
		INCLUDE "CommonInit.inc"
		;INCLUDE "DaughterBrdTest.inc"
		INCLUDE "TimerInit.inc"
	;	INCLUDE "Timer.inc"
		
;Final Project


;	bset PORTS,DTS	;turn on the temperature sensor
; 	bclr TIOS,IOS3	;set timer to input capture, using channel 3	
	
;-------------------------------------------------------------

;Finding temperature
F	EQU 	7200
G	EQU	4550
P	EQU	4000
Q	EQU	2350

R	EQU	100
S	EQU	10

;	MOVw	#5, T1
;	MOVw	#10, T2
	lbra celsius

;RunLoop:


;	ldd count
;	ldx #2
;	idiv
;	std tmp
;	ldaa tmp
;	cmpa #1
;	lbeq fahreinheit		
;Joanne's Loop

LED:	
	bclr PORTS, DISPA0|DISPA1

	ldab digit1
	jsr DispDigit
	jsr NoGhost
	
	bset PORTS, DISPA0
	bclr PORTS, DISPA1
	bset PORTS,DDP
	ldab digit2
	jsr DispDigit
	jsr NoGhost
	bclr PORTS,DDP
	
	bclr PORTS, DISPA0
	bset PORTS, DISPA1
	ldab digit3
	jsr DispDigit
	jsr NoGhost
	
	bset PORTS,DISPA0
	bset PORTS,DISPA1
	ldab digit4
	jsr DispDigit
	jsr NoGhost
	
	ldaa digit4
	cmpa #$0c
	lbeq celsius
	lbra fahreinheit


NoGhost:
	ldab #5
	jsr uS100Delay
	ldab #$ff
	jsr DispDigit
	rts			
i	ds.b	1
;num	dc.b	2,$0f,3,$0f
;num1	ds.w	1	
;-----------------------------------------------------	

value1	ds.w	1

dig1	ds.b	1
dig2	DS.B	1	
dig3	ds.b	1
digit1	ds.b	1
digit2	ds.b	1
digit3	ds.b	1
digit4	ds.b	1
	
count		ds.b	1	
oldvalue	ds.b	1
segAdd		ds.b	1
segVar0		ds.b	1
last		ds.w	1
periodT1	ds.w	1
periodT2	ds.w	1
T1		ds.w	1
T2		ds.w	1	
	
		jmp	ENTRY	
	

;subroutine libraries and constants
;subroutine libraries and constants in RAM
;try to put subroutine libraries in active development here
	;	INCLUDE "FpgaBrdLib.inc"
	;	INCLUDE "DaughterBrdLib.inc"
		INCLUDE "Timer.inc"
		INCLUDE "TimerTest.inc"
		INCLUDE "tempCalc.inc"
		
;tidy up RAM and switch to EEPROM
		INCLUDE "SwitchToEeprom.inc"
		
	
;subroutine libraries and constants in EEPROM
;use this space if RAM gets to full
;order so that more-stable libraries come before less-stable libraries
; ...
		INCLUDE "FpgaBrdLib.inc"
		INCLUDE "DaughterBrdLib.inc"				
		INCLUDE "remainderLib.inc"

	
		


		NOLIST
;These lines will abort assembly if too much EEProm is being used.
	if * > (EEBase + EESize)
		fail "Too much EEProm used"
	endif

		; ends assembly
		end
