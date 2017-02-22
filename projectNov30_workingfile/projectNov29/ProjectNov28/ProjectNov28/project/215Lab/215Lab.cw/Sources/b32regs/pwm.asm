;
;	PWM Register definitions
;
PWCLK:	equ	RegBase+$0040	; PWM Clocks and Concatenate Register.
PWPOL:	equ	RegBase+$0041	; PWM Clock & Polarity Select Register.
PWEN:	equ	RegBase+$0042	; PWM Channel Enable Register.
PWPRES:	equ	RegBase+$0043	; PWM Prescaler Counter Register.
PWSCAL0:	equ	RegBase+$0044	; PWM Scale Register #0.
PWSCNT0:	equ	RegBase+$0045	; PWM Scale Counter Value #0.
PWSCAL1:	equ	RegBase+$0046	; PWM Scale Register #1.
PWSCNT1:	equ	RegBase+$0047	; PWM Scale Counter Value #1.
PWCNT0:	equ	RegBase+$0048	; PWM Channel #0 Counter Register.
PWCNT1:	equ	RegBase+$0049	; PWM Channel #1 Counter Register.
PWCNT2:	equ	RegBase+$004a	; PWM Channel #2 Counter Register.
PWCNT3:	equ	RegBase+$004b	; PWM Channel #3 Counter Register.
PWPER0:	equ	RegBase+$004c	; PWM Channel #0 Period Register.
PWPER1:	equ	RegBase+$004d	; PWM Channel #1 Period Register.
PWPER2:	equ	RegBase+$004e	; PWM Channel #2 Period Register.
PWPER3:	equ	RegBase+$004f	; PWM Channel #3 Period Register.
PWDTY0:	equ	RegBase+$0050	; PWM Channel #0 Duty Cycle Register.
PWDTY1:	equ	RegBase+$0051	; PWM Channel #1 Duty Cycle Register.
PWDTY2:	equ	RegBase+$0052	; PWM Channel #2 Duty Cycle Register.
PWDTY3:	equ	RegBase+$0053	; PWM Channel #3 Duty Cycle Register.
PWCTL:	equ	RegBase+$0054	; PWM Control Register.
PWTST:	equ	RegBase+$0055	; PWM test register.
PORTP:	equ	RegBase+$0056	; Port P data register.
DDRP:	equ	RegBase+$0057	; Port data direction register.
;
;	Bit definitions for the PWCLK register
;
CON23:	equ	$80		; enable concatenation of channels 2 & 3.
CON01:	equ	$40		; enable concatenation of channels 0 & 1.
PCKA2:	equ	$20		; Prescaler bit 2 for clock A source.
PCKA1:	equ	$10		; Prescaler bit 1 for clock A source.
PCKA0:	equ	$08		; Prescaler bit 0 for clock A source.
PCKB2:	equ	$04		; Prescaler bit 2 for clock B source.
PCKB1:	equ	$02		; Prescaler bit 1 for clock B source.
PCKB0:	equ	$01		; Prescaler bit 0 for clock B source.
;
;	Bit definitions for the PWPOL register
;
PCLK3:	equ	$80		; PWM Channel 3 clock select.
PCLK2:	equ	$40		; PWM Channel 2 clock select.
PCLK1:	equ	$20		; PWM Channel 1 clock select.
PCLK0:	equ	$10		; PWM Channel 0 clock select.
PPOL3:	equ	$08		; PWM Channel 3 polarity select.
PPOL2:	equ	$04		; PWM Channel 2 polarity select.
PPOL1:	equ	$02		; PWM Channel 1 polarity select.
PPOL0:	equ	$01		; PWM Channel 0 polarity select.
;
;	Bit definitions for the PWEN register
;
PWEN3:	equ	$08		; PWM Channel 3 enable.
PWEN2:	equ	$04		; PWM Channel 2 enable.
PWEN1:	equ	$02		; PWM Channel 1 enable.
PWEN0:	equ	$01		; PWM Channel 0 enable.
;
;	Bit definitions for the PWCTL register
;
PSWAI:	equ	$10		; Stop PWM Channels in Wait mode.
CENTR:	equ	$08		; Center-aligned output mode.
RDPP:	equ	$04		; enable/disable reduced drive on Port P.
PUPP:	equ	$02		; enable/disable pull-ups on Port P.
PSBCK:	equ	$01		; Stop PWM Channels in Background mode.
;
;	Bit definitions for the PWTST register
;
DISCR:	equ	$80		; Disable reset of channel counter on write to channel counter.
DISCP:	equ	$40		; Disable compare count period.
DISCAL:	equ	$20		; Disable load of scale-counters on write to associated scale-registers.
