#include <stdio.h>
#include <stdlib.h>

//https://www.quora.com/What-does-the-Operator-In-c-do

int evenBit(unsigned int x) {
    
    // Mask to check the even indexes of x  01010101
    int maskX = 0x55555555;
    
    // If maskX and x share "equalivent" bits then replace the mask with those bits(AND)
    int a = maskX & x;
    
    // Maps zero to zero and non-zero to 1 
    printf("Combined = %d \n", !!a);
    
    return !!a;
    
    
    
}



int main() {
        
    evenBit(0x1);// 1
    evenBit(0x2);// 0
    evenBit(0x3);// 1
    evenBit(0x4);// 1
    evenBit(0xFFFFFFFF);// 1
    evenBit(0xAAAAAAAA);// 0
    evenBit(0x55555555);// 1

}


