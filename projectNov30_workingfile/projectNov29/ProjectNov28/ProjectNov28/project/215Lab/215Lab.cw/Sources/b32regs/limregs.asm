;
;	LIM Module Register and bit definitions
;
PORTA:	equ	RegBase+$0000	; Port A data register.
PORTB:	equ	RegBase+$0001	; Port B data register.
DDRA:	equ	RegBase+$0002	; Port A data direction register.
DDRB:	equ	RegBase+$0003	; Port B data direction register.
PORTE:	equ	RegBase+$0008	; Port E data register.
DDRE:	equ	RegBase+$0009	; Port E data direction register.
PEAR:	equ	RegBase+$000a	; Port E pin asignment register.
MODE:	equ	RegBase+$000b	; CPU operating mode select register.
PUCR:	equ	RegBase+$000c	; Port A, B & E pullup control register.
RDRIV:	equ	RegBase+$000d	; Port A, B & E drive reduction control register.
INITRM:	equ	RegBase+$0010	; RAM base address register.
INITRG:	equ	RegBase+$0011	; I/O Register base address.
INITEE:	equ	RegBase+$0012	; EEPROM Base address.
MISC:	equ	RegBase+$0013	; miscellaneous control bit register.
RTICTL:	equ	RegBase+$0014	; Real Time Interrupt Control register.
RTIFLG:	equ	RegBase+$0015	; Real Time Interrupt Flag register.
COPCTL:	equ	RegBase+$0016	; Watchdog timer control register.
COPRST:	equ	RegBase+$0017	; Watchdog timer reset register.
ITST0:	equ	RegBase+$0018	; Interrupt test register #0
ITST1:	equ	RegBase+$0019	; Interrupt test register #1
ITST2:	equ	RegBase+$001a	; Interrupt test register #2
ITST3:	equ	RegBase+$001b	; Interrupt test register #3
INTCR:	equ	RegBase+$001e	; IRQ Interrupt Control Register.
HPRIO:	equ	RegBase+$001f	; Highest priority interrupt source.
;
;	Bit definitions for the PEAR register
;
NDBE:	equ	$80		; enable/disable the DBE control signal on pin PE7.
PIPOE:	equ	$20		; enable/disable pipe signals on pins PE5 & PE6.
NECLK:	equ	$10		; enable/disable the E-clock on pin PE4.
LSTRE:	equ	$08		; enable/disable the low strobe signal on pin PE3.
RDWE:	equ	$04		; enable/disable the R/w signal onpin PE2.
;
;
;	Bit definitions for the MODE register
;
SMODN:	equ	$80		; Special mode select bit.
MODB:	equ	$40		; Mode control 'B' bit.
MODA:	equ	$20		; Mode control 'A' bit.
ESTR:	equ	$10		; E-clock stretch enable bit.
IVIS:	equ	$08		; Internal visibility enable bit.
EBSWAI:	equ	$04		; External bus stop control bit in WAIT mode.
EME:	equ	$01		; Emulate port E control bit.
;
;
;	Bit definitions for the PUCR register
;
PUPK:	equ	$80		; Port K pullup enable control bit.
PUPJ:	equ	$40		; Port J pullup enable control bit.
PUPH:	equ	$20		; Port H pullup enable control bit.
PUPE:	equ	$10		; Port E pullup enable control bit.
PUPB:	equ	$02		; Port B pullup enable control bit.
PUPA:	equ	$01		; Port A pullup enable control bit.
;
;
;	Bit definitions for the RDRIV register
;
RDPK:	equ	$80		; Port K reduced drive control bit.
RDPJ:	equ	$40		; Port J reduced drive control bit.
RDPH:	equ	$20		; Port H reduced drive control bit.
RDPE:	equ	$10		; Port E reduced drive control bit.
RDPB:	equ	$02		; Port B reduced drive control bit.
RDPA:	equ	$01		; Port A reduced drive control bit.
;
;
;	Bit definitions for the INITRG register
;
MMSWAI:	equ	$01
;
;
;	Bit definitions for the INITEE register
;
EEON:	equ	$01		; EEPROM enable control bit.
;
;
;	Bit definitions for the MISC control register
;
NDRF:	equ	$40		; Narrow Data Bus for Register-Following Map.
RFSTR1:	equ	$20		; Register-Following Stretch bit #1.
RFSTR0:	equ	$10		; Register-Following Stretch bit #0.
EXSTR1:	equ	$08		; External Access stretch bit #1.
EXSTR0:	equ	$04		; External Access stretch bit #0.
MAPROM:	equ	$02		; memory map location of on-chip Flash EEPROM.
ROMON:	equ	$01		; Flash EEPROM enable bit.
;
;
;	Bit definitions for the RTICTL control register
;
RTIE:	equ	$80		; real time interrupt enable control bit.
RSWAI:	equ	$40		; disable COP & RTI when in WAIT mode.
RSBCK:	equ	$20		; disable COP & RTI when in background mode.
RTBPY:	equ	$08		; RTI prescaler bypass.
;
;
;	Bit definitions for the RTIFLG control register
;
RTIF:	equ	$80		; Real Time Interrupt Flag bit.
;
;
;	Bit definitions for the COPCTL control register
;
CME:	equ	$80		; Clock monitor control bit.
FCME:	equ	$40		; Force clock monitor control bit.
FCM:	equ	$20		; Force clock monitor reset.
FCOP:	equ	$10		; Force a watchdog timer reset.
DISR:	equ	$08		; Disable resets from watchdog timer & clock monitor.
;
;
;	Bit definitions for the INTCR control register
;
IRQE:	equ	$80		; IRQ edge sensitive only select.
IRQEN:	equ	$40		; External IRQ enable.
DLY:	equ	$40		; Enable oscillator start-up delay on exit from STOP mode.
;
