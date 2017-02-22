;
NSCMode:	equ	$90		; run in normal single-chip mode.
;
RegBase:	equ	$0000		; base address of I/O register block.
INITRGDF:	equ	$0011		; default (out of reset) address of INITRG (I/O mapping register)
SysClock:	equ	8000000		; system clock frequency.
RAMBase:	equ	$0800		; base address of on chip RAM.
RAMSize:	equ	1024		; number of bytes of on-chip RAM
EEBase:	equ	$0d00		; base address of on-chip EEPROM.
EESize:	equ	768		; number of bytes of on-chip EEPROM.
FEEBase:	equ	$8000		; base address of on-chip Flash EEPROM.
FEESize:	equ	32768		; number of bytes of on-chip Flash EEPROM.
;
COPOff:	equ	0
COP1mS:	equ	1		; 1 mS timeout rate based on 8.0 Mhz clock.
COP4mS:	equ	2		; 4 mS timeout rate based on 8.0 Mhz clock.
COP16mS:	equ	3		; 16 mS timeout rate based on 8.0 Mhz clock.
COP65mS:	equ	4		; 65 mS timeout rate based on 8.0 Mhz clock.
COP262mS:	equ	5		; 262 mS timeout rate based on 8.0 Mhz clock.
COP524mS:	equ	6		; 524 mS timeout rate based on 8.0 Mhz clock.
COP1S:	equ	7		; 1 S timeout rate based on 8.0 Mhz clock.
;
