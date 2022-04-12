BITS 64
    section .text
    GLOBAL strncmp:function
strncmp: 
        xor rcx, rcx

compare:
        mov al, [rsi + rcx] ;rsi 2 eme parametre mov 
	mov bl, [rdi + rcx]
        cmp al, bl
        jne exit ; si al diff bl
        cmp al, 0 ;compare al ou r8b = 0
        cmp bl, 0 ;compare bl ou R9b = 0
        je exit
        inc rcx
        cmp rcx, rdx
        je exit
        jmp compare
exit:
        sub bl, al 
        movsx rax, bl
	ret