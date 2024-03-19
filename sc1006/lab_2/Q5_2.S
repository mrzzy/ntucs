Num1		DCD		0x20
Num2		DCD		0x14
Result	DCD		0
		
		;		setup registers with values
		ADR		R0,Num1
		ADR		R1,Num2
		ADR		R2,Result
		;		Calling program
		
		ADR		SP,0XFFFFFFFC ; initialize Stack Pointer (SP) to top of memory
		MOV		R0,#0x100 ; (a) move start address of memory blockinto R0
		BL		Mean ; call subroutine Mean
		
		END		; End the program ;Subroutine Mean Mean
		LDR		R1,[R0] ; (b) Load value in Num1 into R1
		LDR		R2,[R0,#4] ; (c) Load Num2 in R2
		ADD		R1,R1,R2 ; Add R2 to R1
		ASR		R1,R1,#1 ; divide-by-2 us ing arithmetic shift right by 1 bit
		STR		R1,[R0,#8] ; (d) move result in R1 into memory variable Result
		MOV		PC,LR ; return to calling program
