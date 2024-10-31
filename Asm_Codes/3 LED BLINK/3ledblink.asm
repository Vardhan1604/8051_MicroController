ORG 0000H
SJMP MAIN       

ORG 0030H
	
MAIN:
    MOV P1,#00H
    CLR P1.1
    CLR P1.2
    SETB P1.0
    ACALL DELAY	
	CLR P1.2
    CLR P1.0
    SETB P1.1
    ACALL DELAY	
	CLR P1.0
    CLR P1.1
    SETB P1.2
    ACALL DELAY	

    SJMP MAIN     

DELAY:
    MOV R1, #20  
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
