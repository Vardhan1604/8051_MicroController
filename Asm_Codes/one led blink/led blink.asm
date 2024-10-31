		ORG 0000H
		SJMP start
		
		ORG 0030H
	  start:CLR P1.0
			ACALL delay
			SETB P1.0
			ACALL delay
			SJMP start
			
	 delay: MOV R0 ,#100
		abc:	MOV R1, #100
		bc:	MOV R2, #100
		cd:  DJNZ R2,cd
			DJNZ R1,bc
			DJNZ R0,abc
			RET
			
			END