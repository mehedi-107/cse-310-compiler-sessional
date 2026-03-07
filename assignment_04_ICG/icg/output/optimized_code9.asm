.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
.CODE
func PROC		; line 1
	PUSH BP
	MOV BP, SP
	SUB SP, 2
L2:
	MOV AX, [BP+4]		; line 3
	PUSH AX		; line 3
L3:
	MOV AX, 0		; line 3
	PUSH AX
L4:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L5		; line 3
	JMP L6		; line 3
L5:
	MOV AX, 1		; line 3
	JMP L7		; line 3
L6:
	MOV AX, 0		; line 3
L7:
	PUSH AX		; line 3
L8:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L9
L10:
	MOV AX, 0		; line 3
	PUSH AX
L11:
	POP AX		; line 3
	JMP L1		; line 3
L9:
	MOV AX, [BP+4]		; line 4
	MOV [BP-2], AX
L13:
	MOV AX, [BP+4]		; line 5
	PUSH AX		; line 5
L14:
	MOV AX, 1		; line 5
	PUSH AX
L15:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 5
L16:
	CALL func		; line 5
	PUSH AX		; line 5
L17:
	MOV AX, [BP-2]		; line 5
	PUSH AX		; line 5
L18:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 5
L19:
	POP AX		; line 5
	JMP L1		; line 5
L1:
	MOV SP, BP
	POP BP
	RET 2
func ENDP
func2 PROC		; line 8
	PUSH BP
	MOV BP, SP
	SUB SP, 2
L22:
	MOV AX, [BP+4]		; line 10
	PUSH AX		; line 10
L23:
	MOV AX, 0		; line 10
	PUSH AX
L24:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L25		; line 10
	JMP L26		; line 10
L25:
	MOV AX, 1		; line 10
	JMP L27		; line 10
L26:
	MOV AX, 0		; line 10
L27:
	PUSH AX		; line 10
L28:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L29
L30:
	MOV AX, 0		; line 10
	PUSH AX
L31:
	POP AX		; line 10
	JMP L21		; line 10
L29:
	MOV AX, [BP+4]		; line 11
	MOV [BP-2], AX
L33:
	MOV AX, [BP+4]		; line 12
	PUSH AX		; line 12
L34:
	MOV AX, 1		; line 12
	PUSH AX
L35:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 12
L36:
	CALL func		; line 12
	PUSH AX		; line 12
L37:
	MOV AX, [BP-2]		; line 12
	PUSH AX		; line 12
L38:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 12
L39:
	POP AX		; line 12
	JMP L21		; line 12
L21:
	MOV SP, BP
	POP BP
	RET 2
func2 ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
L42:
	MOV AX, 7		; line 17
	PUSH AX
L43:
	CALL func		; line 17
	MOV [BP-2], AX
L44:
	MOV AX, [BP-2]		; line 18
	CALL print_output
	CALL new_line
L45:
	MOV AX, 0		; line 19
	PUSH AX
L46:
	POP AX		; line 19
	JMP L41		; line 19
L41:
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
