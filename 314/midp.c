#include <stdio.h>
#include <stdlib.h>


int isOdd(int x) {
    
    int mask = 0x1;
    return mask & x;
    // extract sign bit of x
//     int extract = x >> 31;
    
    // If the sign bit is 1 then it is odd
//     return extract & 1;
}



int *ptr(long *arr, long i) {
    return arr + i;
    
}

int main() {
    ptr()
    printf("%d\n", isOdd(5));
    printf("%d\n", isOdd(100));
    printf("%d\n", isOdd(1));
    printf("%d\n", isOdd(2));
    
}
