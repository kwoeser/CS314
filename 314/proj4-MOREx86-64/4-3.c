#include <stdio.h>
#include <stdlib.h>

#define N 4
typedef long array_t[N][N];
/*
void transpose(array_t a) {
    for (long i = 0; i < N; ++i) {
        for (long j = 0; j < i; ++j) {
            long t1 = a[i][j];
            long t2 = a[j][i];
            a[i][j] = t2;
            a[j][i] = t1;
        }
    }
}
*/


/* 

 .L3:
    movq (%rax), %rcx   // Move %rax to %rcx; store ith rows into *rp
    movq (%rdx), %rsi   // Move %rdx to %rsi; store ith cols into *cp 
    
    // Temp = row, temp = col
    movq %rsi, (%rax)   // Move %rsi to %rax; swap the rows with the columns ' 
    movq %rcx, (%rdx)   // Move %rcx to %rdx; store ith cols into *cp 
    addq $8, %rax       // add 8 to %rax; 8 bytes = 1 long    +1 to rp
    addq $32, %rdx      // add 32 to %rdx; 32 bytes = 4 long  +4 to cp  
    
    // Loop, if statement
    cmpq %r9, %rax      // Compare register 9 with the %rax 
    jne .L3             // If cmp above is true jump to L3 
    
*/


//https://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
void transposeOpt(array_t a) {
    for (long i = 0; i < N; ++i) {
        long *rp = &a[i][0];
        long *cp = &a[0][i];
        
        for (long j = 0; j < i; ++j) {
            // Temp variables for ith rows and columns
            long tempRP = *rp;
            long tempCP = *cp;
            // Swap rows and columns; vice versa 
            *rp = tempCP;
            *cp = tempRP;
            // Advance the pointers
            rp += 1;
            cp += 4;
        }
        
    }
}



void print(array_t a) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}



    
int main() {
    
    array_t b = {{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}};
    transposeOpt(b);
    print(b);
     /* {{1, 5, 9, 13},
        {2, 6, 10, 14},
        {3, 7, 11, 15},
        {4, 8, 12, 16}}
    */   
    

}
