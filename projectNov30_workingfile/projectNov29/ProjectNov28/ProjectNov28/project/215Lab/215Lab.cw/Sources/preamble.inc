;* Copyright © 2007-2009 W. Craig Scratchley
;* School of Engineering Science, SFU, BC, Canada  V5A 1S6
;* ENSC 215, May 2009
;* Copying and distribution of this file, with or without modification,
;*     are permitted in any medium without royalty provided the copyright
;*     notice and this notice are preserved.

; do not put contents of this file in listing-files/source-panes
		NOLIST		
; export symbols
	IFDEF _HC12		; Only needed for CodeWarrior, where _HC12 is usually defined.
		XDEF	ENTRY	; export 'Entry' symbol
		ABSENTRY ENTRY	; for absolute assembly: mark this as application entry point
	ENDIF

;		INCLUDE "hc912b32.inc"

; Macros for assembler compatiblity

; fill is mentioned in the Huang textbook and apparently used by the as12 assembler.
fill		macro
		dcb.b	\2, \1
		endm
		
; rmw is mentioned in the Huang textbook and apparently used by the as12 assembler.
rmw		macro
		ds.w	\1
		endm
		
; db is used by many assemblers and is equivalent to dc.b

db		macro
		nolist
	ifc "\2",""
		list
		dc.b \1
		nolist
	else
	 ifc "\3",""
		list
		dc.b \1, \2
		nolist
	 else
	  ifc "\4",""
		list
		dc.b \1, \2, \3
		nolist
	  else
	   ifc "\5",""
		list
		dc.b \1, \2, \3, \4
		nolist
	   else
	    ifc "\6",""
		list
		dc.b \1, \2, \3, \4, \5
		nolist
	    else
	     ifc "\7",""
		list
		dc.b \1, \2, \3, \4, \5, \6
		nolist
	     else
	      ifc "\8",""
		list
		dc.b \1, \2, \3, \4, \5, \6, \7
		nolist
	      else
	       ifc "\9",""
		list
		dc.b \1, \2, \3, \4, \5, \6, \7, \8
		nolist
	       else
	        ifc "\A",""
		 list
		 dc.b \1, \2, \3, \4, \5, \6, \7, \8, \9
		 nolist
	        else
	         ifc "\B",""
		  list
		  dc.b \1, \2, \3, \4, \5, \6, \7, \8, \9, \A
		  nolist
	         else
	          ifc "\C",""
		   list
		   dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B
		   nolist
	          else
	           ifc "\D",""
		    list
		    dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C
		    nolist
	           else
	            ifc "\E",""
		     list
		     dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D
		     nolist
	            else
	             ifc "\F",""
		      list
		      dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E
		      nolist
	             else
	              ifc "\G",""
		       list
		       dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F
		       nolist
	              else
	               ifc "\H",""
		        list
		        dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G
		        nolist
	               else
	                ifc "\I",""
		         list
		         dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G,\H
		         nolist
	                else
	                 ifc "\J",""
		          list
		          dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G,\H,\I
		          nolist
	                 else
	                  ifc "\K",""
		           list
		           dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G,\H,\I,\J
		           nolist
	                  else
	                   ifc "\L",""
		            list
		            dc.b \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G,\H,\I,\J,\K
		            nolist
	                   else
	                    fail "Too many arguments for db macro"
	                   endif
	                  endif
	                 endif
	                endif
	               endif
	              endif
	             endif
	            endif
	           endif  
	          endif
	         endif
	        endif
	       endif
	      endif
	     endif
	    endif
	   endif
	  endif
	 endif
	endif
	 	list
		endm

; dw is used by many assemblers and is equivalent to dc.w

