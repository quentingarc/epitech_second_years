BITS 64
    section .text
    GLOBAL memcpy:function
memcpy: 
        xor rcx, rcx
add:
        cmp rcx, rdx ; rdx 3 eme arg
        je print
        mov r8b, byte[rsi + rcx]
        mov byte[rdi +rcx], r8b
        inc rcx
        jmp add
print:
        mov rax, rdi
        ret