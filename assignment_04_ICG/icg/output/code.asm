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
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L2:
	MOV AX, 10		; line 4
	PUSH AX
	POP AX
	MOV [BP-2], AX
L3:
	MOV AX, 5		; line 5
	PUSH AX
	POP AX
	MOV [BP-4], AX
L4:
	MOV AX, 8		; line 6
	PUSH AX
	POP AX
	MOV [BP-6], AX
L5:
	MOV AX, 15		; line 7
	PUSH AX
	POP AX
	MOV [BP-8], AX
L6:
	MOV AX, 3		; line 8
	PUSH AX
	POP AX
	MOV [BP-10], AX
L7:
	MOV AX, 7		; line 9
	PUSH AX
	POP AX
	MOV [BP-12], AX
L8:
	MOV AX, 0		; line 10
	PUSH AX
	POP AX
	MOV [BP-14], AX
L9:
	MOV AX, [BP-2]		; line 12
	PUSH AX		; line 12
L10:
	MOV AX, [BP-4]		; line 12
	PUSH AX		; line 12
L11:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L12		; line 12
	JMP L13		; line 12
L12:
	MOV AX, 1		; line 12
	JMP L14		; line 12
L13:
	MOV AX, 0		; line 12
L14:
	PUSH AX		; line 12
L15:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L16
L17:
	MOV AX, [BP-2]		; line 13
	CALL print_output
	CALL new_line
L18:
	MOV AX, [BP-6]		; line 14
	PUSH AX		; line 14
L19:
	MOV AX, [BP-8]		; line 14
	PUSH AX		; line 14
L20:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L21		; line 14
	JMP L22		; line 14
L21:
	MOV AX, 1		; line 14
	JMP L23		; line 14
L22:
	MOV AX, 0		; line 14
L23:
	PUSH AX		; line 14
	POP AX		; line 14
	CMP AX, 0		; line 14
	JE L24		; line 14
L25:
	MOV AX, [BP-6]		; line 15
	CALL print_output
	CALL new_line
L26:
	MOV AX, [BP-10]		; line 16
	PUSH AX		; line 16
L27:
	MOV AX, 3		; line 16
	PUSH AX
L28:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L29		; line 16
	JMP L30		; line 16
L29:
	MOV AX, 1		; line 16
	JMP L31		; line 16
L30:
	MOV AX, 0		; line 16
L31:
	PUSH AX		; line 16
	POP AX		; line 16
	CMP AX, 0		; line 16
	JE L32		; line 16
L33:
	MOV AX, [BP-10]		; line 17
	CALL print_output
	CALL new_line
	JMP L34		; line 18
L32:
L35:
	MOV AX, [BP-14]		; line 20
	CALL print_output
	CALL new_line
L34:
	JMP L36		; line 22
L24:
L37:
	MOV AX, [BP-8]		; line 24
	CALL print_output
	CALL new_line
L36:
L16:
L38:
	MOV AX, [BP-4]		; line 28
	PUSH AX		; line 28
L39:
	MOV AX, 0		; line 28
	PUSH AX
L40:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L41		; line 28
	JMP L42		; line 28
L41:
	MOV AX, 1		; line 28
	JMP L43		; line 28
L42:
	MOV AX, 0		; line 28
L43:
	PUSH AX		; line 28
	POP AX		; line 28
	CMP AX, 0		; line 28
	JE L44		; line 28
L45:
	MOV AX, [BP-4]		; line 29
	CALL print_output
	CALL new_line
	JMP L46		; line 30
L44:
L47:
	MOV AX, [BP-2]		; line 31
	PUSH AX		; line 31
L48:
	MOV AX, 10		; line 31
	PUSH AX
L49:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L50		; line 31
	JMP L51		; line 31
L50:
	MOV AX, 1		; line 31
	JMP L52		; line 31
L51:
	MOV AX, 0		; line 31
L52:
	PUSH AX		; line 31
	POP AX		; line 31
	CMP AX, 0		; line 31
	JE L53		; line 31
