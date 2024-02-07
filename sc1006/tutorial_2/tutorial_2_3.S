Mem_100	DCD		0x3224FFFF ; write consequtive 4 byte value to memory location 0x100
Mem_104	DCD		0x22282317
Mem_108	DCD		0x17208013
Mem_10C	DCD		0x2D142580
Start	MOV		R1,#0x100 ; set R1 to 0x100
		MOV		R4,#0x100 ; set R4 to 0x100
		MOV		R0,#0 ; set R0 to 0
		STRB		R0,[R4] ; copy the first byte of R0 into memory location pointed by R4
		ADD		R1,R1,#2 ; R1 = R1 + 2
Loop		LDRB		R3,[R1] ; copy first byte of memory pointed by R1 into R3
		CMP		R3,#0x80 ; compare R3 and 0x80 (-128) and set CSPR ibts
		BEQ		Done ; branch to 'Done' if R3 == 0x80
		ADD		R0,R0,#1 ; R0 = R0 + 1
		LDRB		R3,[R1] ; copy first byte of memory pointed by R1 into R3
		CMP		R3,#36 ; compare R3 and 36 and set CSPR bits
		BHS		HotFound ; branch to 'HotFound' if R3 >= 36
		ADD		R1,R1,#1 ; R1 = R1 + 1
		B		Loop ; unconditional branch to loop
HotFound	LDRB		R2,[R4] ; copy first byte of memory pointed by R4 (HotDays) into R2
		ADD		R2,R2,#1 ; R2 = R2 + 1
		STRB		R2,[R4] ; copy first byte of R2 into memory pointed by R4 (HotDays)
		ADD		R1,R1,#1 ; R1 = R1 + 1
		B		Loop ; unconditional branch to loop
Done		ADD		R4,R4,#1 ; R4 = R4 + 1
		STRB		R0,[R4] ; copy first byte of R0 into memory pointed by R4 (DaySum)
		END
