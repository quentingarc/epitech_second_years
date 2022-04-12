BITS 64
    section .text
    GLOBAL strchr:function
strchr: 
        xor rcx, rcx
departure:
        cmp byte [rdi + rcx], sil ;sil 8bit 
        je print
        inc rcx
        jmp departure
print:
        add	rcx, rdi
	mov	rax, rcx
	ret