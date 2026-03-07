.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
	i DW 1 DUP (0000H)
	j DW 1 DUP (0000H)
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L2:
	MOV AX, 1		; line 6
	PUSH AX
	POP AX
	MOV i, AX
L3:
	MOV AX, i		; line7
	CALL print_output
	CALL new_line
L4:
	MOV AX, 5		; line 9
	PUSH AX
L5:
	MOV AX, 8		; line 9
	PUSH AX
L6:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 9
	POP AX
	MOV j, AX
L7:
	MOV AX, j		; line10
	CALL print_output
	CALL new_line
L8:
	MOV AX, i		; line 12
	PUSH AX		; line 12
L9:
	MOV AX, 2		; line 12
	PUSH AX
L10:
	MOV AX, j		; line 12
	PUSH AX		; line 12
L11:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	MUL CX
	PUSH AX		; line 12
L12:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 12
	POP AX
	MOV [BP-2], AX
L13:
	MOV AX, [BP-2]		; line 13
	CALL print_output
	CALL new_line
L14:
	MOV AX, [BP-2]		; line 15
	PUSH AX		; line 15
L15:
	MOV AX, 9		; line 15
	PUSH AX
L16:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	DIV CX
	PUSH DX		; line 15
	POP AX
	MOV [BP-6], AX
L17:
	MOV AX, [BP-6]		; line 16
	CALL print_output
	CALL new_line
L18:
	MOV AX, [BP-6]		; line 18
	PUSH AX		; line 18
L19:
	MOV AX, [BP-4]		; line 18
	PUSH AX		; line 18
L20:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JLE L21		; line 18
	JMP L22		; line 18
L21:
	MOV AX, 1		; line 18
	JMP L23		; line 18
L22:
	MOV AX, 0		; line 18
L23:
	PUSH AX		; line 18
	POP AX
	MOV [BP-8], AX
L24:
	MOV AX, [BP-8]		; line 19
	CALL print_output
	CALL new_line
L25:
	MOV AX, i		; line 21
	PUSH AX		; line 21
L26:
	MOV AX, j		; line 21
	PUSH AX		; line 21
L27:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JNE L28		; line 21
	JMP L29		; line 21
L28:
	MOV AX, 1		; line 21
	JMP L30		; line 21
L29:
	MOV AX, 0		; line 21
L30:
	PUSH AX		; line 21
	POP AX
	MOV [BP-10], AX
L31:
	MOV AX, [BP-10]		; line 22
	CALL print_output
	CALL new_line
L32:
	MOV AX, [BP-8]		; line 24
	PUSH AX		; line 24
L33:
	POP AX		; line 24
	CMP AX, 0
	JNE L34		; line 24
L35:
	MOV AX, [BP-10]		; line 24
	PUSH AX		; line 24
	POP AX
	CMP AX, 0
	JE L36		; line 24
L34:
	MOV AX, 1
	JMP L37		; line 24
L36:
	MOV AX, 0		; line 24
L37:
	PUSH AX		; line 24
	POP AX
	MOV [BP-12], AX
L38:
	MOV AX, [BP-12]		; line 25
	CALL print_output
	CALL new_line
L39:
	MOV AX, [BP-8]		; line 27
	PUSH AX		; line 27
L40:
	POP AX		; line 27
	CMP AX, 0
	JE L41		; line 27
L42:
	MOV AX, [BP-10]		; line 27
	PUSH AX		; line 27
	POP AX
	CMP AX, 0
	JE L41		; line 27
L43:
	MOV AX, 1
	JMP L44		; line 27
L41:
	MOV AX, 0		; line 27
L44:
	PUSH AX		; line 27
	POP AX
	MOV [BP-12], AX
L45:
	MOV AX, [BP-12]		; line 28
	CALL print_output
	CALL new_line
L46:
	MOV AX, [BP-12]		; line 30
	PUSH AX		; line 30
	INC AX		; line 30
	MOV [BP-12], AX		; line 30
L47:
	MOV AX, [BP-12]		; line 31
	CALL print_output
	CALL new_line
L48:
	MOV AX, [BP-12]		; line 33
	PUSH AX		; line 33
L49:
	POP AX
	NEG AX		; line 33
	PUSH AX		; line 33
	POP AX
	MOV [BP-2], AX
L50:
	MOV AX, [BP-2]		; line 34
	CALL print_output
	CALL new_line
L51:
	MOV AX, 0		; line 36
	PUSH AX
L52:
	POP AX		; line 36
	JMP L1		; line 36
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
