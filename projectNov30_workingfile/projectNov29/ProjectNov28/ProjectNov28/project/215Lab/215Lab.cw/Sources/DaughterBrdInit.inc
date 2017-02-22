; Initialize 7-segment displays

	bset	DDRS, DISPA0 | DISPA1 | nDISPEN | DDP
	bset	DDRDLC, #$7f			;DA-DG as output
	
	bclr	PORTS, DDP | nDISPEN		;decimal point off

	