dw		macro
		nolist
	ifc "\2",""
		list
		dc.w \1
		nolist
	else
	 ifc "\3",""
		list
		dc.w \1, \2
		nolist
	 else
	  ifc "\4",""
		list
		dc.w \1, \2, \3
		nolist
	  else
	   ifc "\5",""
		list
		dc.w \1, \2, \3, \4
		nolist
	   else
	    ifc "\6",""
		list
		dc.w \1, \2, \3, \4, \5
		nolist
	    else
	     ifc "\7",""
		list
		dc.w \1, \2, \3, \4, \5, \6
		nolist
	     else
	      ifc "\8",""
		list
		dc.w \1, \2, \3, \4, \5, \6, \7
		nolist
	      else
	       ifc "\9",""
		list
		dc.w \1, \2, \3, \4, \5, \6, \7, \8
		nolist
	       else
	        ifc "\A",""
		 list
		 dc.w \1, \2, \3, \4, \5, \6, \7, \8, \9
		 nolist
	        else
	         ifc "\B",""
		  list
		  dc.w \1, \2, \3, \4, \5, \6, \7, \8, \9, \A
		  nolist
	         else
	          ifc "\C",""
		   list
		   dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B
		   nolist
	          else
	           ifc "\D",""
		    list
		    dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C
		    nolist
	           else
	            ifc "\E",""
		     list
		     dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D
		     nolist
	            else
	             ifc "\F",""
		      list
		      dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E
		      nolist
	             else
	              ifc "\G",""
		       list
		       dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F
		       nolist
	              else
	               ifc "\H",""
		        list
		        dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G
		        nolist
	               else
	                ifc "\I",""
		         list
		         dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G,\H
		         nolist
	                else
	                 ifc "\J",""
		          list
		          dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G,\H,\I
		          nolist
	                 else
	                  ifc "\K",""
		           list
		           dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G,\H,\I,\J
		           nolist
	                  else
	                   ifc "\L",""
		            list
		            dc.w \1,\2,\3,\4,\5,\6,\7,\8,\9,\A,\B,\C,\D,\E,\F,\G,\H,\I,\J,\K
		            nolist
	                   else
	                    fail "Too many arguments for dw macro"
	                   endif
	                  endif
	                 endif
	                endif
	               endif
	              endif
	             endif
	            endif
	           endif  
	          endif
	         endif
	        endif
	       endif
	      endif
	     endif
	    endif
	   endif
	  endif
	 endif
	endif
	 	list
		endm

;  The following lines will cause an error to be displayed if an 
;  instruction is placed in the label field (left-hand margin).
;  It does this by pre-defining labels for instructions.
;  This means that the user cannot use an instruction name for a
;  label in his/her program if so desired.  Hopefully this will be
;  more useful than it is troublesome.

;       Craig Scratchley

; for above macros

fill
rmw
db
dw

; instructions

ldaa
ldab
ldd
lds
ldx
ldy
leas
leax
leay
staa
stab
std
sts
stx
sty
tab
tap
tba
tfr
tpa
tsx
tsy
txs
tys
exg
xgdx
xgdy
sex
movb
movw
aba
abx
aby
adca
adcb
adda
addb
addd
sba
sbca
sbcb
suba
subb
subd
daa
dec
deca
decb
des
dex
dey
inc
inca
incb
ins
inx
iny
cba
cmpa
cmpb
cpd
cps
cpx
cpy
tst
tsta
tstb
anda
andb
andcc
eora
eorb
oraa
orab
orcc
clc
cli
clr
clra
clrb
clv
com
coma
comb
neg
nega
negb
emul
emuls
mul
ediv
edivs
fdiv
idiv
idivs
bclr
bita
bitb
bset
lsl
lsla
lslb
lsld
lsr
lsra
lsrb
lsrd
asl
asla
aslb
asld
asr
asra
asrb
rol
rola
rolb
ror
rora
rorb

mem
rev
revw
wav
wavr
emind
eminm
mina
minm
emaxd
emaxm
maxa
maxm
emacs
etbl
tbl
bra
brn
bcc
bcs
beq
bmi
bne
bpl
bvc
bvs
bhi
bhs
blo
bls
bge
bgt
ble
blt
lbra
lbrn
lbcc
lbcs
lbeq
lbmi
lbne
lbpl
lbvc
lbvs
lbhi
lbhs
lblo
lbls
lbge
lbgt
lble
lblt
brclr
brset
dbeq
dbne
ibeq
ibne
tbeq
tbne
bsr
call
jmp
jsr
rtc
rts
rti
swi
trap
psha
pshb
pshc
pshd
pshx
pshy
pula
pulb
pulc
puld
pulx
puly

sec
sei
sev
stop
wai
bgnd
nop


; directives

ABSENTRY
ALIGN
BASE
CLIST

DC.B
DC.W
DC.L

DCB.B
DCB.W
DCB.L

DS.B
DS.W
DS.L

ELSE
END
ENDFOR
ENDIF
ENDM
EQU
EVEN
FAIL
FOR
IF
IFEQ
IFNE
IFLT
IFLE
IFGT
IFGE
IFC
IFNC
IFDEF
IFNDEF
INCLUDE
LIST
LLEN
LONGEVEN
MACRO
MEXIT
MLIST
NOLIST
NOPAGE
OFFSET
ORG
;PAGE
PLEN
RAD50
SECTION
SET
SPC
TABS
TITLE
XDEF
XREF
XREFB

; synonms

DCW
DCL
FCB
FDB
FQB

;RMB
;RMD
;RMQ

; MASM compatibility directives

RMB
RMD 
RMQ 
ELSEC 
ENDC 
NOL 
TTL 
GLOBAL
PUBLIC
EXTERNAL 
;XREFB 
SWITCH 
ASCT 
BSCT 
CSCT
DSCT
IDSCT 
IPSCT
PSCT

; misc

FCC

; re-enable output of source code in listing-files/source-panes
		LIST
