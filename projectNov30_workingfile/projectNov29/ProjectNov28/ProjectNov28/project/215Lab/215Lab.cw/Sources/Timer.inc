
TimerCh3:
	ldd TC3
	tfr d,y
	
	brclr PORTT, #%00001000, rising
	subd	last
	std	periodT2
;	movw	#5,periodT2
	sty	last
	bra	done
	
rising:
	;bset PORTT,#%00001000
	subd 	last
	std 	periodT1
;	movw	#2,periodT1
	sty 	last
	

done:
	;movw	TC3,last
	rti
