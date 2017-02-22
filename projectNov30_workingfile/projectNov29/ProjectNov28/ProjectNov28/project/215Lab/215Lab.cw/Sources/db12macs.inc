	ifndef DB12MACS_INC
DB12MACS_INC	set	1 
; Macros (and equates) for D-Bug12 on 68HC12 EVBs
; Modified by Craig Scratchley

; The label "Version" should be set to the D-Bug12 version number that is being ; used.
; For example, if the D-Bug12 version number is 1.0.4, Version should be set to ; 104.
;
Version:	equ	200		; Actually 2.0.A
;
		if Version=102
;
;
; constants used with the SetUserVector() function to set the address of user ;supplied
; interrupt service routines. These constants are only for use with D-Bug12 ;version 1.0.2.
;
UserPortHKWU:	equ	7	; PortH key wake-up user interrupt
UserPortJKWU:	equ	8 	; PortJ key wake-up user interrupt
UserAtoD:	equ	9	; A-to-D user interrupt
UserSCI1:	equ	10	; SCI #1 user interrupt (not available in the MC68HC912B32)
UserSCI0:	equ	11	; SCI #0 user interrupt
UserSPI0:	equ	12	; SPI #0 user interrupt
UserTimerCh0:	equ	13	; Timer Channel #0 user interrupt
UserTimerCh1:	equ	14	; Timer Channel #1 user interrupt
UserTimerCh2:	equ	15	; Timer Channel #2 user interrupt
UserTimerCh3:	equ	16 	; Timer Channel #3 user interrupt
UserTimerCh4:	equ	17	; Timer Channel #4 user interrupt
UserTimerCh5:	equ	18	; Timer Channel #5 user interrupt
UserTimerCh6:	equ	19	; Timer Channel #6 user interrupt
UserTimerCh7:	equ	20	; Timer Channel #7 user interrupt
UserPAccOvf:	equ	21	; Pulse Accumulator Overflow user interrupt
UserPAccEdge:	equ	22	; Pulse Accumulator Edge user interrupt
UserTimerOvf:	equ	23	; Timer counter overflow user interrupt
UserRTI:	equ	24	; Real Time Interrupt user interrupt
UserIRQ:	equ 	25	; CPU Maskable Interrupt request user interrupt
UserXIRQ: 	equ 	26	; CPU Non-maskable Interrupt request user interrupt
UserSWI: 	equ	27 	; Software Interrupt user interrupt
UserTrap: 	equ 	28 	; Instruction Trap user interrupt
RAMVectAddr: 	equ 	-1 	; returns the base address of the RAM interrupt vector table.
;
		else
;
; constants used with the SetUserVector() function to set the address of user ;supplied
; interrupt service routines. These constants are for use with D-Bug12 version ;1.0.4 and later
; or version 2.0.0 and later.
;
UserPortHKWU:	equ 	7 	; PortH key wake-up user interrupt
UserPortJKWU:	equ 	8 	; PortJ key wake-up user interrupt
UserAtoD: 	equ 	9 	; A-to-D user interrupt
UserSCI1: 	equ 	10 	; SCI #1 user interrupt (not available in the MC68HC912B32)
UserSCI0: 	equ 	11 	; SCI #0 user interrupt
UserSPI0: 	equ 	12 	; SPI #0 user interrupt
UserPAccEdge:	equ 	13 	; Pulse Accumulator Edge user interrupt
UserPAccOvf: 	equ 	14 	; Pulse Accumulator Overflow user interrupt
UserTimerOvf:	equ 	15 	; Timer counter overflow user interrupt
UserTimerCh7:	equ 	16 	; Timer Channel #7 user interrupt
UserTimerCh6:	equ 	17 	; Timer Channel #6 user interrupt
UserTimerCh5:	equ 	18 	; Timer Channel #5 user interrupt
UserTimerCh4:	equ 	19 	; Timer Channel #4 user interrupt
UserTimerCh3:	equ 	20 	; Timer Channel #3 user interrupt
UserTimerCh2:	equ 	21 	; Timer Channel #2 user interrupt
UserTimerCh1:	equ 	22 	; Timer Channel #1 user interrupt
UserTimerCh0:	equ 	23 	; Timer Channel #0 user interrupt
UserRTI: 	equ 	24 	; Real Time Interrupt user interrupt
UserIRQ: 	equ 	25 	; CPU Maskable Interrupt request user interrupt
UserXIRQ: 	equ 	26 	; CPU Non-maskable Interrupt request user interrupt
UserSWI: 	equ 	27 	; Software Interrupt user interrupt
UserTrap: 	equ 	28 	; Instruction Trap user interrupt
RAMVectAddr: 	equ 	-1 	; returns the base address of the RAM interrupt vector table.
;
;
		endif
