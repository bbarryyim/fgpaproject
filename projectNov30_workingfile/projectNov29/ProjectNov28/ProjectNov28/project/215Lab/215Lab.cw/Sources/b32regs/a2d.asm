;
;	A-to-D Module Register and bit definitions
;
ATDCTL0:	equ	RegBase+$0060	; Reserved.
ATDCTL1:	equ	RegBase+$0061	; Reserved.
ATDCTL2:	equ	RegBase+$0062	; A-to-D Control register 2.
ATDCTL3:	equ	RegBase+$0063	; A-to-D Control register 3.
ATDCTL4:	equ	RegBase+$0064	; A-to-D Control register 4.
ATDCTL5:	equ	RegBase+$0065	; A-to-D Control register 5.
ATDSTATH:	equ	RegBase+$0066	; A-to-D status register high byte.
ATDSTATL:	equ	RegBase+$0067	; A-to-D status register low byte.
ATDTSTH:	equ	RegBase+$0068	; A-to-D test register high byte.
ATDTSTL:	equ	RegBase+$0069	; A-to-D test register low byte.
PORTAD:	equ	RegBase+$006f	; Port AD Input Register.
ADR0:	equ	RegBase+$0070	; A-to-D Result register 0.
ADR1:	equ	RegBase+$0072	; A-to-D Result register 1.
ADR2:	equ	RegBase+$0074	; A-to-D Result register 2.
ADR3:	equ	RegBase+$0076	; A-to-D Result register 3.
ADR4:	equ	RegBase+$0078	; A-to-D Result register 4.
ADR5:	equ	RegBase+$007a	; A-to-D Result register 5.
ADR6:	equ	RegBase+$007c	; A-to-D Result register 6.
ADR7:	equ	RegBase+$007e	; A-to-D Result register 7.
ADR0H:	equ	RegBase+$0070	; A-to-D Result register 0.
ADR1H:	equ	RegBase+$0072	; A-to-D Result register 1.
ADR2H:	equ	RegBase+$0074	; A-to-D Result register 2.
ADR3H:	equ	RegBase+$0076	; A-to-D Result register 3.
ADR4H:	equ	RegBase+$0078	; A-to-D Result register 4.
ADR5H:	equ	RegBase+$007a	; A-to-D Result register 5.
ADR6H:	equ	RegBase+$007c	; A-to-D Result register 6.
ADR7H:	equ	RegBase+$007e	; A-to-D Result register 7.
;
;
;	Bit definitions for the ATDCTL2 register
;
ADPU:	equ	$80		; enable/disable A-to-D module.
AFFC:	equ	$40		; A-to-D Fast Flag Clear All Control bit.
ASWAI:	equ	$20		; Stop A-to-D module in Wait mode.
ASCIE:	equ	$02		; A-to-D Sequence complete Interrupt Enable.
ASCIF:	equ	$01		; A-to-D Sequence complete Interrupt Flag.
;
;	Bit definitions for the ATDCTL3 register
;
FRZ1:	equ	$02		; A-to-D module mode in Background.
FRZ0:	equ	$01		; A-to-D module mode in Background.
;
;	Bit definitions for the ATDCTL4 register
;
RES10:	equ	$80		; A-to-D resolution select bit.
SMP1:	equ	$40		; A-to-D sample time select.
SMP0:	equ	$20		; A-to-D sample time select.
;
;	Bit definitions for the ATDCTL5 register
;
S8CM:	equ	$40		; Select number of channels to convert.
SCAN:	equ	$20		; Enable continuous channel scan.
MULT:	equ	$10		; Enable multi-channel conversion.
;
;	Bit definitions for the ATDSTATH register
;
SCF:	equ	$80		; Sequence complete flag.
;
;	Bit definitions for the ATDSTATL register
;
CCF7:	equ	$80		; Channel 7 conversion complete flag.
CCF6:	equ	$40		; Channel 6 conversion complete flag.
CCF5:	equ	$20		; Channel 5 conversion complete flag.
CCF4:	equ	$10		; Channel 4 conversion complete flag.
CCF3:	equ	$08		; Channel 3 conversion complete flag.
CCF2:	equ	$04		; Channel 2 conversion complete flag.
CCF1:	equ	$02		; Channel 1 conversion complete flag.
CCF0:	equ	$01		; Channel 0 conversion complete flag.
;
;	Bit definitions for the ATDTESTL register
;
RST:	equ	$20		; Module reset control bit.
TSTOUT:	equ	$10		; Mux. output of TST[3:0].
