.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
.CODE
f PROC		; line 1
	PUSH BP
	MOV BP, SP
	SUB SP, 2
L1:
	MOV AX, 5		; line 3
	PUSH AX
	POP AX
	MOV [BP-2], AX
L2:
L3:
	MOV AX, 0		; line 4
	PUSH AX
	POP AX
	MOV DX, AX
	MOV AX, [BP-2]		; line 4
	CMP AX, DX
	JG L4		; line 4
	JMP L5		; line 4
L4:
	MOV AX, 1		; line 4
	JMP L6		; line 4
L5:
	MOV AX, 0		; line 4
L6:
	PUSH AX		; line 4
	POP AX
	CMP AX, 0
	JE L9		; line 7
L7:
	MOV AX, [BP+4]		; line 5
	PUSH AX		; line 5
	INC AX		; line 5
	MOV [BP+4], AX		; line 5
L8:
	MOV AX, [BP-2]		; line 6
	PUSH AX		; line 6
	DEC AX		; line 6
	MOV [BP-2], AX		; line 6
	JMP L2		; line 7
L9:
	MOV AX, 3		; line 8
	PUSH AX
L10:
	MOV AX, [BP+4]		; line 8
	MOV CX, AX
	POP AX
	CWD
	MUL CX
	PUSH AX		; line 8
	MOV AX, 7		; line 8
	PUSH AX
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 8
	POP AX		; line 8
	JMP L12		; line 10
L11:
	MOV AX, 9		; line 9
	PUSH AX
	POP AX
	MOV [BP+4], AX
L12:
	MOV SP, BP
	POP BP
	RET 2
f ENDP
g PROC		; line 12
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
L13:
L14:
	MOV AX, [BP+6]		; line 15
	PUSH AX		; line 15
	CALL f		; line 15
	PUSH AX		; line 15
L15:
	MOV AX, [BP+6]		; line 15
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 15
L16:
	MOV AX, [BP+4]		; line 15
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 15
	POP AX
	MOV [BP-2], AX
L17:
	MOV AX, 0		; line 17
	PUSH AX
	POP AX
	MOV [BP-4], AX
L18:
L19:
	MOV AX, 7		; line 17
	PUSH AX
	POP AX
	MOV DX, AX
	MOV AX, [BP-4]		; line 17
	CMP AX, DX
	JL L20		; line 17
	JMP L21		; line 17
L20:
	MOV AX, 1		; line 17
	JMP L22		; line 17
L21:
	MOV AX, 0		; line 17
L22:
	PUSH AX		; line 17
	POP AX		; line 17
	CMP AX, 0		; line 17
	JE L34		; line 24
	JMP L24		; line 17
L23:
	MOV AX, [BP-4]		; line 17
	PUSH AX		; line 17
	INC AX		; line 17
	MOV [BP-4], AX		; line 17
	JMP L18		; line 17
L24:
L25:
	MOV AX, 3		; line 18
	PUSH AX
	POP AX
	MOV CX, AX
	MOV AX, [BP-4]		; line 18
	CWD
	DIV CX
	PUSH DX		; line 18
	MOV AX, 0		; line 18
	PUSH AX
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L26		; line 18
	JMP L27		; line 18
L26:
	MOV AX, 1		; line 18
	JMP L28		; line 18
L27:
	MOV AX, 0		; line 18
L28:
	PUSH AX		; line 18
	POP AX		; line 18
	CMP AX, 0		; line 18
	JE L31		; line 18
L29:
L30:
	MOV AX, 5		; line 19
	PUSH AX
	POP AX
	MOV DX, AX
	MOV AX, [BP-2]		; line 19
	ADD AX, DX
	PUSH AX		; line 19
	POP AX
	MOV [BP-2], AX
	JMP L33		; line 23
L31:
L32:
	MOV AX, 1		; line 22
	PUSH AX
	POP AX
	MOV DX, AX
	MOV AX, [BP-2]		; line 22
	SUB AX, DX
	PUSH AX		; line 22
	POP AX
	MOV [BP-2], AX
L33:
	JMP L23		; line 24
L34:
L35:
	MOV AX, [BP-2]		; line 26
	JMP L36		; line 27
L36:
	MOV SP, BP
	POP BP
	RET 4
g ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L37:
	MOV AX, 1		; line 31
	PUSH AX
	POP AX
	MOV [BP-2], AX
L38:
	MOV AX, 2		; line 32
	PUSH AX
	POP AX
	MOV [BP-4], AX
L39:
L40:
L41:
	MOV AX, [BP-2]		; line 33
	PUSH AX		; line 33
	MOV AX, [BP-4]		; line 33
	PUSH AX		; line 33
	CALL g		; line 33
	PUSH AX		; line 33
	POP AX
	MOV [BP-2], AX
L42:
	MOV AX, [BP-2]		; line 34
	CALL print_output
	CALL new_line
L43:
	MOV AX, 0		; line 35
	PUSH AX
	POP AX
	MOV [BP-6], AX
L44:
L45:
	MOV AX, 4		; line 35
	PUSH AX
	POP AX
	MOV DX, AX
	MOV AX, [BP-6]		; line 35
	CMP AX, DX
	JL L46		; line 35
	JMP L47		; line 35
L46:
	MOV AX, 1		; line 35
	JMP L48		; line 35
L47:
	MOV AX, 0		; line 35
L48:
	PUSH AX		; line 35
	POP AX		; line 35
	CMP AX, 0		; line 35
	JE L59		; line 41
	JMP L50		; line 35
L49:
	MOV AX, [BP-6]		; line 35
	PUSH AX		; line 35
	INC AX		; line 35
	MOV [BP-6], AX		; line 35
	JMP L44		; line 35
L50:
	MOV AX, 3		; line 36
	PUSH AX
	POP AX
	MOV [BP-2], AX
L51:
L52:
	MOV AX, 0		; line 37
	PUSH AX
	POP AX
	MOV DX, AX
	MOV AX, [BP-2]		; line 37
	CMP AX, DX
	JG L53		; line 37
	JMP L54		; line 37
L53:
	MOV AX, 1		; line 37
	JMP L55		; line 37
L54:
	MOV AX, 0		; line 37
L55:
	PUSH AX		; line 37
	POP AX
	CMP AX, 0
	JE L58		; line 40
L56:
	MOV AX, [BP-4]		; line 38
	PUSH AX		; line 38
	INC AX		; line 38
	MOV [BP-4], AX		; line 38
L57:
	MOV AX, [BP-2]		; line 39
	PUSH AX		; line 39
	DEC AX		; line 39
	MOV [BP-2], AX		; line 39
	JMP L51		; line 40
L58:
	JMP L49		; line 41
L59:
	MOV AX, [BP-2]		; line 42
	CALL print_output
	CALL new_line
L60:
	MOV AX, [BP-4]		; line 43
	CALL print_output
	CALL new_line
L61:
	MOV AX, [BP-6]		; line 44
	CALL print_output
	CALL new_line
L62:
	MOV AX, 0		; line 45
	PUSH AX
	POP AX		; line 45
	JMP L63		; line 45
L63:
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
