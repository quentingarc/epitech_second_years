
BITS 64
    section .text           ; begining of the code
    GLOBAL strlen:function  ; strlen function
strlen: 
        xor rax, rax ; incrementer en 0 rax = valeur retourné
while: 
        cmp byte[rdi + rax], 0 ; rdi = rec 1 arg rsi = 2 arg ...
        je finish ; vas a finish si cmp est egal
        inc rax ; +1
        jmp while ;return a while
finish:
        ret

        

