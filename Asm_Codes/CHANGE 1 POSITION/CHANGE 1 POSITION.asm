ORG 0000H
SJMP MAIN   

ORG 0030H
MAIN:
    MOV A, #001H   

LOOP:
    MOV P1, A     
    ACALL DELAY    
    RLC A          
    CJNE A, #00H, LOOP

    SJMP MAIN    

DELAY: 
    MOV R1, #50   
L1:  
    MOV R2, #0100  
L2:
    MOV R3, #0100  
L3:
    DJNZ R3, L3   
    DJNZ R2, L2   
    DJNZ R1, L1   
    RET           

END
