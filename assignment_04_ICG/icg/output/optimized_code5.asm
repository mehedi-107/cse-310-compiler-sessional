.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
.CODE
f PROC		; line 1
	PUSH BP
	MOV BP, SP
	SUB SP, 2
L2:
	MOV AX, 5		; line 3
	MOV [BP-2], AX
L3:
	MOV AX, [BP-2]		; line 4
	PUSH AX		; line 4
L5:
	MOV AX, 0		; line 4
	PUSH AX
L6:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L7		; line 4
	JMP L8		; line 4
L7:
	MOV AX, 1		; line 4
	JMP L9		; line 4
L8:
	MOV AX, 0		; line 4
L9:
	CMP AX, 0
	JE L10
L11:
	MOV AX, [BP+4]		; line 5
	PUSH AX		; line 5
	INC AX		; line 5
	MOV [BP+4], AX		; line 5
L12:
	MOV AX, [BP-2]		; line 6
	PUSH AX		; line 6
	DEC AX		; line 6
	MOV [BP-2], AX		; line 6
	JMP L3		; line 7
L10:
	MOV AX, 3		; line 8
	PUSH AX
L14:
	MOV AX, [BP+4]		; line 8
	PUSH AX		; line 8
L15:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	MUL CX
	PUSH AX		; line 8
L16:
	MOV AX, 7		; line 8
	PUSH AX
L17:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 8
L18:
	POP AX		; line 8
	JMP L1		; line 8
L19:
	MOV AX, 9		; line 9
	MOV [BP+4], AX
L1:
	MOV SP, BP
	POP BP
	RET 2
f ENDP
g PROC		; line 12
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
L22:
	MOV AX, [BP+6]		; line 15
	PUSH AX		; line 15
L23:
	CALL f		; line 15
	PUSH AX		; line 15
L24:
	MOV AX, [BP+6]		; line 15
	PUSH AX		; line 15
L25:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 15
L26:
	MOV AX, [BP+4]		; line 15
	PUSH AX		; line 15
L27:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	MOV [BP-2], AX
L28:
	MOV AX, 0		; line 17
	MOV [BP-4], AX
L29:
	MOV AX, [BP-4]		; line 17
	PUSH AX		; line 17
L31:
	MOV AX, 7		; line 17
	PUSH AX
L32:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L33		; line 17
	JMP L34		; line 17
L33:
	MOV AX, 1		; line 17
	JMP L35		; line 17
L34:
	MOV AX, 0		; line 17
L35:
	CMP AX, 0		; line 17
	JE L36		; line 17
	JMP L37		; line 17
L38:
	MOV AX, [BP-4]		; line 17
	PUSH AX		; line 17
	INC AX		; line 17
	MOV [BP-4], AX		; line 17
	JMP L29		; line 17
L37:
	MOV AX, [BP-4]		; line 18
	PUSH AX		; line 18
L40:
	MOV AX, 3		; line 18
	PUSH AX
L41:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	DIV CX
	PUSH DX		; line 18
L42:
	MOV AX, 0		; line 18
	PUSH AX
L43:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L44		; line 18
	JMP L45		; line 18
L44:
	MOV AX, 1		; line 18
	JMP L46		; line 18
L45:
	MOV AX, 0		; line 18
L46:
	CMP AX, 0		; line 18
	JE L47		; line 18
L48:
	MOV AX, [BP-2]		; line 19
	PUSH AX		; line 19
L49:
	MOV AX, 5		; line 19
	PUSH AX
L50:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	MOV [BP-2], AX
	JMP L51		; line 20
L47:
	MOV AX, [BP-2]		; line 22
	PUSH AX		; line 22
L53:
	MOV AX, 1		; line 22
	PUSH AX
L54:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	MOV [BP-2], AX
L51:
	JMP L38		; line 24
L36:
	MOV AX, [BP-2]		; line 26
	PUSH AX		; line 26
L57:
	MOV AX, [BP-2]		; line 26
	JMP L21		; line 26
L21:
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
L60:
	MOV AX, 1		; line 31
	MOV [BP-2], AX
L61:
	MOV AX, 2		; line 32
	MOV [BP-4], AX
L62:
	MOV AX, [BP-2]		; line 33
	PUSH AX		; line 33
L63:
	MOV AX, [BP-4]		; line 33
	PUSH AX		; line 33
L64:
	CALL g		; line 33
	MOV [BP-2], AX
L65:
	MOV AX, [BP-2]		; line 34
	CALL print_output
	CALL new_line
L66:
	MOV AX, 0		; line 35
	MOV [BP-6], AX
L67:
	MOV AX, [BP-6]		; line 35
	PUSH AX		; line 35
L69:
	MOV AX, 4		; line 35
	PUSH AX
L70:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L71		; line 35
	JMP L72		; line 35
L71:
	MOV AX, 1		; line 35
	JMP L73		; line 35
L72:
	MOV AX, 0		; line 35
L73:
	CMP AX, 0		; line 35
	JE L74		; line 35
	JMP L75		; line 35
L76:
	MOV AX, [BP-6]		; line 35
	PUSH AX		; line 35
	INC AX		; line 35
	MOV [BP-6], AX		; line 35
	JMP L67		; line 35
L75:
	MOV AX, 3		; line 36
	MOV [BP-2], AX
L78:
	MOV AX, [BP-2]		; line 37
	PUSH AX		; line 37
L80:
	MOV AX, 0		; line 37
	PUSH AX
L81:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L82		; line 37
	JMP L83		; line 37
L82:
	MOV AX, 1		; line 37
	JMP L84		; line 37
L83:
	MOV AX, 0		; line 37
L84:
	CMP AX, 0
	JE L85
L86:
	MOV AX, [BP-4]		; line 38
	PUSH AX		; line 38
	INC AX		; line 38
	MOV [BP-4], AX		; line 38
L87:
	MOV AX, [BP-2]		; line 39
	PUSH AX		; line 39
	DEC AX		; line 39
	MOV [BP-2], AX		; line 39
	JMP L78		; line 40
L85:
	JMP L76		; line 41
L74:
	MOV AX, [BP-2]		; line 42
	CALL print_output
	CALL new_line
L90:
	MOV AX, [BP-4]		; line 43
	CALL print_output
	CALL new_line
L91:
	MOV AX, [BP-6]		; line 44
	CALL print_output
	CALL new_line
L92:
	MOV AX, 0		; line 45
	PUSH AX
L93:
	POP AX		; line 45
	JMP L59		; line 45
L59:
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
