#include <stdio.h>
#include <stdlib.h>


/*
subq %rsi, %rdx
imulq %rdx, %rdi
salq $63, %rdx
sarq $63, %rdx
movq %rdi, %rax
orq %rdx, %rax
ret

*/


// https://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
long f(long x, long y, long z) {
    long ret;
    
    // Subtract subq %rsi, %rdx
    ret = z - y;

    // Multiply imulq %rdx, %rdi
    // Move x into ret movq %rdi, rax
    x *= ret;
    
    // Shift left salq $63, %rdx
    ret = ret << 63;
    
    // Shift right sarq $63, %rdx
    ret = ret >> 63;
    
    // Bitwise OR orq %rdx, %rax
    ret = x | ret;
    
    return ret;
    
}

int main() {
/*
    f(1, 2, 4): 2
    f(3, 5, 7): 6
    f(10, 20, 40): 200
    f(30, 50, 70): 600
*/
    printf("f(1, 2, 4): %d\n", f(1, 2, 4));
    printf("f(3, 5, 7): %d\n", f(3, 5, 7)); 
    printf("f(10, 20, 40): %d\n", f(10, 20, 40));
    printf("f(30, 50, 70): %d\n", f(30, 50, 70));

}
