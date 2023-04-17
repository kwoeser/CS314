#include <stdio.h>
#include <stdlib.h>


unsigned int combine (unsigned int x, unsigned int y) { 
    
    // Create bit masks that to isolate bytes
    unsigned int maskX = 0xff000000;
    unsigned int maskY = 0x00ffffff;
    
    
    // If the maskX and x share the same bits (AND)
    unsigned int a = maskX & x;
    unsigned int b = maskY & y;
    
    // Add a and b together (OR)
    unsigned int combined = a | b;

    printf("Combined = 0x%08X \n", combined);
    return combined;
}





int main() {
    combine(0x12345678, 0xABCDEF00); // 0x12CDEF00
    combine(0xABCDEF00, 0x12345678); // 0xAB345678
    
}



