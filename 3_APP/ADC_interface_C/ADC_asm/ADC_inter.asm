org 00h
	LJMP MAIN
	MAIN:
	;=======================================================================
	LCD_PORT EQU P1
	RS BIT P2.0
	E BIT P2.1
	MOV LCD_PORT , #00H
	CLR RS
	CLR E
	
	ACALL LCD_INIT
	
	ADC_PORT EQU P3
		
	MOV ADC_PORT,#0FFH
	
	ALE BIT P2.4
	OE BIT P2.7
	START BIT P2.5
	EOC BIT P2.6
	AD1	BIT P2.1
	AD2 BIT P2.2
	AD3 BIT P2.3
	SETB EOC
	CLR ALE
	CLR OE
	CLR START
	SUPER:
	clr AD1
	clr AD2
	clr AD3
	SETB ALE
	SETB START
	CLR ALE
	CLR START
	JB EOC,$
	JNB EOC,$
	SETB OE
	MOV A,ADC_PORT
	CLR OE
	SJMP SUPER
	
	
	; ADC 0804
	;INTR BIT P2.7
	;WRR BIT P2.6
	;RDD BIT P2.5

	;MOV DPTR,#TEMP_MSG
	;ACALL LCD_STRING
	;SUPER:
	;CLR WRR
	;SETB WRR
	;HERE : JB INTR , HERE
	;CLR RDD
	;MOV A,P3
	;MOV R1,A
	;MOV A,#0C0H
	;ACALL LCD_COMM
	;MOV A,R1
	;ACALL LCD_NUM
	;MOV A,#0DFH
	;ACALL LCD_DATA
	;MOV A,#'C'
	;ACALL LCD_DATA
	;ACALL DELAY
	;SETB RDD
	;SJMP SUPER
	; ADC 0808
	
	;=============================================================LCD_DISPLAY_RESULT=======================================================================;	
LCD_INIT:
	MOV A , #01H
	ACALL LCD_COMM
	MOV A , #38H
	ACALL LCD_COMM
	MOV A , #0EH
	ACALL LCD_COMM
	RET
LCD_STRING:	
	AGAIN_STRING:
         CLR A
	     MOVC A,@ A+DPTR
	     JZ	END_STRING
	     ACALL LCD_DATA
	     INC DPTR
	     SJMP AGAIN_STRING
	END_STRING:
RET
LCD_NUM: 
	    CJNE A ,#10, NOT_EQ1
		SJMP RESULT_2_DIGITS
NOT_EQ1:
        JNC NEXT1
		
RESULT_1_DIGITS:	
        ORL A ,#30H
		ACALL LCD_DATA
		SJMP EXT
NEXT1:  
        CJNE A ,#100, NOT_EQ2
	    SJMP RESULT_3_DIGITS
NOT_EQ2:
	    JNC NEXT2
RESULT_2_DIGITS:		
	    MOV B ,#10
	    DIV AB
		ORL A ,#30H
		ACALL LCD_DATA
		MOV A ,B
		ORL A ,#30H
		ACALL LCD_DATA
	    SJMP EXT
		
	
NEXT2:
       CJNE A ,#255, NOT_EQ3
        SJMP RESULT_3_DIGITS
NOT_EQ3:
	   JNC EXT
RESULT_3_DIGITS:
       MOV B ,#100
	   DIV AB
	   ORL A ,#30H
	   ACALL LCD_DATA
	   MOV A ,B
	   MOV B ,#10
	   DIV AB
	   ORL A ,#30H
	   ACALL LCD_DATA
	   MOV A ,B
	   ORL A ,#30H
	   ACALL LCD_DATA
	   
EXT:   RET
	
LCD_COMM:
	   MOV LCD_PORT , A
	   CLR RS
	   SETB E
	   NOP
	   NOP
	   NOP
	   CLR E
	   ACALL DELAY
	   RET
	
LCD_DATA:
	MOV LCD_PORT , A
	SETB RS
	SETB E
	NOP
	NOP
	NOP
	CLR E
	ACALL DELAY
	RET
	
LCD_CLEAR:
	MOV A , #01H
	ACALL LCD_COMM
	RET
	
	DELAY:
	MOV R5 , #50H
	LL1: MOV R6 , #0FFH
	LL2: DJNZ R6 , LL2
	DJNZ R5 , LL1
	RET
	ORG 500H
		TEMP_MSG: DB "TEMP : ",0
	
END