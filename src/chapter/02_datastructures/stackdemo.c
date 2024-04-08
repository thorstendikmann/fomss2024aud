#include <stdio.h>

/**
 * Simple demonstrator how a C function is called 
 * and how it will look in assembler.
 * 
 * In x86_64: To call a function, the program should 
 * place the first six integer or pointer parameters in the
 * registers %rdi, %rsi, %rdx, %rcx, %r8, and %r9; 
 * subsequent parameters (or parameters larger than 64 bits) 
 * should be pushed onto the stack, with the first argument topmost
 * See https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf
*/
int add(int a, int b)
{
    int d = a + b;
    return d;
}

int main(void)
{
    add(7, 11);
    return 0;
}
