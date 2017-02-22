;
;	Configuration values for MC68HC912B32
;
MISConfig:	equ	ROMON+MAPROM
OprMode:	equ	$90		; run in normal single-chip mode.
;
RegBase:	equ	$0000		; base address of I/O register block.
INITRGDF:	equ	$0011		; default (out of reset) of INITRG (I/O mapping register)
SysClock:	equ	8000000		; system clock frequency.
RAMBase:	equ	$0800		; base address of on chip RAM.
RAMSize:	equ	1024		; number of bytes of on-chip RAM
EEBase:	equ	$0d00		; base address of on-chip EEPROM.
EESize:	equ	768		; number of bytes of on-chip EEPROM.
FEEBase:	equ	$8000		; base address of on-chip Flash EEPROM.
FEESize:	equ	32768		; number of bytes of on-chip Flash EEPROM.
;
COPOff:	equ	0
COPRate1:	equ	1
COPRate2:	equ	2
COPRate3:	equ	3
COPRate4:	equ	4
COPRate5:	equ	5
COPRate6:	equ	6
COPRate7:	equ	7
