;
;	Breakpoint Module Register and bit definitions
;
BRKCT0:	equ	RegBase+$20		; Breakpoint Control Register 0.
BRKCT1:	equ	RegBase+$21		; Breakpoint Control Register 1.
BRKAH:	equ	RegBase+$22		; Breakpoint Address Register, High Byte.
BRKAL:	equ	RegBase+$23		; Breakpoint Address Register, Low Byte.
BRKDH:	equ	RegBase+$24		; Breakpoint Data Register, High Byte.
BRKDL:	equ	RegBase+$25		; Breakpoint Data Register, Low Byte.
;
;	Bit definitions for the BRKCT0 register
;
BKEN1:	equ	$80		; Breakpoint mode enable 1.
BKEN0:	equ	$40		; Breakpoint mode enable 0.
BKPM:	equ	$20		; Break on program address.
BK1ALE:	equ	$08		; Breakpoint 1 range control.
BK0ALE:	equ	$04		; Breakpoint 0 range control.
;
;	Bit definitions for the BRKCT1 register
;
BKDBE:	equ	$40		; Enable data bus.
BKMBH:	equ	$20		; Breakpoint Mask High.
BKMBL:	equ	$10		; Breakpoint Mask Low.
BK1RWE:	equ	$08		; Breakpoint 1 R/w Compare Enable.
BK1RW:	equ	$04		; Breakpoint 1 R/w Compare Value.
BK0RWE:	equ	$02		; Breakpoint 0 R/w Compare Enable.
BK0RW:	equ	$01		; Breakpoint 0 R/w Compare Value.
;
