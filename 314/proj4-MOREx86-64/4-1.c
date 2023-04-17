#include <stdio.h>
#include <stdlib.h>

/*
long sum(long from, long to) {
    long result = 0;
    
    do {
        result += from;
        ++from;
    } while (from <= to);

    return result;
}
*/

/*
Part A

long sum(long from, long to) {
    long result = 0;
    
    // ADD label
    ADD: {
        // Statements
        result += from;
        ++from;
    }
    
    
    while (from <= to) {
        // Goes to the ADD got label
        goto ADD;
    }
   
    printf("%d\n", result);
    return result;
}
*/


// https://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
long sum(long from, long to) {
    // Declare and initialize result var – *do not modify*.
    long result = 0;
    // Ensure that argument *from* is in %rdi,
    // argument *to* is in %rsi, *result* is in %rax - *do not
    // modify*.
    __asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from ));
    __asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
    __asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));
    // Your x86-64 code goes below - comment each instruction...
    __asm__(
    ".LOOP:"
    // x86-64 instruction to add *from* to *result*
    "addq %rdi, %rax;"
    // x86-64 instruction to add 1 to *from*
    "addq $1, %rdi;"
    // x86-64 instruction to compare *from* and *to*
    "cmpq %rdi, rsi;"
    "jle .LOOP;"
    );
    // Ensure that *result* is in %rax for return - *do not modify*.
    __asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));
    return result;
    
}


int main() {
    printf("sum(1, 6): %ld\n", sum(1, 6));
    printf("sum(3, 5): %ld\n", sum(3, 5));
    printf("sum(5, 3): %ld\n", sum(5, 3));
}

