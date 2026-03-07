.MODEL SMALL
.STACK 1000H
.DATA
    number DB "00000$"
.CODE
main PROC
    MOV AX, @DATA
    MOV DS, AX
    PUSH BP
    MOV BP, SP
    SUB SP, 2
    SUB SP, 2
    SUB SP, 2
L2:
    MOV AX, 3		; line 5
    MOV [BP-2], AX
L3:
L4:
L5:
    MOV AX, [BP-2]		; line 10
    PUSH AX		; line 10
    POP AX		; line 10
    CALL print_output
L6:
    ADD AX, 0		; redundant operation
    MUL AX, 1		; redundant operation
    MOV AX, 5
    MOV BX, AX
    MOV AX, BX		; redundant MOV
L7:
    MOV AX, 4CH
    INT 21H
main ENDP
END main