L54:
	MOV AX, [BP-2]		; line 32
	CALL print_output
	CALL new_line
	JMP L55		; line 33
L53:
L56:
	MOV AX, [BP-14]		; line 35
	CALL print_output
	CALL new_line
L55:
L46:
L57:
	MOV AX, [BP-10]		; line 38
	PUSH AX		; line 38
L58:
	MOV AX, [BP-12]		; line 38
	PUSH AX		; line 38
L59:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L60		; line 38
	JMP L61		; line 38
L60:
	MOV AX, 1		; line 38
	JMP L62		; line 38
L61:
	MOV AX, 0		; line 38
L62:
	PUSH AX		; line 38
L63:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L64
L65:
	MOV AX, [BP-12]		; line 39
	CALL print_output
	CALL new_line
L66:
	MOV AX, [BP-12]		; line 40
	PUSH AX		; line 40
L67:
	MOV AX, [BP-10]		; line 40
	PUSH AX		; line 40
L68:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 40
L69:
	MOV AX, 3		; line 40
	PUSH AX
L70:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L71		; line 40
	JMP L72		; line 40
L71:
	MOV AX, 1		; line 40
	JMP L73		; line 40
L72:
	MOV AX, 0		; line 40
L73:
	PUSH AX		; line 40
	POP AX		; line 40
	CMP AX, 0		; line 40
	JE L74		; line 40
L75:
	MOV AX, [BP-12]		; line 41
	CALL print_output
	CALL new_line
	JMP L76		; line 42
L74:
L77:
	MOV AX, [BP-10]		; line 44
	CALL print_output
	CALL new_line
L76:
L64:
L78:
	MOV AX, [BP-2]		; line 48
	PUSH AX		; line 48
L79:
	MOV AX, [BP-4]		; line 48
	PUSH AX		; line 48
L80:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 48
L81:
	MOV AX, [BP-6]		; line 48
	PUSH AX		; line 48
L82:
	MOV AX, [BP-8]		; line 48
	PUSH AX		; line 48
L83:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 48
L84:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L85		; line 48
	JMP L86		; line 48
L85:
	MOV AX, 1		; line 48
	JMP L87		; line 48
L86:
	MOV AX, 0		; line 48
L87:
	PUSH AX		; line 48
	POP AX		; line 48
	CMP AX, 0		; line 48
	JE L88		; line 48
L89:
	MOV AX, [BP-2]		; line 49
	CALL print_output
	CALL new_line
	JMP L90		; line 50
L88:
L91:
	MOV AX, [BP-4]		; line 51
	PUSH AX		; line 51
L92:
	MOV AX, [BP-6]		; line 51
	PUSH AX		; line 51
L93:
	POP AX
	MOV DX, AX
	POP AX
	ADD AX, DX
	PUSH AX		; line 51
L94:
	MOV AX, [BP-8]		; line 51
	PUSH AX		; line 51
L95:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L96		; line 51
	JMP L97		; line 51
L96:
	MOV AX, 1		; line 51
	JMP L98		; line 51
L97:
	MOV AX, 0		; line 51
L98:
	PUSH AX		; line 51
	POP AX		; line 51
	CMP AX, 0		; line 51
	JE L99		; line 51
L100:
	MOV AX, [BP-4]		; line 52
	CALL print_output
	CALL new_line
	JMP L101		; line 53
L99:
L102:
	MOV AX, [BP-8]		; line 54
	PUSH AX		; line 54
L103:
	MOV AX, [BP-6]		; line 54
	PUSH AX		; line 54
L104:
	POP AX
	MOV DX, AX
	POP AX
	SUB AX, DX
	PUSH AX		; line 54
L105:
	MOV AX, [BP-2]		; line 54
	PUSH AX		; line 54
L106:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JL L107		; line 54
	JMP L108		; line 54
L107:
	MOV AX, 1		; line 54
	JMP L109		; line 54
L108:
	MOV AX, 0		; line 54
L109:
	PUSH AX		; line 54
	POP AX		; line 54
	CMP AX, 0		; line 54
	JE L110		; line 54
