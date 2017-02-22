; Created by Craig Scratchley
; Copyright (C) 2004 School of Engineering Science, SFU, Burnaby, BC, Canada
; You can modify this software under the terms of the GNU General Public License
;
; this file allows one to "define space" for HC12 ports.  That
;     means that ports, etc. can show up in the data window
;     of the debugger.  Examples are given below.  These are
;     optional and can be used if desired to speed debugging.

		ORG PORTB
PORTB_Var:	ds.b 1

		ORG DDRB
DDRB_Var:	ds.b 1	

; 		ORG	IRQIsrP
; 		dc.w	ExtIsr
