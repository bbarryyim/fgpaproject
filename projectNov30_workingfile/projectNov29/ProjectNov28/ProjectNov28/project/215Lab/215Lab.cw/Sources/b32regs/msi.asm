;
;	MSI Module Register and bit definitions
;
SC0BD:	equ	RegBase+$c0	; SCI 0 baud rate register word.
SC0BDH:	equ	RegBase+$c0	; SCI 0 baud rate register high byte.
SC0BDL:	equ	RegBase+$c1	; SCI 0 baud rate register low byte.
SC0CR1:	equ	RegBase+$c2	; SCI 0 control register 1.
SC0CR2:	equ	RegBase+$c3	; SCI 0 control register 2.
SC0SR1:	equ	RegBase+$c4	; SCI 0 status register 1.
SC0SR2:	equ	RegBase+$c5	; SCI 0 status register 2.
SC0DRH:	equ	RegBase+$c6	; SCI 0 data register high byte.
SC0DRL:	equ	RegBase+$c7	; SCI 0 data register low byte.
SP0CR1:	equ	RegBase+$d0	; SPI 0 control register 1.
SP0CR2:	equ	RegBase+$d1	; SPI 0 control register 2.
SP0BR:	equ	RegBase+$d2	; SPI 0 baud rate register.
SP0SR:	equ	RegBase+$d3	; SPI 0 status register.
SP0DR:	equ	RegBase+$d5	; SPI 0 data register.
PORTS:	equ	RegBase+$d6	; Port S data register.
DDRS:	equ	RegBase+$d7	; Port S data direction register.
PURDS:	equ	RegBase+$db	; Port S Pull-up and Reduced Drive Control Register.
;
;	Bit definitions for the SC0BDH register
;
BTST:	equ	$80		; reserved for factory test.
BSPL:	equ	$40		; reserved for factory test.
BRDL:	equ	$20		; reserved for factory test.
;
;	Bit definitions for the SC0CR1 register
;
LOOPS:	equ	$80		; Loop/Single wire mode select.
WOMS:	equ	$40		; Tx/Rx pin Open drain enable.
RSRC:	equ	$20		; Select receiver source.
M:	equ	$10		; Data length select control bit.
WAKE:	equ	$08		; Address Mark/Idle Line wake-up mode select.
ILT:	equ	$04		; short/long idle line wake-up mode select.
PE:	equ	$02		; parity enable/disable control bit.
PT:	equ	$01		; odd/even parity select control bit.
;
;	Bit definitions for the SC0CR2 register
;
TIE:	equ	$80		; Transmit interrupt enable.
TCIE:	equ	$40		; Transmit complete interrupt enable.
RIE:	equ	$20		; Receive interrupt enable.
ILIE:	equ	$10		; Idle line interrupt enable.
TE:	equ	$08		; Transmitter enable.
RE:	equ	$04		; Receiver enable.
RWU:	equ	$02		; Receiver wake-up mode enable.
SBK:	equ	$01		; Send break control bit.
;
;	Bit definitions for the SC0SR1 register
;
TDRE:	equ	$80		; Transmit data register empty status bit.
TC:	equ	$40		; Transmit data complete flag.
RDRF:	equ	$20		; Receive data register full flag.
IDLE:	equ	$10		; Receiver idle line detect flag.
OR:	equ	$08		; Receiver data overrun flag.
NF:	equ	$04		; Noise detect flag.
FE:	equ	$02		; Framing error flag.
PF:	equ	$01		; Parity error flag.
;
;	Bit definitions for the SC0SR2 register
;
RAF:	equ	$01		; receiver active flag.
;
;	Bit definitions for the SC0DRH register
;
R8:	equ	$80		; Received Ninth data bit.
T8:	equ	$40		; Transmitted Ninth data bit.
;
;	Bit definitions for the SP0CR1 register
;
SPIE:	equ	$80		; SPI interrupt enable.
SPE:	equ	$40		; SPI system enable.
SWOM:	equ	$20		; enable open drain outputs on pins PS7:PS4.
MSTR:	equ	$10		; Master/Slave mode select.
CPOL:	equ	$08		; Clock polarity select.
CPHA:	equ	$04		; Clock phase select.
SSOE:	equ	$02		; Slave select output enable.
LSBF:	equ	$01		; LSB first enable.
;
;	Bit definitions for the SP0CR2 register
;
PUPS:	equ	$08		; Port S pullup enable.
RDPS:	equ	$04		; Port S reduced drive enable.
SSWAI:	equ	$02		; Disable SPI system in WAIT mode.
SPC0:	equ	$01		; SPI pin control.
;
;	Bit definitions for the SP0SR register
;
SPIF:	equ	$80		; SPI interrupt flag.
WCOL:	equ	$40		; Write collision Flag.
MODF:	equ	$01		; SPI mode fault interrupt flag.
