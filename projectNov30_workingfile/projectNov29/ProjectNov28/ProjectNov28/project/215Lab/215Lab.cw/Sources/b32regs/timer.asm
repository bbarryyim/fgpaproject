;
;	Standard Timer Module Register and bit definitions
;
TIOS:	equ	RegBase+$0080	; Timer Input Capture/Output Compare Select.
CFORC:	equ	RegBase+$0081	; Timer Compare Force Register.
OC7M:	equ	RegBase+$0082	; Output Compare 7 Mask Register.
OC7D:	equ	RegBase+$0083	; Output Compare 7 Data Register.
TCNT:	equ	RegBase+$0084	; Timer Count Register.
TSCR:	equ	RegBase+$0086	; Timer System Control Register.
TQCR:	equ	RegBase+$0087	; Reserved for future use.
TCTL1:	equ	RegBase+$0088	; Timer Control Register #1.
TCTL2:	equ	RegBase+$0089	; Timer Control Register #2.
TCTL3:	equ	RegBase+$008a	; Timer Control Register #3.
TCTL4:	equ	RegBase+$008b	; Timer Control Register #4.
TMSK1:	equ	RegBase+$008c	; Timer Interrupt Mask #1.
TMSK2:	equ	RegBase+$008d	; Timer Interrupt Mask #2.
TFLG1:	equ	RegBase+$008e	; Timer Interrupt Flag #1.
TFLG2:	equ	RegBase+$008f	; Timer Interrupt Flag #2.
TC0:	equ	RegBase+$0090	; Input Capture/Output Compare Channel 0.
TC1:	equ	RegBase+$0092	; Input Capture/Output Compare Channel 1.
TC2:	equ	RegBase+$0094	; Input Capture/Output Compare Channel 2.
TC3:	equ	RegBase+$0096	; Input Capture/Output Compare Channel 3.
TC4:	equ	RegBase+$0098	; Input Capture/Output Compare Channel 4.
TC5:	equ	RegBase+$009a	; Input Capture/Output Compare Channel 5.
TC6:	equ	RegBase+$009c	; Input Capture/Output Compare Channel 6.
TC7:	equ	RegBase+$009e	; Input Capture/Output Compare Channel 7.
PACTL:	equ	RegBase+$00a0	; Pulse accumulator control register.
PAFLG:	equ	RegBase+$00a1	; Pulse accumulator flag register.
PACNT:	equ	RegBase+$00a2	; 16-bit pulse accumulator count register.
TIMTST:	equ	RegBase+$00ad	; Timer test register.
PORTT:	equ	RegBase+$00ae	; Timer port data register.
PORTTD:	equ	RegBase+$00af	; Timer port data direction register.
DDRT:	equ	RegBase+$00af	; Timer port data direction register.
;
;	Bit definitions for the TIOS register
;
IOS7:	equ	$80		; Input Capture/Output Compare Select Channel 7.
IOS6:	equ	$40		; Input Capture/Output Compare Select Channel 6.
IOS5:	equ	$20		; Input Capture/Output Compare Select Channel 5.
IOS4:	equ	$10		; Input Capture/Output Compare Select Channel 4.
IOS3:	equ	$08		; Input Capture/Output Compare Select Channel 3.
IOS2:	equ	$04		; Input Capture/Output Compare Select Channel 2.
IOS1:	equ	$02		; Input Capture/Output Compare Select Channel 1.
IOS0:	equ	$01		; Input Capture/Output Compare Select Channel 0.
;
;	Bit definitions for the CFORC register
;
FOC7:	equ	$80		; Force Compare Select On Channel 7.
FOC6:	equ	$40		; Force Compare Select On Channel 6.
FOC5:	equ	$20		; Force Compare Select On Channel 5.
FOC4:	equ	$10		; Force Compare Select On Channel 4.
FOC3:	equ	$08		; Force Compare Select On Channel 3.
FOC2:	equ	$04		; Force Compare Select On Channel 2.
FOC1:	equ	$02		; Force Compare Select On Channel 1.
FOC0:	equ	$01		; Force Compare Select On Channel 0.
;
;	Bit definitions for the OC7M register
;
OC7M7:	equ	$80		; Force Compare Mask For Channel 7.
OC7M6:	equ	$40		; Force Compare Mask For Channel 6.
OC7M5:	equ	$20		; Force Compare Mask For Channel 5.
OC7M4:	equ	$10		; Force Compare Mask For Channel 4.
OC7M3:	equ	$08		; Force Compare Mask For Channel 3.
OC7M2:	equ	$04		; Force Compare Mask For Channel 2.
OC7M1:	equ	$02		; Force Compare Mask For Channel 1.
OC7M0:	equ	$01		; Force Compare Mask For Channel 0.
;
;	Bit definitions for the OC7D register
;
OC7D7:	equ	$80		; Force Compare Data For Channel 7.
OC7D6:	equ	$40		; Force Compare Data For Channel 6.
OC7D5:	equ	$20		; Force Compare Data For Channel 5.
OC7D4:	equ	$10		; Force Compare Data For Channel 4.
OC7D3:	equ	$08		; Force Compare Data For Channel 3.
OC7D2:	equ	$04		; Force Compare Data For Channel 2.
OC7D1:	equ	$02		; Force Compare Data For Channel 1.
OC7D0:	equ	$01		; Force Compare Data For Channel 0.
;
;	Bit definitions for the TSCR register
;
TEN:	equ	$80		; Timer Enable.
TSWAI:	equ	$40		; Stop Timer in Wait Mode.
TSBCK:	equ	$20		; Stop Timer in Background Mode.
TFFCA:	equ	$10		; Timer Fast Flag Clear Mode.
;
;	Bit definitions for the TCTL1 register
;
OM7:	equ	$80		; Output Mode For Channel 7.
OL7:	equ	$40		; Output Level For Channel 7.
OM6:	equ	$20		; Output Mode For Channel 6.
OL6:	equ	$10		; Output Level For Channel 6.
OM5:	equ	$08		; Output Mode For Channel 5.
OL5:	equ	$04		; Output Level For Channel 5.
OM4:	equ	$02		; Output Mode For Channel 4.
OL4:	equ	$01		; Output Level For Channel 4.
;
;	Bit definitions for the TCTL2 register
;
OM3:	equ	$80		; Output Mode For Channel 3.
OL3:	equ	$40		; Output Level For Channel 3.
OM2:	equ	$20		; Output Mode For Channel 2.
OL2:	equ	$10		; Output Level For Channel 2.
OM1:	equ	$08		; Output Mode For Channel 1.
OL1:	equ	$04		; Output Level For Channel 1.
OM0:	equ	$02		; Output Mode For Channel 0.
OL0:	equ	$01		; Output Level For Channel 0.
;
;	Bit definitions for the TCTL3 register
;
EDG7B:	equ	$80		; Input Capture Edge Control For Channel 7.
EDG7A:	equ	$40		; Input Capture Edge Control For Channel 7.
EDG6B:	equ	$20		; Input Capture Edge Control For Channel 6.
EDG6A:	equ	$10		; Input Capture Edge Control For Channel 6.
EDG5B:	equ	$08		; Input Capture Edge Control For Channel 5.
EDG5A:	equ	$04		; Input Capture Edge Control For Channel 5.
EDG4B:	equ	$02		; Input Capture Edge Control For Channel 4.
EDG4A:	equ	$01		; Input Capture Edge Control For Channel 4.
;
;	Bit definitions for the TCTL4 register
;
EDG3B:	equ	$80		; Input Capture Edge Control For Channel 3.
EDG3A:	equ	$40		; Input Capture Edge Control For Channel 3.
EDG2B:	equ	$20		; Input Capture Edge Control For Channel 2.
EDG2A:	equ	$10		; Input Capture Edge Control For Channel 2.
EDG1B:	equ	$08		; Input Capture Edge Control For Channel 1.
EDG1A:	equ	$04		; Input Capture Edge Control For Channel 1.
EDG0B:	equ	$02		; Input Capture Edge Control For Channel 0.
EDG0A:	equ	$01		; Input Capture Edge Control For Channel 0.
;
;	Bit definitions for the TMSK1 register
;
C7I:	equ	$80		; Channel 7 Interrupt Enable.
C6I:	equ	$40		; Channel 6 Interrupt Enable.
C5I:	equ	$20		; Channel 5 Interrupt Enable.
C4I:	equ	$10		; Channel 4 Interrupt Enable.
C3I:	equ	$08		; Channel 3 Interrupt Enable.
C2I:	equ	$04		; Channel 2 Interrupt Enable.
C1I:	equ	$02		; Channel 1 Interrupt Enable.
C0I:	equ	$01		; Channel 0 Interrupt Enable.
;
;	Bit definitions for the TMSK2 register
;
TOI:	equ	$80		; Timer Overflow Interrupt Enable.
PUPT:	equ	$20		; Port T Pull-up Resistor Enable.
RDPT:	equ	$10		; Port T Reduced Drive Enable.
TCRE:	equ	$08		; Timer Counter Reset Enable.
PR2:	equ	$04		; Timer Prescaler Select Bit 2.
PR1:	equ	$02		; Timer Prescaler Select Bit 1.
PR0:	equ	$01		; Timer Prescaler Select Bit 0.
;
;	Bit definitions for the TFLG1 register
;
C7F:	equ	$80		; Channel 7 Interrupt Flag.
C6F:	equ	$40		; Channel 6 Interrupt Flag.
C5F:	equ	$20		; Channel 5 Interrupt Flag.
C4F:	equ	$10		; Channel 4 Interrupt Flag.
C3F:	equ	$08		; Channel 3 Interrupt Flag.
C2F:	equ	$04		; Channel 2 Interrupt Flag.
C1F:	equ	$02		; Channel 1 Interrupt Flag.
C0F:	equ	$01		; Channel 0 Interrupt Flag.
;
;	Bit definitions for the TFLG2 register
;
TOF:	equ	$80		; Timer Overflow Interrupt Flag.
;
;	Bit definitions for the PACTL register
;
PAEN:	equ	$40		; Pulse Accumulator System Enable.
PAMOD:	equ	$20		; Pulse Accumulator Mode Select.
PEDGE:	equ	$10		; Pulse Accumulator Edge Select.
CLK1:	equ	$08		; Pulse Accumulator Clock Select.
CLK0:	equ	$04		; Pulse Accumulator Clock Select.
PAOVI:	equ	$02		; Pulse Accumulator Overflow Interrupt Enable.
PAI:	equ	$01		; Pulse Accumulator Input Interrupt Enable.
;
;	Bit definitions for the PAFLG register
;
PAOVF:	equ	$02		; Pulse Accumulator Overflow Interrupt Flag.
PAIF:	equ	$01		; Pulse Accumulator Input Interrupt Flag.
;
;	Bit definitions for the TIMTST register
;
TCBYP:	equ	$02		; Timer Divider Chain Bypass.
PCBYP:	equ	$01		; Pulse Accumulator Divider Chain Bypass.
;
