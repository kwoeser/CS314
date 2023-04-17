
#include <stdio.h>
#include <stdlib.h>

//https://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
long fact(long x) {
    
    if (x <= 1) {
        return 1;
    }
    return x * fact(x - 1);
}


int main() {
    fact(1); //1
    fact(3); //6
    fact(5); //120    
}

/*


fact:   
        cmpq    $1, %rdi           // Compare 1 and x; if (x <= 1) 
        jle     .L3                // If x <= 1 then jump to L3; x <= 1
        pushq   %rbx               // Push x onto stack
        movq    %rdi, %rbx         // Move the value of %rdi to %rbx
        leaq    -1(%rdi), %rdi     // Subtract 1 from x; (x-1)
        call    fact               // Subroutine call fact, fact(x-1)
        imulq   %rbx, %rax         // Multiply the %rbx with the result; x * fact(x-1)
        popq    %rbx               // Pop %rbx off the stack
        ret                        // Return 
.L3:
        movl    $1, %eax           // Move 1 to %eax
        ret                        // Return 1 if the jump condition on line 2 is true
    
*/
