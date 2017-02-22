;
;	Clock Synthesizer Module Register and bit definitions
;
SYNR:	equ	RegBase+$0038	; Synthesizer loop count register.
REFDV:	equ	RegBase+$0039	; Synthesizer reference divider register.
CGTFLG:	equ	RegBase+$003a	; Clock generator test register.
PLLFLG:	equ	RegBase+$003b	; PLL Flag register.
PLLCR:	equ	RegBase+$003c	; PLL control register.
CLKSEL:	equ	RegBase+$003d	; Clock generator Clock select register.
SLOW:	equ	RegBase+$003e	; Slow mode divider register.
CGTCTL:	equ	RegBase+$003f	; Clock generator test control register.
;
;	Bit definitions for the PLLFLG register
;
LOCKIF:	equ	$80		; PLL lock interrupt flag.
LOCK:	equ	$40		; PLL locked flag.
LHIF:	equ	$02		; Limp-Home interrupt flag.
LHOME:	equ	$01		; Limp-Home mode status.
;
;	Bit definitions for the PLLCR register
;
LOCKIE:	equ	$80		; PLL lock interrupt enable.
PLLON:	equ	$40		; PLL on/off control bit.
AUTO:	equ	$20		; PLL automatic bandwidth control.
ACQ:	equ	$10		; PLL not in acquisition.
PSTP:	equ	$04		; Pseudo-STOP Enable control bit.
LHIE:	equ	$02		; Limp-Home Interrupt Enable.
NOLHM:	equ	$01		; Limp-Home mode disable/enable.
;
;	Bit definitions for the CLKSEL register
;
BCSP:	equ	$40		; SYSCLK (bus) source select.
BCSS:	equ	$20		; SYSCLK (bus) slow mode clock select.
MCS:	equ	$04		; Module clock source select.
;
;	Bit definitions for the CGTCTL register
;
OPNLE:	equ	$80		;
TRK:	equ	$40		;
TSTCLKE:	equ	$20		;
