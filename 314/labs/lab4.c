#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;
    int *dataPtr;
    
} intArray;

//typedef:
// instead of "struct intArray", you can just use "intArray"

int readInt() 
{
        char lineBuf[10];
        char *p = NULL;
        int n;

        while (1) {
                // char* fgets (char* str, int num, FILE* stream);
                fgets(lineBuf, sizeof(lineBuf), stdin);

                // long int strtol (const char* str, char** endptr, int base);
                n = strtol(lineBuf, &p, 10);
                if (lineBuf != p) {
                    
                        printf("Pointers after read:\n\tLinebuf: %p\n\tp: %p\n", 
                                lineBuf, p);
                        break;
                } else {
                    printf("Invalid input\n");
                    break;
                }

                
        }

        return n;
}

long f(long x, long y, long z) 
{
        // x in %rdi, y in %rsi, z in %rdx, %rax holds return value.
        // Comment each line of assembly in terms of x, y, and z
        // good reference: https://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html (or find another resource that works for you)

        // leaq (%rdi,%rsi), %rax
        // We know x is in rdi, and y is in rsi
        // formula is for "leaq (a, b, c), d":
        // d = a + b*c
    
        long result = x + y;
    
        // imulq %rdx, %rax
        
        // for imulq a, b:
        // b = a*b
        
        result *= z;
        // ret

        // after comments, implement in C (replace "return 0" to match asm)
        // compile with flags: -Wall -Og -S -masm=att for .s file, or use godbolt

        return result;
}

int main() 
{
        // ---------- PART 1: memory management ----------

        // create int array of fixed length, but with malloc
//         length = readInt();
//         intArray intArr = mallocIntArr(length);
//         intArr.length;
//         &intArr->length;

        int i, length, *arr;
        
        length = 3;
        
        
        // Lives on the stack, fixed at compiled time
//         int exampleArray[length];
        
        
        // Pointer to int size of int * length
        // On the heap, dynamic memory, resolved at run time
        arr = (int *) malloc(length * sizeof(int));

        // loop over array and fill with readInt

        for (i = 0; i < length; i++) 
        {
            printf("Enter an Integer: ");
            arr[i] = readInt();
            printf("\n");
            
        }

        // loop over again and print
        printf("[");
        for (i = 0; i < length - 1; i++) 
        {
            printf("%d, ", arr[i]);
        }
        printf("%d]\n", arr[i]);
        // free malloc'd array pointer

        free(arr);
        // ---------- PART 2: reverse engineering ASM ----------

        // implement f() above

        printf("f(1, 2, 3): %ld.\n",   f(1, 2, 3));
        printf("f(7, 11, 13): %ld.\n", f(7, 11, 13));
}