;
;
		if Version < 200	; if we're assembling for version 1.x.x
TableBase: 	equ 	$fe00 		; the address table is located at $fe00
		else
TableBase:	equ 	$f680 		; for version 2.x.x the table is located at $f680
		endif
;
;
jmain: 		equ 	TableBase + $00
jgetchar: 	equ 	TableBase + $02
jputchar: 	equ 	TableBase + $04
printf: 	equ 	TableBase + $06
jGetCmdLine: 	equ 	TableBase + $08
jsscanhex: 	equ 	TableBase + $0a
jisxdigit: 	equ 	TableBase + $0c
jtoupper: 	equ 	TableBase + $0e
jisalpha: 	equ 	TableBase + $10
jstrlen: 	equ 	TableBase + $12
jstrcpy: 	equ 	TableBase + $14
jout2hex: 	equ 	TableBase + $16
jout4hex: 	equ 	TableBase + $18
jSetUsrVect: 	equ 	TableBase + $1a
jWriteEEByte:	equ 	TableBase + $1c
jEraseEE: 	equ 	TableBase + $1e
jReadMem: 	equ 	TableBase + $20
jWriteMem: 	equ 	TableBase + $22




; Macros are as follows...

;
; C function: void main(void);
;
main: 		macro
		jmp	[jmain,PCR] 		; start D-Bug12 from main().
		endm


;
;
; C function: int getchar(void);
;
getchar: 	macro
		jsr 	[jgetchar,PCR]		; call D-Bug12's getchar routine. 								;return the character in the B-								;accumulator.
		endm


;
;
; C function: int putchar(int);
;
putchar: 	macro
		ldab	\1 			; load the character to send into the B-;accumulator.
		jsr 	[jputchar,PCR]		; call D-Bug12's getchar routine. Sent character is returned in B-accumulator.
		endm

;
; C function: int GetCmdLine(char *CmdLineStr, int CmdLineLen);
;
GetCmdLine:	macro
		Ldd	\2 			; load the length of the command line character buffer.
		pshd   				; place it on the stack.
		ldd 	\1 			; get a pointer to the character buffer
		jsr 	[jGetCmdLine,PCR]	; go get characters from the user.
		pulx 				; remove the command line length parameter from thestack.
		endm

;
; C function: char * sscanhex(char *HexStr, unsigned int *BinNum);
;
sscanhex:	macro
		ldd 	\2 			; get a pointer to a word location where the conversion result will be placed
		pshd 				; place it on the stack.
		ldd 	\1 			; get a pointer to the ASCII hex string to convert.
		jsr 	[jsscanhex,PCR]		; go convert ASCII hex string to binary
		pulx 				; 1-byte inst. to remove the pointer to the conversion result from the stack.
		endm

;
; C function: int isxdigit(int c);
;
isxdigit:	macro
		ldab	\1 			; load ASCII character into the B-accumulator.
		jsr 	[jisxdigit,PCR]		; go check for membership in the character set 0..9, A..F, a..f.
		endm
	
