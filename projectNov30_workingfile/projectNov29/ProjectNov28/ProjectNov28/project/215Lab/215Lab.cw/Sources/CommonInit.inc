;	movw	#TimerCh2,TimerCh2IsrP	;Int vector Init

;Timer-related initialization

;	bset	TIOS,IOS2		;CH2 ouptput compare
;	bset	TMSK2,PR0 | PR2		;Prescaler = 32
;	bset	TSCR,TEN | TFFCA	;timer enable & Fast Flag clear