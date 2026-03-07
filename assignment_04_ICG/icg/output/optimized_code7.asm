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
L2:
	MOV AX, [BP-2]		; line 3
	PUSH AX		; line 3
L3:
	MOV AX, 0		; line 3
	PUSH AX
L4:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L5		; line 3
	JMP L6		; line 3
L5:
	MOV AX, 1		; line 3
	JMP L7		; line 3
L6:
	MOV AX, 0		; line 3
L7:
	PUSH AX		; line 3
L8:
	POP AX		; line 3
	CMP AX, 0
	JNE L9		; line 3
L10:
	MOV AX, [BP-2]		; line 3
	PUSH AX		; line 3
L11:
	MOV AX, 10		; line 3
	PUSH AX
L12:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L13		; line 3
	JMP L14		; line 3
L13:
	MOV AX, 1		; line 3
	JMP L15		; line 3
L14:
	MOV AX, 0		; line 3
L15:
	CMP AX, 0
	JE L16		; line 3
L9:
	MOV AX, 1
	JMP L17		; line 3
L16:
	MOV AX, 0		; line 3
L17:
	CMP AX, 0		; line 3
	JE L18		; line 3
L19:
	MOV AX, 100		; line 4
	MOV [BP-2], AX
	JMP L20		; line 4
L18:
	MOV AX, 200		; line 6
	MOV [BP-2], AX
L20:
	MOV AX, [BP-2]		; line 8
	PUSH AX		; line 8
L23:
	MOV AX, 20		; line 8
	PUSH AX
L24:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L25		; line 8
	JMP L26		; line 8
L25:
	MOV AX, 1		; line 8
	JMP L27		; line 8
L26:
	MOV AX, 0		; line 8
L27:
	PUSH AX		; line 8
L28:
	POP AX		; line 8
	CMP AX, 0
	JE L29		; line 8
L30:
	MOV AX, [BP-2]		; line 8
	PUSH AX		; line 8
L31:
	MOV AX, 30		; line 8
	PUSH AX
L32:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L33		; line 8
	JMP L34		; line 8
L33:
	MOV AX, 1		; line 8
	JMP L35		; line 8
L34:
	MOV AX, 0		; line 8
L35:
	CMP AX, 0
	JE L29		; line 8
L36:
	MOV AX, 1
	JMP L37		; line 8
L29:
	MOV AX, 0		; line 8
L37:
	CMP AX, 0		; line 8
	JE L38		; line 8
L39:
	MOV AX, 300		; line 9
	MOV [BP-2], AX
	JMP L40		; line 9
L38:
	MOV AX, 400		; line 11
	MOV [BP-2], AX
L40:
	MOV AX, [BP-2]		; line 13
	PUSH AX		; line 13
L43:
	MOV AX, 40		; line 13
	PUSH AX
L44:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L45		; line 13
	JMP L46		; line 13
L45:
	MOV AX, 1		; line 13
	JMP L47		; line 13
L46:
	MOV AX, 0		; line 13
L47:
	PUSH AX		; line 13
L48:
	POP AX		; line 13
	CMP AX, 0
	JE L49		; line 13
L50:
	MOV AX, [BP-2]		; line 13
	PUSH AX		; line 13
L51:
	MOV AX, 50		; line 13
	PUSH AX
L52:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L53		; line 13
	JMP L54		; line 13
L53:
	MOV AX, 1		; line 13
	JMP L55		; line 13
L54:
	MOV AX, 0		; line 13
L55:
	CMP AX, 0
	JE L49		; line 13
L56:
	MOV AX, 1
	JMP L57		; line 13
L49:
	MOV AX, 0		; line 13
L57:
	PUSH AX		; line 13
L58:
	POP AX		; line 13
	CMP AX, 0
	JNE L59		; line 13
L60:
	MOV AX, [BP-2]		; line 13
	PUSH AX		; line 13
L61:
	MOV AX, 60		; line 13
	PUSH AX
L62:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L63		; line 13
	JMP L64		; line 13
L63:
	MOV AX, 1		; line 13
	JMP L65		; line 13
L64:
	MOV AX, 0		; line 13
L65:
	PUSH AX		; line 13
L66:
	POP AX		; line 13
	CMP AX, 0
	JE L67		; line 13
L68:
	MOV AX, [BP-2]		; line 13
	PUSH AX		; line 13
L69:
	MOV AX, 70		; line 13
	PUSH AX
L70:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L71		; line 13
	JMP L72		; line 13
L71:
	MOV AX, 1		; line 13
	JMP L73		; line 13
L72:
	MOV AX, 0		; line 13
L73:
	CMP AX, 0
	JE L67		; line 13
L74:
	MOV AX, 1
	JMP L75		; line 13
L67:
	MOV AX, 0		; line 13
L75:
	CMP AX, 0
	JE L76		; line 13
L59:
	MOV AX, 1
	JMP L77		; line 13
L76:
	MOV AX, 0		; line 13
L77:
	CMP AX, 0		; line 13
	JE L78		; line 13
L79:
	MOV AX, 500		; line 14
	MOV [BP-2], AX
	JMP L80		; line 14
L78:
	MOV AX, 600		; line 16
	MOV [BP-2], AX
L80:
	MOV AX, [BP-2]		; line 17
	CALL print_output
	CALL new_line
L83:
	MOV AX, 0		; line 19
	PUSH AX
L84:
	POP AX		; line 19
	JMP L1		; line 19
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
