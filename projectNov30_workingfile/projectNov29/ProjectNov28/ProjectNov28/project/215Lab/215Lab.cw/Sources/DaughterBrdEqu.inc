; ENSC 215 Thermo daughter board equates
; Created by Craig Scratchley/Kourosh Khosraviani for Summer term 2008
; Copyright (C) 2008 School of Engineering Science, SFU, Burnaby, BC, Canada
; You can modify this software under the terms of the GNU General Public License
; Please add to this file as necessary and contribute your
;	changes (send email to wcs@sfu.ca)

;Notes:  an "n" in a symbol means "active low"

;ENSC 215 Thermo daughter board masks

;Port S masks
DISPA0		EQU	%00000100	;7-seg address select0
DISPA1		EQU	%00001000	;7-seg address select1
nDISPEN		EQU	%00010000	;7-seg enable line (active low)
DTS		EQU	%00100000	;Digital Temp. Sensor
BUZ		EQU	%01000000	;4kHz Buzzer
DDP		EQU	%10000000	;7-seg decimal point
