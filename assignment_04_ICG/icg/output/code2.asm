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
	PUSH AX
	POP AX
	MOV [BP-2], AX
L3:
	MOV AX, 8		; line 6
	PUSH AX
	POP AX
	MOV [BP-4], AX
L4:
	MOV AX, 6		; line 7
	PUSH AX
	POP AX
	MOV [BP-6], AX
L5:
	MOV AX, [BP-2]		; line 10
	PUSH AX		; line 10
L6:
	MOV AX, 3		; line 10
	PUSH AX
L7:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L8		; line 10
	JMP L9		; line 10
L8:
	MOV AX, 1		; line 10
	JMP L10		; line 10
L9:
	MOV AX, 0		; line 10
L10:
	PUSH AX		; line 10
L11:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L12
L13:
	MOV AX, [BP-4]		; line 11
	CALL print_output
	CALL new_line
L12:
L14:
	MOV AX, [BP-4]		; line 14
	PUSH AX		; line 14
L15:
	MOV AX, 8		; line 14
	PUSH AX
L16:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L17		; line 14
	JMP L18		; line 14
L17:
	MOV AX, 1		; line 14
	JMP L19		; line 14
L18:
	MOV AX, 0		; line 14
L19:
	PUSH AX		; line 14
	POP AX		; line 14
	CMP AX, 0		; line 14
	JE L20		; line 14
L21:
	MOV AX, [BP-2]		; line 15
	CALL print_output
	CALL new_line
	JMP L22		; line 16
L20:
L23:
	MOV AX, [BP-6]		; line 18
	CALL print_output
	CALL new_line
L22:
L24:
	MOV AX, [BP-6]		; line 21
	PUSH AX		; line 21
L25:
	MOV AX, 6		; line 21
	PUSH AX
L26:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JNE L27		; line 21
	JMP L28		; line 21
L27:
	MOV AX, 1		; line 21
	JMP L29		; line 21
L28:
	MOV AX, 0		; line 21
L29:
	PUSH AX		; line 21
	POP AX		; line 21
	CMP AX, 0		; line 21
	JE L30		; line 21
L31:
	MOV AX, [BP-6]		; line 22
	CALL print_output
	CALL new_line
	JMP L32		; line 23
L30:
L33:
	MOV AX, [BP-4]		; line 24
	PUSH AX		; line 24
L34:
	MOV AX, 8		; line 24
	PUSH AX
L35:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L36		; line 24
	JMP L37		; line 24
L36:
	MOV AX, 1		; line 24
	JMP L38		; line 24
L37:
	MOV AX, 0		; line 24
L38:
	PUSH AX		; line 24
	POP AX		; line 24
	CMP AX, 0		; line 24
	JE L39		; line 24
L40:
	MOV AX, [BP-4]		; line 25
	CALL print_output
	CALL new_line
	JMP L41		; line 26
L39:
L42:
	MOV AX, [BP-2]		; line 27
	PUSH AX		; line 27
L43:
	MOV AX, 5		; line 27
	PUSH AX
L44:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L45		; line 27
	JMP L46		; line 27
L45:
	MOV AX, 1		; line 27
	JMP L47		; line 27
L46:
	MOV AX, 0		; line 27
L47:
	PUSH AX		; line 27
	POP AX		; line 27
	CMP AX, 0		; line 27
	JE L48		; line 27
L49:
	MOV AX, [BP-2]		; line 28
	CALL print_output
	CALL new_line
	JMP L50		; line 29
L48:
L51:
	MOV AX, 0		; line 31
	PUSH AX
	POP AX
	MOV [BP-6], AX
L52:
	MOV AX, [BP-6]		; line 32
	CALL print_output
	CALL new_line
L50:
L41:
L32:
L53:
	MOV AX, 0		; line 36
	PUSH AX
L54:
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
