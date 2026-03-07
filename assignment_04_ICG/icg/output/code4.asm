.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
	a DW 1 DUP (0000H)
	b DW 1 DUP (0000H)
	c DW 1 DUP (0000H)
.CODE
func_a PROC		; line 3
	PUSH BP
	MOV BP, SP
L2:
	MOV AX, 7		; line 4
	PUSH AX
	POP AX
	MOV a, AX
L1:
	MOV SP, BP
	POP BP
	RET
func_a ENDP
foo PROC		; line 7
	PUSH BP
	MOV BP, SP
L4:
	MOV AX, [BP+4]		; line 8
	PUSH AX		; line 8
L5:
	MOV AX, 3		; line 8
	PUSH AX
L6:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 8
	POP AX
	MOV [BP+4], AX
L7:
	MOV AX, [BP+4]		; line 9
	PUSH AX		; line 9
L8:
	MOV AX, [BP+4]		; line 9
	JMP L3		; line 9
L3:
	MOV SP, BP
	POP BP
	RET 2
foo ENDP
bar PROC		; line 13
	PUSH BP
	MOV BP, SP
L11:
	MOV AX, 4		; line 14
	PUSH AX
L12:
	MOV AX, [BP+6]		; line 14
	PUSH AX		; line 14
L13:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	MUL CX
	PUSH AX		; line 14
L14:
	MOV AX, 2		; line 14
	PUSH AX
L15:
	MOV AX, [BP+4]		; line 14
	PUSH AX		; line 14
L16:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	MUL CX
	PUSH AX		; line 14
L17:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 14
	POP AX
	MOV c, AX
L18:
	MOV AX, c		; line 15
	PUSH AX		; line 15
L19:
	MOV AX, c		; line 15
	JMP L10		; line 15
L10:
	MOV SP, BP
	POP BP
	RET 4
bar ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L22:
	MOV AX, 5		; line 22
	PUSH AX
	POP AX
	MOV [BP-2], AX
L23:
	MOV AX, 6		; line 23
	PUSH AX
	POP AX
	MOV [BP-4], AX
L24:
	CALL func_a		; line 25
	PUSH AX		; line 25
L25:
	MOV AX, a		; line26
	CALL print_output
	CALL new_line
L26:
	MOV AX, [BP-2]		; line 28
	PUSH AX		; line 28
L27:
	CALL foo		; line 28
	PUSH AX		; line 28
	POP AX
	MOV [BP-6], AX
L28:
	MOV AX, [BP-6]		; line 29
	CALL print_output
	CALL new_line
L29:
	MOV AX, [BP-2]		; line 31
	PUSH AX		; line 31
L30:
	MOV AX, [BP-4]		; line 31
	PUSH AX		; line 31
L31:
	CALL bar		; line 31
	PUSH AX		; line 31
	POP AX
	MOV [BP-8], AX
L32:
	MOV AX, [BP-8]		; line 32
	CALL print_output
	CALL new_line
L33:
	MOV AX, 6		; line 34
	PUSH AX
L34:
	MOV AX, [BP-2]		; line 34
	PUSH AX		; line 34
L35:
	MOV AX, [BP-4]		; line 34
	PUSH AX		; line 34
L36:
	CALL bar		; line 34
	PUSH AX		; line 34
L37:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	MUL CX
	PUSH AX		; line 34
L38:
	MOV AX, 2		; line 34
	PUSH AX
L39:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 34
L40:
	MOV AX, 3		; line 34
	PUSH AX
L41:
	MOV AX, [BP-2]		; line 34
	PUSH AX		; line 34
L42:
	CALL foo		; line 34
	PUSH AX		; line 34
L43:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	MUL CX
	PUSH AX		; line 34
L44:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 34
	POP AX
	MOV [BP-4], AX
L45:
	MOV AX, [BP-4]		; line 35
	CALL print_output
	CALL new_line
L46:
	MOV AX, 0		; line 38
	PUSH AX
L47:
	POP AX		; line 38
	JMP L21		; line 38
L21:
	MOV SP, BP
	POP BP
	MOV AX, 4CH
	INT 21H
main ENDP
new_line proc
	push ax
	push dx
	mov ah,2
	mov dl,0Dh
	int 21h
	mov ah,2
	mov dl,0Ah
	int 21h
	pop dx
	pop ax
	ret
new_line endp
print_output proc  ;print what is in ax
	push ax
	push bx
	push cx
	push dx
	push si
	lea si,number
	mov bx,10
	add si,4
	cmp ax,0
	jnge negate
print:
	xor dx,dx
	div bx
	mov [si],dl
	add [si],'0'
	dec si
	cmp ax,0
	jne print
	inc si
	lea dx,si
	mov ah,9
	int 21h
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret
negate:
	push ax
	mov ah,2
	mov dl,'-'
	int 21h
	pop ax
	neg ax
	jmp print
print_output endp
END main
