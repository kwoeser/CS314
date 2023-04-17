#include <stdio.h>
#include <stdlib.h>


//2 
unsigned int replace (unsigned int x, int i, unsigned char b) {

    // Shifts left based off i
    unsigned int one = 0xff << (i << 3);
    
    // Flips all 1's to 0's and vice versa (Negation)
    one = ~one;
    
    // If one and x share "equalivent" bits(AND)
    unsigned int a = one & x;

    // Shift b based off i
    unsigned int shiftB = b << (i << 3);
    
    // Add a with shiftB (OR)
    unsigned int replaced = a |shiftB;
    printf("Replaced = 0x%08X \n", replaced);
    return replaced;

}


int main() {
    replace(0x12345678, 3, 0xAB); //0xAB345678
    replace(0x12345678, 0, 0xAB); //0x123456AB
    
  
}
