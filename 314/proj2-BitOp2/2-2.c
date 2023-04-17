#include <stdio.h>
#include <stdlib.h>


unsigned int extract(unsigned int x, int i) {
    
    unsigned int mask = 0xFF; // 0x000000FF;
    
    // Shift mask: convert byte to bit
    int shift = i << 3; 
    mask <<= shift;
    
    // Compares mask and x (AND)
    int comp = x & mask;
    
    // Shift left all the way to the front
    comp = comp << ((3 - i) << 3);
    
    // shift all the way back right (sign extend)
    int extract = comp >> 24;
    printf("Extract = 0x%08X \n", extract);
    
}



int main() {

    extract(0x12345678, 0); // 0x00000078
    extract(0xABCDEF00, 2); // 0xFFFFFFCD
    
}



    
  

