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
	SUB SP, 2
L2:
	MOV AX, 0		; line 5
	MOV [BP-2], AX
L3:
	MOV AX, [BP-2]		; line 5
	PUSH AX		; line 5
L5:
	MOV AX, 6		; line 5
	PUSH AX
L6:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L7		; line 5
	JMP L8		; line 5
L7:
	MOV AX, 1		; line 5
	JMP L9		; line 5
L8:
	MOV AX, 0		; line 5
L9:
	CMP AX, 0		; line 5
	JE L10		; line 5
	JMP L11		; line 5
L12:
	MOV AX, [BP-2]		; line 5
	PUSH AX		; line 5
	INC AX		; line 5
	MOV [BP-2], AX		; line 5
	JMP L3		; line 5
L11:
	MOV AX, [BP-2]		; line 6
	CALL print_output
	CALL new_line
L14:
	JMP L12		; line 7
L10:
	MOV AX, 4		; line 9
	MOV [BP-6], AX
L16:
	MOV AX, 6		; line 10
	MOV [BP-8], AX
L17:
	MOV AX, [BP-6]		; line 11
	PUSH AX		; line 11
L19:
	MOV AX, 0		; line 11
	PUSH AX
L20:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L21		; line 11
	JMP L22		; line 11
L21:
	MOV AX, 1		; line 11
	JMP L23		; line 11
L22:
	MOV AX, 0		; line 11
L23:
	CMP AX, 0
	JE L24
L25:
	MOV AX, [BP-8]		; line 12
	PUSH AX		; line 12
L26:
	MOV AX, 3		; line 12
	PUSH AX
L27:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	MOV [BP-8], AX
L28:
	MOV AX, [BP-6]		; line 13
	PUSH AX		; line 13
	DEC AX		; line 13
	MOV [BP-6], AX		; line 13
	JMP L17		; line 14
L24:
	MOV AX, [BP-8]		; line 16
	CALL print_output
	CALL new_line
L30:
	MOV AX, [BP-6]		; line 17
	CALL print_output
	CALL new_line
L31:
	MOV AX, 4		; line 19
	MOV [BP-6], AX
L32:
	MOV AX, 6		; line 20
	MOV [BP-8], AX
L33:
	MOV AX, [BP-6]		; line 22
	PUSH AX		; line 22
	DEC AX		; line 22
	MOV [BP-6], AX		; line 22
	POP AX
	CMP AX, 0
	JE L35
L36:
	MOV AX, [BP-8]		; line 23
	PUSH AX		; line 23
L37:
	MOV AX, 3		; line 23
	PUSH AX
L38:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	MOV [BP-8], AX
	JMP L33		; line 24
L35:
	MOV AX, [BP-8]		; line 26
	CALL print_output
	CALL new_line
L40:
	MOV AX, [BP-6]		; line 27
	CALL print_output
	CALL new_line
L41:
	MOV AX, 0		; line 30
	PUSH AX
L42:
	POP AX		; line 30
	JMP L1		; line 30
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
