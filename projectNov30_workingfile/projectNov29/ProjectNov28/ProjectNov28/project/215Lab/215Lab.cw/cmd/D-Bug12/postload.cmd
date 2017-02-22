// Copyright © 2004-2009 W. Craig Scratchley
// School of Engineering Science, SFU, BC, Canada  V5A 1S6
// Copying and distribution of this file, with or without modification,
//     are permitted in any medium without royalty provided the copyright
//     notice and this notice are preserved.

// After load the commands written below will be executed

// disable external interrupts.  After ISR(s) have been configured,
//	external interrupts can be programmatically re-enabled.

	fill $1e $20
	
	
//		cli			; enable interrupts

	rs ccr=0x80


// Next line should help D-Bug12 to interrupt user code so that Metrowerks 
//	debugger can gain control (i.e. break execution). 
//		bset	SC0CR2,RIE	; SCI interrupt requested

	fill $c3 $2c


//	This line requires a newer version of D-Bug12

	pt usehbr

