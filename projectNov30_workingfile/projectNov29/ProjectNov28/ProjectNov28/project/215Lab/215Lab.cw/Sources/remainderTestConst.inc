; Completed assignment submitted by:
;
; Student #1 -- Name: _________________  Student #: ______________
;
; Student #2 -- Name: _________________  Student #: ______________
;

; Testing data
		
; Table of testing data
; This table provides testing data.  Each set of data gives testing input and
; corresponding output for the Remainder subroutine.
; The inputs for each test are a divisor value, a dividend length and dividend
; value bytes (corresponding to the specified length).  The outputs for each test 
; are the remainder and the flag "quotientIsBig", which specifies whether or not the 
; quotient couldn't fit in one byte.  Also in each row of the table is a rowId, which 
; can help you determine what row(s) of the table don't pass in the situation
; that one or more failures are detected.

; A 0 as the divisor marks the end of the table.
;
; Please add more tests as you need to ensure the correctness of your submission.
;
;				quot-		divi-	      
;		divi-	remain-	ient-		dend	dividend
;		sor	der	IsBig	rowId	length	bytes		

TestTbl:

; row 1	
rId:	set	1
	dc.b	$2,	$0,	0,	0,rId,	1,	$8
; row 2	
rId:	set	rId + 1
	dc.b	$2,	$0,	0,	0,rId,	2,	$0,$08
rId:	set	rId + 1
	dc.b	$3,	$2,	0,	0,rId,	1,	$8
rId:	set	rId + 1
	dc.b	$2,	$0,	1,	0,rId,	2,	$2,$00		
;...
rId:	set	rId + 1
	dc.b	$FF,	$2,	1,	0,rId,	4,	$2,$00,$00,$00
		
;ending divisor
	dc.b	0
