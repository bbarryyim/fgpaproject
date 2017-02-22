;
;	Flash EEPROM Register definitions
;
FEELCK:	equ	RegBase+$00f4	; Flash EEPROM Lock Control Registers.
FEEMCR:	equ	RegBase+$00f5	; Flash EEPROM Module Configuration Register.
FEETST:	equ	RegBase+$00f6	; Flash EEPROM Module Test Register.
FEECTL:	equ	RegBase+$00f7	; Flash EEPROM Control Register.
;
;
;	Bit definitions for the FEELCK register
;
LOCK:	equ	$01		; enable/disable writes to FEEMCR register.
;
;	Bit definitions for the FEEMCR register
;
BOOTP:	equ	$01		; enable/disable erase & program of 1k-byte or 2k-byte bootblock.
;
;	Bit definitions for the FEETST register
;
FSTE:	equ	$80		; enable (1)/disable (0) gate/drain stress circuitry.
GADR:	equ	$40		; Select  drain (0) or gate (1) stress circuitry.
HVT:	equ	$20		; High voltage present (1)/not present (0) during stress test
FENLV:	equ	$10		; enable (1)/disable (0) low voltage xsistor in current ref. circuit.
FDISVFP:	equ	$08		; enable (0)/disable (1) automatic lock mechanism if Vfp is low.
VTCK:	equ	$04		; enable (1)/disable (0) Vt test.
STRE:	equ	$02		; enable (1)/disable (0) spare row test.
MWPR:	equ	$01		; enable (1)/disable (0) multiple word programming.
;
;	Bit definitions for the FEECTL register
;
FEESWAI:	equ	$10		; enable (0)/disable (1) Flash when in wait mode.
SVFP:	equ	$08		; Vfp present (1)/not present (0).
ERAS:	equ	$04		; configure for programming (0) or erase (1).
LAT:	equ	$02		; enable (1)/disable (0) programming/erase latches.
ENPE:	equ	$01		; apply (1)/remove (0) Vfp from Flash EEPROM array.
;
