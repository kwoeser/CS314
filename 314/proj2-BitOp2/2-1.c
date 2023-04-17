#include <stdio.h>
#include <stdlib.h>


unsigned int mask(int n) {
    
    // Exp shift left depending on n
    unsigned int exp = 1 << n; // i=0:1 -> i=1:2 -> 4 -> 8
    
    // Since counting starts at zero the we need to subtract 1
    exp = exp - 1;
    
    printf("0x%0X\n", exp);
    
}



int main() {
    
    mask(2); // 0x3
    mask(3); // 0x7
    mask(5); // 0x1F
    mask(8); // 0xFF
    mask(16); // 0xFFFF
    mask(31); // 0x7FFFFFFF
    
    
}


