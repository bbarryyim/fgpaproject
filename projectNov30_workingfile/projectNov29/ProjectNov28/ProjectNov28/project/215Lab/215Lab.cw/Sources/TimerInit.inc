;initializing the timer	

;Timer 3 (Finding period1 and period2

	movw	#TimerCh3, TimerCh3IsrP
;	movw	#TimerCh2, TimerCh2IsrP
	
	;bset TIOS,IOS0|IOS1
	bset TMSK1,C3I	
	bset TMSK2, PR0 | PR2
	bset TCTL4, %11000000	
	;set Timer control register to capture rising or falling edge
	
	bset TSCR,TEN|TFFCA


;Timer 1 (For 3Hz interrupt)

;	movw	#TimerCh1, TimerCh1IsrP
;	bset	TIOS,IOS1
;	bset	TMSK1,C1I
;	bset	TMSK2,PR0 | PR2
;	bset	TSCR,TEN|TFFCA
	
	
;Timer 2 (de-bouncing )
	
;End of Timer init
	