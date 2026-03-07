.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
	w DW 10 DUP (0000H)
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 20
L2:
	MOV AX, 0		; line 6
	PUSH AX
L3:
	MOV AX, 2		; line 6
	PUSH AX
L4:
	POP AX
	NEG AX		; line 6
	POP BX
	PUSH AX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	POP AX
	MOV w[BX], AX
L5:
	MOV AX, 0		; line 7
	PUSH AX
L6:
	MOV AX, 0		; line 7
	PUSH AX
L7:
	POP BX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	MOV AX, w[BX]
	POP BX
	PUSH AX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	MOV AX, 22
	SUB AX, BX
	MOV BX, AX
	POP AX
	MOV SI, BX
	NEG SI
	MOV [BP + SI], AX
L8:
	MOV AX, 0		; line 8
	PUSH AX
L9:
	POP BX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	MOV AX, 22
	SUB AX, BX
	MOV BX, AX
	MOV SI, BX
	NEG SI
	MOV AX, [BP + SI]
	MOV [BP-2], AX
L10:
	MOV AX, [BP-2]		; line 9
	CALL print_output
	CALL new_line
L11:
	MOV AX, 1		; line 10
	PUSH AX
L12:
	MOV AX, 0		; line 10
	PUSH AX
L13:
	POP BX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	MOV AX, w[BX]
	PUSH AX
	INC AX
	MOV w[BX], AX
	POP AX
	POP BX
	PUSH AX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	MOV AX, 22
	SUB AX, BX
	MOV BX, AX
	POP AX
	MOV SI, BX
	NEG SI
	MOV [BP + SI], AX
L14:
	MOV AX, 1		; line 11
	PUSH AX
L15:
	POP BX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	MOV AX, 22
	SUB AX, BX
	MOV BX, AX
	MOV SI, BX
	NEG SI
	MOV AX, [BP + SI]
	MOV [BP-2], AX
L16:
	MOV AX, [BP-2]		; line 12
	CALL print_output
	CALL new_line
L17:
	MOV AX, 0		; line 13
	PUSH AX
L18:
	POP BX
	MOV AX, 2
	MUL BX
	MOV BX, AX
	MOV AX, w[BX]
	MOV [BP-2], AX
L19:
	MOV AX, [BP-2]		; line 14
	CALL print_output
	CALL new_line
L20:
	MOV AX, [BP-2]		; line 16
	PUSH AX		; line 16
L21:
	MOV AX, 0		; line 16
	PUSH AX
L22:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	MOV [BP-2], AX
L23:
	MOV AX, [BP-2]		; line 17
	PUSH AX		; line 17
L24:
	MOV AX, 0		; line 17
	PUSH AX
L25:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	MOV [BP-2], AX
L26:
	MOV AX, [BP-2]		; line 18
	PUSH AX		; line 18
L27:
	MOV AX, 1		; line 18
	PUSH AX
L28:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	MUL CX
	MOV [BP-2], AX
L29:
	MOV AX, [BP-2]		; line 19
	CALL print_output
	CALL new_line
L30:
	MOV AX, [BP-2]		; line 21
	PUSH AX		; line 21
L31:
	MOV AX, 0		; line 21
	PUSH AX
L32:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L33		; line 21
	JMP L34		; line 21
L33:
	MOV AX, 1		; line 21
	JMP L35		; line 21
L34:
	MOV AX, 0		; line 21
L35:
	PUSH AX		; line 21
L36:
	POP AX		; line 21
	CMP AX, 0
	JE L37		; line 21
L38:
	MOV AX, [BP-2]		; line 21
	PUSH AX		; line 21
L39:
	MOV AX, 10		; line 21
	PUSH AX
L40:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L41		; line 21
	JMP L42		; line 21
L41:
	MOV AX, 1		; line 21
	JMP L43		; line 21
L42:
	MOV AX, 0		; line 21
L43:
	CMP AX, 0
	JE L37		; line 21
L44:
	MOV AX, 1
	JMP L45		; line 21
L37:
	MOV AX, 0		; line 21
L45:
	PUSH AX		; line 21
L46:
	POP AX		; line 21
	CMP AX, 0
	JNE L47		; line 21
L48:
	MOV AX, [BP-2]		; line 21
	PUSH AX		; line 21
L49:
	MOV AX, 0		; line 21
	PUSH AX
L50:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L51		; line 21
	JMP L52		; line 21
L51:
	MOV AX, 1		; line 21
	JMP L53		; line 21
L52:
	MOV AX, 0		; line 21
L53:
	PUSH AX		; line 21
L54:
	POP AX		; line 21
	CMP AX, 0
	JE L55		; line 21
L56:
	MOV AX, [BP-2]		; line 21
	PUSH AX		; line 21
L57:
	MOV AX, 10		; line 21
	PUSH AX
L58:
	POP AX
	NEG AX		; line 21
	PUSH AX		; line 21
L59:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L60		; line 21
	JMP L61		; line 21
L60:
	MOV AX, 1		; line 21
	JMP L62		; line 21
L61:
	MOV AX, 0		; line 21
L62:
	CMP AX, 0
	JE L55		; line 21
L63:
	MOV AX, 1
	JMP L64		; line 21
L55:
	MOV AX, 0		; line 21
L64:
	CMP AX, 0
	JE L65		; line 21
L47:
	MOV AX, 1
	JMP L66		; line 21
L65:
	MOV AX, 0		; line 21
L66:
	CMP AX, 0		; line 21
	JE L67		; line 21
L68:
	MOV AX, 100		; line 22
	MOV [BP-2], AX
	JMP L69		; line 22
L67:
	MOV AX, 200		; line 24
	MOV [BP-2], AX
L69:
	MOV AX, [BP-2]		; line 25
	CALL print_output
	CALL new_line
L72:
	MOV AX, 0		; line 27
	PUSH AX
L73:
	POP AX		; line 27
	JMP L1		; line 27
L1:
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
