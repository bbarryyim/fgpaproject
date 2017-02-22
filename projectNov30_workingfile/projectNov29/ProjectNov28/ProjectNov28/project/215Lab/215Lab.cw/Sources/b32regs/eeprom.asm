;
;	EEPROM Register definitions
;
EEMCR:	equ	RegBase+$f0	; EEPROM Module Configuration Register.
EEPROT:	equ	RegBase+$f1	; EEPROM Block Protect Register.
EETST:	equ	RegBase+$f2	; EEPROM Test Register.
EEPROG:	equ	RegBase+$f3	; EEPROM Control Register.
;
;
;	Bit definitions for the EEMCR register
;
EESWAI:	equ	$04		; enable (0)/disable (1) EEPROM in wait mode.
PROTLCK:	equ	$02		; lock (1)/unlock (0) block protect bits.
EERC:	equ	$01		; Use system clock (0)/RC clock (1) for charge pump.
;
;	Bit definitions for the EEPROT register
;
BPROT4:	equ	$10		; protect 256 bytes xd00 - xdff.
BPROT3:	equ	$08		; protect 256 bytes xe00 - xeff.
BPROT2:	equ	$04		; protect 128 bytes xf00 - xf7f.
BPROT1:	equ	$02		; protect 64 bytes xf80 - xfbf.
BPROT0:	equ	$01		; protect 64 bytes xfbf - xfff.
;
;	Bit definitions for the EETST register
;
EEODD:	equ	$80		; enable (1)/disable(0) odd row programming.
EEVEN:	equ	$40		; enable (1)/disable(0) even row programming.
MARG:	equ	$20		; enable (1)/disable(0) voltage margin test.
EECPD:	equ	$10		; enable (0)/disable(1) EEPROM charge pump.
EECPRD:	equ	$08		; enable (0)/disable(1) EEPROM charge pump ramp.
EECPM:	equ	$02		; (1) place EE charge pump voltage on IRQ/Vpp pin.
;
;	Bit definitions for the EEPROG register
;
BULKP:	equ	$80		; enable (0)/disable (1) EEPROM bulk erase.
BYTE:	equ	$10		; (0) bulk or row erase; (1) byte or word erase.
ROW:	equ	$08		; (0) erase entire EEPROM array; (1) erase 32-byte row.
ERASE:	equ	$04		; (0) program or read EEPROM; (1) erase EEPROM.
EELAT:	equ	$02		; enable (1)/disable(0) program/erase latches.
EEPGM:	equ	$01		; apply (1)/remove (0) Vpp from EEPROM array.
;
