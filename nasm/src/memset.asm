BITS 64
    section .text
    GLOBAL memset:function
memset: 
        xor rcx, rcx
add:
        cmp rcx, rdx
        je print 
        mov [rdi + rcx], rsi ; rdi 1er arg  rsi 2eme
        inc rcx
        jmp add
print:
        mov rax, rdi
        ret