#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ColorPoint {
    long a;
    long r;
    long g;
    long b;
};


long f(struct ColorPoint **points, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += points[j][i].a;
            sum += points[j][i].r;
            sum += points[j][i].g;
            sum += points[j][i].b;
        }
    }
    return sum;
}


long g(struct ColorPoint **points, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += points[i][j].a;
            sum += points[i][j].r;
            sum += points[i][j].g;
            sum += points[i][j].b;
        }
    }
    return sum;
}



struct ColorPoint** create2DArray(int n) {
    // Array to hold a pointer to the beginning of each row
    struct ColorPoint **points = (struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
    for (int i = 0; i < n; ++i) {
        // Array to hold each row
        points[i] = (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
        for (int j = 0; j < n; ++j) {
            // Init the ColorPoint struct
            points[i][j].a = rand();
            points[i][j].r = rand();
            points[i][j].g = rand();
            points[i][j].b = rand();
        }
    }
    return points;
}


void free2DArray(struct ColorPoint** points, int n) {
    for (int i = 0; i < n; ++i) {
        free(points[i]);
    }
    
    free(points);
}



int main () 
{   
    /*
    The results for both function f and g are 18015422859182080.000000.
    The times should how function g is far faster then fucntion f. Basically 6 times faster. The average time for function f was around 60.27 seconds. 
    The average time for function g was around 11.75 seconds. 
    
    Function f is slower then function g because of the higher miss rate. From the answers of part a and b we can see that function f miss rate was higher. Cache misses slow down performance.
     */

    
    // allocate a 2048 x 2048 array of ColorPoint structs 
    // then measure the time to call f and g functions above with this array as an argument
    struct ColorPoint **arr = create2DArray(2048);
    
    
    // f time
    float resultF;
    
    clock_t start = clock();
    for (int i = 0; i < 1000; ++i) {
        resultF = f(arr, 2048);
    }
    clock_t end = clock();
    
    double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("resultF = %f, f time: %f\n", resultF, totalTime1);

    
    
    // g time
    float resultG;
    
    start = clock();
    for (int i = 0; i < 1000; ++i) {
        resultG = g(arr, 2048);
    }
    end = clock();
    
    double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("resultG = %f, g time: %f\n", resultG, totalTime2);
    
    
    free2DArray(arr, 2048);
}
