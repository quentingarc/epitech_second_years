BITS 64
    section .text
    GLOBAL strcasecmp:function
strcasecmp: 
        xor rcx, rcx
compare:
        mov al, [rsi + rcx]
	mov bl, [rdi + rcx]
        cmp al, bl
        jne exit
        cmp al, 0
        cmp bl, 0
        je exit	
        inc rcx
        jmp compare
exit:
        sub bl, al
        movsx rax, bl ;rax valeur que tu return
	ret
