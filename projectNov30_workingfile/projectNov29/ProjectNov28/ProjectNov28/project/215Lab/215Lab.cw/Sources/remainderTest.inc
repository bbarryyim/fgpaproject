; Completed assignment submitted by:
;
; Student #1 -- Name: _________________  Student #: ______________
;
; Student #2 -- Name: _________________  Student #: ______________
;

***************************************************
; TestRoutine 
; The following code will test the Remainder subroutine
; with data from the table at the end of this file.  The
; Y register jumps through the data in the table row by row.  Using 
; the swi instruction, etc., the testing code should instruct the 
; simulator (or hardware) to halt each time it detects an incorrect result 
; being returned by the Remainder subroutine. 
; Press the continue (or a step) button to continue
; the testing.  

TestRoutine:
		ldy	#TestTbl	; point to the test data table (TestTbl)
TestLoop:	
		;...			; are we at the end of the table?
		beq	EndOfTesting
		;...
		bra	TestLoop
		
		;...
						 
EndOfTesting:	
		nop  