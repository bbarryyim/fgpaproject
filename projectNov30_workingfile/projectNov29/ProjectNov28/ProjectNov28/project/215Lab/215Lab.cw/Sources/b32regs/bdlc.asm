;
;	BDLC Module Register and bit definitions
;
BCR1:	equ	RegBase+$00f8	; BDLC Control Register 1.
BSVR:	equ	RegBase+$00f9	; BDLC State Vector Register.
BCR2:	equ	RegBase+$00fa	; BDLC Control Register 2.
BDR:	equ	RegBase+$00fb	; BDLC Data Register.
BARD:	equ	RegBase+$00fc	; BDLC Analog Roundtrip Delay Register.
DLCSCR:	equ	RegBase+$00fd	; Port DLC Control Register.
PORTDLC:	equ	RegBase+$00fe	; Port DLC Data Register.
DDRDLC:	equ	RegBase+$00ff	; Port DLC Data Direction Register.
;
;	Bit definitions for the BCR1 register
;
IMSG:	equ	$80		; Ignore incomming message control bit.
CLCKS:	equ	$40		; Integer/binary clovk source select.
R1:	equ	$20		; BDLC clock rate select bit 1.
R0:	equ	$10		; BDLC clock rate select bit 0.
IE:	equ	$02		; BDLC Interrupt enable.
WCM:	equ	$01		; Stop BDLC in CPU WAIT mode.
;
;	Bit definitions for the BCR2 register
;
ALOOP:	equ	$80		; Put BDLC in analog loopback mode.
DLOOP:	equ	$40		; Put BDLC in digital loopback mode.
RX4XE:	equ	$20		; Enable 4x receive mode.
NBFS:	equ	$10		; Normalization Bit Format select.
TEOD:	equ	$08		; Xmit End Of Data (8-bit CRC).
TSIFR:	equ	$04		; Xmit In-frame response.
TMIFR1:	equ	$02		; Xmit multi-byte In-frame response w/ CRC.
TMIFR0:	equ	$01		; Xmit multi-byte In-frame response w/o CRC.
;
;	Bit definitions for the BARD register
;
ATE:	equ	$80		; On-chip analog transceiver enable.
RXPOL:	equ	$40		; Receive pin polarity.
;
;	Bit definitions for the BDLSCR register
;
BDLCEN:	equ	$04		; BDLC Enable.
PUPDLC:	equ	$02		; Port DLC active pull-up enable.
RDPDLC:	equ	$01		; Port DLC reduced enable.