L111:
	MOV AX, [BP-10]		; line 55
	PUSH AX		; line 55
L112:
	MOV AX, 1		; line 55
	PUSH AX
L113:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L114		; line 55
	JMP L115		; line 55
L114:
	MOV AX, 1		; line 55
	JMP L116		; line 55
L115:
	MOV AX, 0		; line 55
L116:
	PUSH AX		; line 55
L117:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L118
L119:
	MOV AX, [BP-10]		; line 56
	CALL print_output
	CALL new_line
L120:
	MOV AX, [BP-12]		; line 57
	PUSH AX		; line 57
L121:
	MOV AX, 5		; line 57
	PUSH AX
L122:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L123		; line 57
	JMP L124		; line 57
L123:
	MOV AX, 1		; line 57
	JMP L125		; line 57
L124:
	MOV AX, 0		; line 57
L125:
	PUSH AX		; line 57
	POP AX		; line 57
	CMP AX, 0		; line 57
	JE L126		; line 57
L127:
	MOV AX, [BP-12]		; line 58
	CALL print_output
	CALL new_line
	JMP L128		; line 59
L126:
L129:
	MOV AX, [BP-14]		; line 61
	CALL print_output
	CALL new_line
L128:
L118:
	JMP L130		; line 64
L110:
L131:
	MOV AX, [BP-14]		; line 66
	CALL print_output
	CALL new_line
L130:
L101:
L90:
L132:
	MOV AX, [BP-14]		; line 69
	PUSH AX		; line 69
L133:
	MOV AX, 0		; line 69
	PUSH AX
L134:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L135		; line 69
	JMP L136		; line 69
L135:
	MOV AX, 1		; line 69
	JMP L137		; line 69
L136:
	MOV AX, 0		; line 69
L137:
	PUSH AX		; line 69
L138:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L139
L140:
	MOV AX, [BP-14]		; line 70
	CALL print_output
	CALL new_line
L141:
	MOV AX, [BP-2]		; line 71
	PUSH AX		; line 71
L142:
	MOV AX, 10		; line 71
	PUSH AX
L143:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L144		; line 71
	JMP L145		; line 71
L144:
	MOV AX, 1		; line 71
	JMP L146		; line 71
L145:
	MOV AX, 0		; line 71
L146:
	PUSH AX		; line 71
L147:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L148
L149:
	MOV AX, [BP-2]		; line 72
	CALL print_output
	CALL new_line
L150:
	MOV AX, [BP-4]		; line 73
	PUSH AX		; line 73
L151:
	MOV AX, 5		; line 73
	PUSH AX
L152:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L153		; line 73
	JMP L154		; line 73
L153:
	MOV AX, 1		; line 73
	JMP L155		; line 73
L154:
	MOV AX, 0		; line 73
L155:
	PUSH AX		; line 73
L156:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L157
L158:
	MOV AX, [BP-4]		; line 74
	CALL print_output
	CALL new_line
L157:
L148:
L139:
L159:
	MOV AX, [BP-2]		; line 79
	PUSH AX		; line 79
L160:
	MOV AX, 0		; line 79
	PUSH AX
L161:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L162		; line 79
	JMP L163		; line 79
L162:
	MOV AX, 1		; line 79
	JMP L164		; line 79
L163:
	MOV AX, 0		; line 79
L164:
	PUSH AX		; line 79
L165:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L166
L167:
	MOV AX, [BP-4]		; line 80
	PUSH AX		; line 80
L168:
	MOV AX, 0		; line 80
	PUSH AX
L169:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L170		; line 80
	JMP L171		; line 80
L170:
	MOV AX, 1		; line 80
	JMP L172		; line 80
L171:
	MOV AX, 0		; line 80
L172:
	PUSH AX		; line 80
L173:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L174
L175:
	MOV AX, [BP-6]		; line 81
	PUSH AX		; line 81
L176:
	MOV AX, 0		; line 81
	PUSH AX
L177:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L178		; line 81
	JMP L179		; line 81
L178:
	MOV AX, 1		; line 81
	JMP L180		; line 81
