      ORG 0000H
      SJMP MAD   

      ORG 0030H
MAD:
      CLR P0.0
	  ACALL DELAY
	  SETB P0.0
	  ACALL DELAY
      SJMP   MAD

DELAY: 
      MOV R0, #050
L3:   MOV R1, #0100
L2:   MOV R2, #0100
L1:   DJNZ R2, L1    
      DJNZ R1, L2  
      DJNZ R0, L3  
      RET         
END
 