; Created by Craig Scratchley, Spring 2005
; Copyright (C) 2005 School of Engineering Science, SFU, Burnaby, BC, Canada
; You can modify this software under the terms of the GNU General Public License

; Nest the inclusion of configuration files provided by G. Doughman
; with his book on the hc12.

; The .asm extensions used by Doughman have been retained, although
; .inc extensions would be more usual with Codewarrior.

		INCLUDE "\b32regs\configsc.asm"
		INCLUDE "\b32regs\a2d.asm"
		INCLUDE "\b32regs\bdlc.asm"
		INCLUDE "\b32regs\brkpoint.asm"
		
; Is the clock synthesis stuff reserved? (See data sheet book)
;		INCLUDE "\b32regs\clocksyn.asm"

		INCLUDE "\b32regs\eeprom.asm"
		INCLUDE "\b32regs\flashee.asm"
		INCLUDE "\b32regs\limregs.asm"
		INCLUDE "\b32regs\msi.asm"
		INCLUDE "\b32regs\pwm.asm"
		INCLUDE "\b32regs\timer.asm"

		