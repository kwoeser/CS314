#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float f(float *a, int n) {
    float prod = 1.0f;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0.0f) {
            prod *= a[i];
        }
    }
    return prod;
}


float g(float *a, int n) {
    float prod = 1.0f;
    for (int i = 0; i < n; ++i) {
        prod *= a[i];
    }
    return prod;
}


float* createArray(int size) {
    float *a = (float *)malloc(size * sizeof(float));
    for (int i = 0; i < size; ++i) {
        // 50% chance that a[i] is 0.0f, random value on the range
        // [0.76, 1.26] otherwise.
        float r = rand()/(float)RAND_MAX;
        a[i] = r < 0.5f ? 0.0f : r + 0.26f;
    }
    return a;
}


int main() 
{
    /* Function g(arrayB) is faster then f(arrayA). The func g is faster because we remove the zero check if statement. 
    
    
    Function g(arrayC) is faster then both g(arrayB) and f(arrayA). This function is faster then both because there is less elements we need to go through in function g(arrayC).
    
    
    The results for all three parts was 0.000018. The average time for a was around 0.040000. The average time for b was around 0.009000. The average time for c was around 0.004000. Each function as ran 1000 times.
     */
    
    // f time
    float *arrayA = createArray(10000);
    float resultA;
    clock_t start = clock();
    for (int i = 0; i < 1000; ++i) {
        resultA = f(arrayA, 10000);
    }
    clock_t end = clock();
    
    double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("resultA = %f, f time: %f\n", resultA, totalTime1);

    
    
    // g time
    float *arrayB = malloc(10000 * sizeof(float));
    
    // Changes all 0.0f to 1.0f
    for (int i = 0; i < 10000; i++) {
        if (arrayA[i] == 0.0f) {
            arrayB[i] = 1.0f;
        } else {
            arrayB[i] = arrayA[i];
        }
    }

    float resultB;
    start = clock();
    for (int i = 0; i < 1000; ++i) {
        resultB = g(arrayB, 10000);
    }
    end = clock();
    
    double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("resultB = %f, g time: %f\n", resultB, totalTime2);
    
    
    
    // c time; using g func
    float *arrayC = malloc(10000 * sizeof(float));
    
    // counter for arrayC that only increment for non zeroes
    int count = 0;
    for (int i = 0; i < 10000; i++) {
        if (arrayA[i] != 0.0f) {
            arrayC[count] = arrayA[i];
            count ++;
        } 
    }
    
    
    float resultC;
    start = clock();
    for (int i = 0; i < 1000; ++i) {
        resultC = g(arrayC, count);
    }
    end = clock();
    
    double totalTime3 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("resultC = %f, c time: %f\n", resultC, totalTime3);
    
    
    // free arrays
    free(arrayA);
    free(arrayB);
    free(arrayC);


}




