.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
.CODE
foo PROC		; line 1
	PUSH BP
	MOV BP, SP
L2:
	MOV AX, [BP+6]		; line 2
	PUSH AX		; line 2
L3:
	MOV AX, [BP+4]		; line 2
	PUSH AX		; line 2
L4:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 2
L5:
	MOV AX, 5		; line 2
	PUSH AX
L6:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JLE L7		; line 2
	JMP L8		; line 2
L7:
	MOV AX, 1		; line 2
	JMP L9		; line 2
L8:
	MOV AX, 0		; line 2
L9:
	PUSH AX		; line 2
L10:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L11
L12:
	MOV AX, 7		; line 3
	PUSH AX
L13:
	POP AX		; line 3
	JMP L1		; line 3
L11:
	MOV AX, [BP+6]		; line 5
	PUSH AX		; line 5
L15:
	MOV AX, 2		; line 5
	PUSH AX
L16:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 5
L17:
	MOV AX, [BP+4]		; line 5
	PUSH AX		; line 5
L18:
	MOV AX, 1		; line 5
	PUSH AX
L19:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 5
L20:
	CALL foo		; line 5
	PUSH AX		; line 5
L21:
	MOV AX, 2		; line 5
	PUSH AX
L22:
	MOV AX, [BP+6]		; line 5
	PUSH AX		; line 5
L23:
	MOV AX, 1		; line 5
	PUSH AX
L24:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 5
L25:
	MOV AX, [BP+4]		; line 5
	PUSH AX		; line 5
L26:
	MOV AX, 2		; line 5
	PUSH AX
L27:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 5
L28:
	CALL foo		; line 5
	PUSH AX		; line 5
L29:
	POP AX
	MOV CX, AX
	POP AX
	CWD
	MUL CX
	PUSH AX		; line 5
L30:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 5
L31:
	POP AX		; line 5
	JMP L1		; line 5
L1:
	MOV SP, BP
	POP BP
	RET 4
foo ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L34:
	MOV AX, 7		; line 11
	MOV [BP-2], AX
L35:
	MOV AX, 3		; line 12
	MOV [BP-4], AX
L36:
	MOV AX, [BP-2]		; line 14
	PUSH AX		; line 14
L37:
	MOV AX, [BP-4]		; line 14
	PUSH AX		; line 14
L38:
	CALL foo		; line 14
	MOV [BP-6], AX
L39:
	MOV AX, [BP-6]		; line 15
	CALL print_output
	CALL new_line
L40:
	MOV AX, 0		; line 17
	PUSH AX
L41:
	POP AX		; line 17
	JMP L33		; line 17
L33:
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
