celsius:


	ldx periodT1
	stx T1


	ldx periodT2
	stx T2
		
	ldd #P
	ldy T1
	
	emul

	ldx T2
	
	ediv
;-------------------------	
	sty value1

	ldd #Q
	subd value1
	ldx #R
	idiv
	stx dig1
	movb dig2,digit1

	ldx #S
	idiv
	stx dig1
	movb dig2,digit2
	std dig1
	movb dig2,digit3
	
	movb #$0c,digit4
	lbra LED
;-----------------------


fahreinheit:
	
	ldx periodT1
	stx T1


	ldx periodT2
	stx T2
		
	ldd #F
	ldy T1
	
	emul

	ldx T2
	
	ediv
;-------------------------	
	sty value1

	ldd #G
	subd value1
	ldx #R
	idiv
	stx dig1
	movb dig2,digit1

	ldx #S
	idiv
	stx dig1
	movb dig2,digit2
	std dig1
	movb dig2,digit3
	movb #$0f,digit4
	lbra LED	
	
