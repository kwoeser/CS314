#include <stdio.h>
#include <stdlib.h>


// int f(int a, int b, int c, int d, int n) {
//     int result = 0;
//     for (int i = 0; i < n; i += 2) {
//         for (int j = 0; j < n; j += 2) {
//             result += a * b + i * c * d + j;
// 
//             
//         }
//     }
//     return result;
// }


int f(int a, int b, int c, int d, int n) {
    int result = 0;
    for (int i = 0; i < n; i += 2) {
        // Multiply a with b 
        int axb = a*b;
        // Multiply i with c and d
        int ix = i * c * d;
        for (int j = 0; j < n; j += 2) {
            result += axb + ix + j;

            
        }
    }
    return result;
}


// Correct ?????
int f(int a, int b, int c, int d, int n) {
    int result = 0;
    // Multiply a with b 
    int axb = a*b;
    // Multiply  c and d
    int cd = c*d;
    
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            result += axb + i * cd + j;

            
        }
    }
    return result;
}




int main() {
    printf("%d\n", f(1, 2, 3, 4, 5));// 252
    printf("%d\n", f(2, 3, 4, 5, 6));// 432
    printf("%d\n", f(6, 5, 4, 3, 2));// 30
    printf("%d\n", f(5, 4, 3, 2, 1));// 20
    
}
