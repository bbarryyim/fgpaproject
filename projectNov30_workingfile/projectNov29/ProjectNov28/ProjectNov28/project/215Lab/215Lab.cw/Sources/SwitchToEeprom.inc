;*****************************************************************
;* Copyright © 2008-2009 W. Craig Scratchley
;* School of Engineering Science, SFU, BC, Canada  V5A 1S6
;* ENSC 215, June 2009
;* Copying and distribution of this file, with or without modification,
;*     are permitted in any medium without royalty provided the copyright
;*     notice and this notice are preserved.
;*****************************************************************
		NOLIST

;These lines will abort assembly if too much RAM is being used.
	if * > (Dbg12Ram - StackRes)
		fail "Too much RAM used"
	endif
;		XDEF	EndRamCode
;EndRamCode:	ds.b	1

;These lines will initialize the RAM reserved for stack with $AC.
;The remaining unused RAM has been preinitilized with $EE on the 
;hardware and is marked as being unused in the simulator.  
;If all the $AC's disappear
;during execution of your program, increase the size of StackRes.
;Remember that an interrupt is triggered (and hence stack space is
;consumed) when a D-Bug12 breakpoint is reached.

;Unused:		dcb.b	(Dbg12Ram - StackRes - *), $EE
;RamUsedNoStk:	dc.w	Unused - RAMBase
		org	(Dbg12Ram - StackRes)
;		XDEF	Stack
Stack:	dcb.b 	(Dbg12Ram - *), $AC		

		ORG EEBase
		LIST