L179:
	MOV AX, 0		; line 81
L180:
	PUSH AX		; line 81
L181:
	POP AX		; line 
	CMP AX, 0		; line 
	JE L182
L183:
	MOV AX, [BP-8]		; line 82
	PUSH AX		; line 82
L184:
	MOV AX, 0		; line 82
	PUSH AX
L185:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JG L186		; line 82
	JMP L187		; line 82
L186:
	MOV AX, 1		; line 82
	JMP L188		; line 82
L187:
	MOV AX, 0		; line 82
L188:
	PUSH AX		; line 82
	POP AX		; line 82
	CMP AX, 0		; line 82
	JE L189		; line 82
L190:
	MOV AX, [BP-8]		; line 83
	CALL print_output
	CALL new_line
	JMP L191		; line 84
L189:
L192:
	MOV AX, [BP-6]		; line 86
	CALL print_output
	CALL new_line
L191:
L182:
L174:
L166:
L193:
	MOV AX, [BP-10]		; line 92
	PUSH AX		; line 92
L194:
	MOV AX, 3		; line 92
	PUSH AX
L195:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L196		; line 92
	JMP L197		; line 92
L196:
	MOV AX, 1		; line 92
	JMP L198		; line 92
L197:
	MOV AX, 0		; line 92
L198:
	PUSH AX		; line 92
L199:
	POP AX		; line 92
	CMP AX, 0
	JE L200		; line 92
L201:
	MOV AX, [BP-12]		; line 92
	PUSH AX		; line 92
L202:
	MOV AX, 7		; line 92
	PUSH AX
L203:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L204		; line 92
	JMP L205		; line 92
L204:
	MOV AX, 1		; line 92
	JMP L206		; line 92
L205:
	MOV AX, 0		; line 92
L206:
	PUSH AX		; line 92
	POP AX
	CMP AX, 0
	JE L200		; line 92
L207:
	MOV AX, 1
	JMP L208		; line 92
L200:
	MOV AX, 0		; line 92
L208:
	PUSH AX		; line 92
	POP AX		; line 92
	CMP AX, 0		; line 92
	JE L209		; line 92
L210:
	MOV AX, [BP-10]		; line 93
	CALL print_output
	CALL new_line
L211:
	MOV AX, [BP-12]		; line 94
	CALL print_output
	CALL new_line
	JMP L212		; line 95
L209:
L213:
	MOV AX, [BP-10]		; line 96
	PUSH AX		; line 96
L214:
	MOV AX, 3		; line 96
	PUSH AX
L215:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L216		; line 96
	JMP L217		; line 96
L216:
	MOV AX, 1		; line 96
	JMP L218		; line 96
L217:
	MOV AX, 0		; line 96
L218:
	PUSH AX		; line 96
L219:
	POP AX		; line 96
	CMP AX, 0
	JNE L220		; line 96
L221:
	MOV AX, [BP-14]		; line 96
	PUSH AX		; line 96
L222:
	MOV AX, 1		; line 96
	PUSH AX
L223:
	POP AX
	MOV DX, AX
	POP AX
	CMP AX, DX
	JE L224		; line 96
	JMP L225		; line 96
L224:
	MOV AX, 1		; line 96
	JMP L226		; line 96
L225:
	MOV AX, 0		; line 96
L226:
	PUSH AX		; line 96
	POP AX
	CMP AX, 0
	JE L227		; line 96
L220:
	MOV AX, 1
	JMP L228		; line 96
L227:
	MOV AX, 0		; line 96
L228:
	PUSH AX		; line 96
	POP AX		; line 96
	CMP AX, 0		; line 96
	JE L229		; line 96
L230:
	MOV AX, [BP-14]		; line 97
	CALL print_output
	CALL new_line
	JMP L231		; line 98
L229:
L232:
	MOV AX, [BP-2]		; line 100
	CALL print_output
	CALL new_line
L231:
L212:
L233:
	MOV AX, 0		; line 103
	PUSH AX
L234:
	POP AX		; line 103
	JMP L1		; line 103
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
