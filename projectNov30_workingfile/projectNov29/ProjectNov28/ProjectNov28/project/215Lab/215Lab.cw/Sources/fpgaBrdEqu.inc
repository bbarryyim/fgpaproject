	ifndef FPGA_BRD_INC
FPGA_BRD_INC	set	1
 
; ENSC 151 FPGA board equates
; Created by Craig Scratchley for Spring term 2007
; Copyright (C) 2004-2007 School of Engineering Science, SFU, Burnaby, BC, Canada
; You can modify this software under the terms of the GNU General Public License
; Please add to this file as necessary and contribute your
;	changes (send email to wcs@sfu.ca)

;Notes:  an "n" in a symbol means "active low"

;ENSC 151 FPGA board masks

;Port E masks
nRST1		EQU	%01000000 ; device #1 (switches/LCD_Busy) reset
nRST2		EQU	%10000000 ; device #2 (external) reset
LcdStatus	EQU	%00001000 ; LCD status
Status2		EQU	%00100000 ; device #2 (external) status
CheckLcdBusy	EQU	%00000100 ; request LCD interrupt
;end of Port E equates

;Port P masks
AudRt		EQU	%00001000 ; Audio right channel
AudLt		EQU	%00000100 ; Audio left channel
;end of Port P equates

;Port B masks
LED1		EQU	%10000000 ; LED1

LcdE		EQU	%00010000 ; LCD Operation (Data read/write) Enable
EClk		EQU	LcdE	  ; for compatibility with Doughman
LcdRnW		EQU	%00100000 ; LCD Read (1) or Write (0)
Rw		EQU	LcdRnW	  ; for compatibility with Doughman
LcdRS_DnI	EQU	%01000000 ; LCD Register Select
					; 1 = Data (Read and Write)
					; 0 = Instruction (Write)
					; 0 = BusyFlag/Address (Read)
RS		EQU	LcdRS_DnI ; for compatibility with Doughman	
					
; Push Button Switches, normally open (1 = normal, 0 = pushed)
nSw4B		EQU	%00001000 ; Blue
nSw3WG		EQU	%00000100 ; White/Grey
nSw2RO		EQU	%00000010 ; Red/Orange
nSw1Y		EQU	%00000001 ; Yellow
;end of Port B equates

;Port A masks
LcdBusy		EQU	%10000000 ; Busy Flag
BUSY		EQU	LcdBusy   ; for compatibility with Doughman
LcdAddrCntr	EQU	%01111111 ; Address Counter
;end of Port A masks

;More LCD stuff

LcdDispClr	EQU	%00000001	; Display Clear
ClrDisp:	equ	LcdDispClr	; for compatibility with Doughman

LcdDispCursHome	EQU	%00000010	; Display/Cursor Home
CursHome	equ	LcdDispCursHome	; for compatibility with Doughman

LcdEntMdSet	EQU	%00000100	; Entry Mode Set	
LcdInD		EQU	%00000010	; 1 = Increment, 0 = Decrement
LcdS		EQU	%00000001	; Display Shift On

LcdDispOnOff	EQU	%00001000	; LCD Display On/Off
LcdD		EQU	%00000100	; Display turned on
LcdC		EQU	%00000010	; Cursor displayed
LcdB		EQU	%00000001	; Character blinks

LcdDispCursShft EQU	%00010000	; Display/Cursor Shift
LcdSnC		EQU	%00001000	; 1 = Shift Display, 0 = Move Cursor
LcdRnL		EQU	%00000100	; 1 = Shift Right, 0 = Shift Left

LcdFuncSet	EQU	%00100000	; LCD Function Set
LcdDL		EQU	%00010000	; 1 = 8-Bit, 0 = 4Bit
LcdN		EQU	%00001000	; 1 = Dual Line, 0 = Single Line
LcdF		EQU	%00000100	; 1 = 5x10 font??, 0 = 5x7 font

LcdCgRam	EQU	%01000000	; CG RAM Address Set (Character Generator)
LcdDdRam	EQU	%10000000	; DD RAM Address Set (Display Data)
SetCurs		equ	LcdDdRam	; for compatibility with Doughman

Line1:		equ	$80
Line2:		equ	$c0

	endif ; FPGA_BRD_INC
