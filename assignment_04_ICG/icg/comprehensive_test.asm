.MODEL SMALL
.STACK 1000H
.DATA
	a DW 1 DUP (0000H)
	b DW 1 DUP (0000H)
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	
	; Test case (i) - Redundant MOV instructions
	MOV AX, a		; Load a into AX
	MOV a, AX		; Store AX back to a - REDUNDANT
	
	MOV BX, b		; Load b into BX  
	MOV b, BX		; Store BX back to b - REDUNDANT
	
	; Test case (ii) - Redundant PUSH/POP pairs
	PUSH AX			; Push AX
	POP AX			; Pop AX - REDUNDANT PAIR
	
	PUSH BX			; Push BX
	POP BX			; Pop BX - REDUNDANT PAIR
	
	PUSH CX			; Push CX with comment
	POP CX			; Pop CX - REDUNDANT PAIR
	
	; Test case (iii) - Redundant operations
	ADD AX, 0		; Add 0 - REDUNDANT
	SUB BX, 0		; Subtract 0 - REDUNDANT  
	MUL CX, 1		; Multiply by 1 - REDUNDANT
	DIV DX, 1		; Divide by 1 - REDUNDANT
	OR AX, 0		; OR with 0 - REDUNDANT
	XOR BX, 0		; XOR with 0 - REDUNDANT
	
	; Test case (iv) - Consecutive redundant labels
L1:
L2:
L3:
	MOV AX, 5		; Only one label needed for this instruction
	
L4:
L5:
	MOV BX, 10		; Only one label needed for this instruction
	
L6:
L7:
L8:
L9:
	MOV CX, 15		; Only one label needed for this instruction
	
	; Jump to test label mapping
	JMP L2			; Should map to L1
	JMP L5			; Should map to L4
	JMP L8			; Should map to L6
	
	; Mixed cases - some optimizations together
	MOV AX, a		; Load a
	MOV a, AX		; REDUNDANT MOV
	PUSH AX			; Push
	POP AX			; REDUNDANT PUSH/POP
	ADD AX, 0		; REDUNDANT ADD
	
L10:
L11:
	MOV AX, 4CH
	INT 21H
	
main ENDP
END main