;
; C function: int toupper(int c);
;
toupper:	macro
		ldab	\1 			; load ASCII character into the B-accumulator.
		jsr 	[jtoupper,PCR]		; convert the character to upper case if the character is in the set a..z.
		endm

;
; C function: int isalpha(int c);
;
isalpha:	macro
		ldab	\1 			; load ASCII character into the B-accumulator.
		jsr 	[jisalpha,PCR]		; go check for membership in the character set A..Z, a..z.
		endm

;
; C function: unsigned int strlen(const char *cs);
;
strlen: 	macro
		ldd 	\1 			; get a pointer to the null ('\0') terminated character array.
		jsr 	[jstrlen,PCR] ; go count the number of characters in the string.
		endm

;
; C function: char * strcpy(char *s1, char *s2);
;
strcpy:		macro
		ldd 	\2 			; get pointer to source string (s2) onto the stack.
		pshd 				; place it on the stack.
		ldd 	\1 			; get pointer to destination string (s1)
		jsr 	[jstrcpy,PCR] 		; go copy the string.
		pulx 				; one byte instruction to remove the source string pointer (s2) from the stack.
		endm

;
; C function: void out2hex(unsigned int num);
;
out2hex:	macro
		ldab	\1 			; get the 8-bit byte to display as ASCII hex.
		jsr 	[jout2hex,PCR]		; go display the byte.
		endm

;
; C function: void out4hex(unsigned int num);
;
out4hex:	macro
		ldd 	\1 			; get the 16-bit word to display as ASCII hex.
		jsr 	[jout4hex,PCR]		; go display the word.
		endm

;
; C function: int SetUserVector (int VectNum, Address UserAddress);
;
SetUserVector:	macro
		ldd 	\2 			; get the address of the users interrupt service routine.
		pshd 				; place it on the stack.
		ldd 	\1 			; get the interrupt vector to set.
		jsr 	[jSetUsrVect,PCR]	; go set the user's interrupt vector.
		pulx 				; one byte instruction to remove the address of the users interrupt service routine from the stack.
		endm

;
; C function: Boolean WriteEEByte(Address EEAddress, Byte EEData);
;
WriteEEByte:	macro
		ldab	\2 			; get the data byte to place in EEPROM memory.
		pshd 				; place it on the stack.
		ldd 	\1 			; get the EEPROM byte address.
		jsr 	[jWriteEEByte,PCR]	; go program the EEPROM byte.
		pulx 				; one byte instruction to remove the EEPROM data from the stack.
		endm

;
; C function: int EraseEE(void);
;
EraseEE: 	macro
		jsr 	[jEraseEE,PCR]		; go bulk erase the EEPROM.
		endm

;
; C function: int ReadMem (Address StartAddress, Byte *MemDataP, unsigned int ;NumBytes);
;
ReadMem:	macro
		ldd 	\3 			; get the number of bytes to read.
		pshd 				; place it on the stack.
		ldd 	\2 			; get a pointer to a buffer in which to place the memory contents.
		pshd 				; place it on the stack.
		ldd 	\1 			; get the memory address where we will start reading data.
		jsr	[jReadMem,PCR]		; go read data from the target memory.
		leas	4,sp 			; remove the 2 parameters placed on the stack.
		endm

;
; C function: int WriteMem (Address StartAddress, Byte *MemDataP, unsigned int ;NumBytes);
;
WriteMem: 	macro
		ldd 	\3 			; get the number of bytes to write.
		pshd 				; place it on the stack.
		ldd 	\2 			; get a pointer to the data that will be placed in memory.
		pshd 				; place it on the stack.
		ldd 	\1 			; get the memory address where we will start writing data to memory.
		jsr 	[jWriteMem,PCR]		; go write our data into the target memory.
		leas	4,sp 			; remove the 2 parameters placed on the stack.
		endm
;
;

	endif ; DB12MACS_INC