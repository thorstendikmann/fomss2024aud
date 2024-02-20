# x86_64 Assembler
# AT&T Synatx by default [destination first, source second]

.global _start

.text

_start:
    mov $1, %rax            # system call 1 -> write
    mov $1, %rdi            # file handler 1 -> stdout
    mov $message, %rsi      # address of string "message" to output
    mov $52, %rdx           # number of bytes ... count it!!
    syscall

    # syscall exit(0)
    mov $60, %rax           # system call 60 -> exit
    xor %rdi, %rdi          # return code 0
    syscall

message:
    .ascii "Hello world - from x86_64 assembler in AT&T Syntax.\n"
