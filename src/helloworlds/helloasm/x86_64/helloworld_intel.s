# x86_64 Assembler
# Intel synatx [source first, destination second]

.intel_syntax noprefix

.section .data
    hello:
        .ascii "Hello world - from x86_64 assembler in Intel Syntax.\n"

.section .text

.globl _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, offset hello
    mov rdx, 53            # Length of string
    syscall

    mov rax, 60
    mov rdi, 0
    syscall
