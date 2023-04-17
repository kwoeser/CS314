#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest) {
    float sum = 0.0f;
    for (int i = 0; i < length; ++i) {
        sum += u[i] * v[i];
    }
    *dest = sum;
}

/*
# u in %rbx, v in %rax, length in %rcx, i in %rdx, sum in %xmm1
.L87:
    movss (%rbx, %rdx, 4), %xmm0 # Get u[i]
    movss (%rax, %rdx, 4), %xmm2 # Get v[i]
    mulss %xmm2, %xmm0 # Multiply by u[i] * v[i]
    adds %xmm0, %xmm1 # Add to sum
    addq $1, %rdx # Increment i
    cmpq %rcx, %rdx # Compare i to length
    jl .L87 # If <, keep looping
*/


// 2C)

//https://www.youtube.com/watch?v=hsQj7n-8Q3A
void inner2(float *u, float *v, int length, float *dest) {
    float sum1 = 0.0f;
    float sum2 = 0.0f;
    float sum3 = 0.0f;
    float sum4 = 0.0f;
    
    // Four iterations in loop instead of the usual 1; loop unrolling
    for (int i = 0; i < length; i+=4) {
        sum1 += u[i] * v[i];
        sum2 += u[i+2] * v[i+2];
        sum3 += u[i+3] * v[i+3];
        sum4 += u[i+4] * v[i+4];
    }

    // Add all the sums together 
    *dest = sum1 + sum2 + sum3 + sum4;
    
}


int main() {
    
    // Similar to lab7 
    for (int size = 1000; size <= 10000; size += 1000)
    {
        float u[size], v[size];
        
        for (int i = 0; i < size; ++i) 
        {
            u[i] = rand()/(float)RAND_MAX < 0.5 ? 0 : 1;
            v[i] = rand()/(float)RAND_MAX < 0.5 ? 0 : 1;
        }


        
        float dest;
        // inner
        clock_t start = clock();
        for (int i = 0; i < 1000; ++i) {
            inner(u, v, size, &dest);
        }
        clock_t end = clock();
        
        double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;

        
        // inner2
        start = clock();
        for (int i = 0; i < 1000; ++i) {
            inner2(u, v, size, &dest);
        }
        end = clock();
        
        double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;

        
        
        printf("size: %d, inner1 time: %f\n", size, totalTime1);
        printf("size: %d, inner2 time: %f\n\n", size, totalTime2);

    }
    
}





