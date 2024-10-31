ORG 0000H
SJMP MAIN       

ORG 0030H
	
MAIN:
    MOV A,#00H
LOOP:
    MOV P1,A
	ACALL DELAY
	INC A
	CJNE A,#0FFH,LOOP
	MOV P1,#0FFH
    SJMP $

DELAY:
    MOV R1, #2  
L1:  
    MOV R2, #100  
L2:
    MOV R3, #100  
L3:
    DJNZ R3, L3  
    DJNZ R2, L2  
    DJNZ R1, L1  
    RET          

END
