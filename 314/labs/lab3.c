// convert 11100101 from 8 bit float to decimal

// separate sign, exponent, and mantissa

//s eeee mmm: 1 1100 101


// restore the mantissa leading 1

//1.101


// subtract bias from exponent. bias = 2^(k-1)-1, where k = number of digits in exponent field (3 for 8bit floats)

/* bias: 2^(4-1)-1 = 2^3-1 = 7
   exp: 1100 = 2^0 * 0 + 2^1 * 0 + 2^2 * 1 + 2^3 * 1 = 0 + 0 + 4 + 8 = 12
   12 - 7 = 5 is our "denorm factor"
*/


// denormalize mantissa: move decimal point according to the preceeding step

//1.101 * 2^5 = 110100.00


// convert to decimal: multiply each digit by 2^x, where x is the "place" of the digit, and then sum

// 2^6 2^5 2^4 2^3 2^1 2^0. 2^(-1) 2^(-2)...
// 1   1   0   1   0   0  . 0      0
// 32 + 16 + 0 + 4 + 0 + 0 = 52


// apply sign bit

//-52

#include <stdio.h>

unsigned int unsignedBinaryToDecimal(unsigned char *s, int length) {
    unsigned int result = 0;
    for (int i = 0; i < length; i++) {
        // TODO: implement
        
        // Get bits from s
        unsigned int bit = s[length-i-1];
        
        // exp
        // Normally i << 3
        // 1, 2, 4, 8 
        unsigned int exp = 1 << i;
        
        // Multiply bit and exp
        unsigned int mult = bit * exp;
        
        // Add to the result
        result += mult;
        
        printf("Step %d: %d * %d = %d.\n", i, bit, exp, mult);
        
    }
    return result;
}



int main() {
    unsigned char s[4] = {1, 0, 1, 1};
    //unsigned char s[8] = {0, 1, 1, 0, 1, 0, 1, 1 };

    printf("%d\n", unsignedBinaryToDecimal(s, 4));
}
