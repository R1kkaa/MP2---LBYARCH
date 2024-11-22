section .data
    conv:  dq 3.6
section .text
bits 64
default rel
global calculateacceleration

calculateacceleration:
    subsd xmm0, xmm1
    divsd xmm0, [conv]
    divsd xmm0, xmm2 
    CVTSD2SI rax, xmm0
    ret