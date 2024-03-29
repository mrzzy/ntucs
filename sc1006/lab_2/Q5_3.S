Num1		DCD		0x20
Num2		DCD		0x14
Result	DCD		0
		
		;		setup registers with values
		ADR		R0,Num1
		ADR		R1,Num2
		ADR		R2,Result
		
		;Calling	Program
		ADR		SP,0xFFFFFFFC ; initialize Stack Pointer (SP) to top of memory
		MOV		R0,#0x100 ;
		LDR		R1,[R0],#4
		STR		R1,[SP,#-4]! ; (a) push value at memoryvariable Num1 to stack
		LDR		R1,[R0],#4
		STR		R1,[SP,#-4]! ; (b) push value at memory variable Num2 to stack
		STR		R0,[SP,#-4]! ; (c) push address at memory variable Result to stack
		BL		Mean ; call subroutine Mean
		ADD		SP,SP,#12 ; (h) remove the 3 parameters push to the stack earlier
		END		; Stop emulation
		;Subroutine	Mean
Mean
		LDR		R0,[SP,#8] ; (d) move value of Num1 that is on the stackinto R0
		LDR		R1,[SP,#4] ; (e) move value of Num2 that is on the stack to R1
		ADD		R0,R0,R1 ; Add R1 to R0
		ASR		R0,R0,#1 ; divide-by-2 us ing arithmetic shift right by 1 bit
		LDR		R2,[SP] ; (f) move address of Result that is on the stack into R2
		STR		R0,[R2] ; (g) move result in R0 into memory variable Result
		MOV		PC,LR ; return to calling program
