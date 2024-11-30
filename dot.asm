section .text
bits 64
default rel
global getSDotx64


getSDotx64:
    push rbp               
    mov rbp, 0  
    xorps xmm0, xmm0        

L1:
    cmp rbp, r8
    
    je done

    movss xmm1, dword [rcx]
    
    movss xmm2, dword [rdx]

    mulss xmm1, xmm2

    addss xmm0, xmm1

    add rcx, 4
    add rdx, 4
    
    inc rbp
    jmp L1

done:
    pop rbp
    xor rax, rax
    ret
