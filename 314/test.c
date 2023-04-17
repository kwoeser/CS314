#include <stdio.h>
#include <stdlib.h>



struct IntArray {
    int length;
    int *dataPtr;
};


struct IntArray* mallocIntArray(int length) {
    // Allocate, initialize and return a pointer to a new struct intArray 
    struct IntArray *array = malloc(sizeof(struct IntArray));
    
    // Sets length 
    array->length = length;
    // Allocates memory for dataPtr
    array->dataPtr = (int *)malloc(length * sizeof(int));
    return array;
    
}

// Frees the instance's dataPtr and frees the instance
void freeIntArray(struct IntArray *arrayPtr) {
    free(arrayPtr);
    free(arrayPtr->dataPtr);
}




int readInt() 
{
    char lineBuf[128];
    char *p = NULL;
    int n;
    
    while (1) {
            printf("Enter int: ");

            // char* fgets (char* str, int num, FILE* stream);
            fgets(lineBuf, sizeof(lineBuf), stdin);
            
            // long int strtol (const char* str, char** endptr, int base);
            n = strtol(lineBuf, &p, 10);
            
            if (lineBuf != p) {
                // Worked
                break;
            } else { 
                printf("Invalid input \n");
                continue;
            }
            
    }
    

    return n;
    
}



//https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
void readIntArray(struct IntArray *array) {
    int i;

    for (i = 0; i < array->length; i++) {
        
        array->dataPtr[i] = readInt();
        printf("\n");
      
        
    }
}

//https://stackoverflow.com/questions/8403447/swapping-pointers-in-c-char-int
void swap(int *xp, int *yp) {
    // set the yp value to xp location vice versa
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    
    
}



void sortIntArray(struct IntArray *array) {
    // Bubble sort, repeatdly call your swap function
    int i, j;

	for (i = 0; i < array->length; i++) {
		for (j = i + 1; j < array->length; j++) {
			if (array->dataPtr[j] < array->dataPtr[i]) {
                swap(&array->dataPtr[i], &array->dataPtr[j]);
			}	
		}
	}
}


void printIntArray(struct IntArray *array) {
    int i;
    
    printf("[");
    for(i = 0; i < array->length - 1; i++) {
        printf("%d, ", array->dataPtr[i]);
    }
    printf("%d]\n", array->dataPtr[i]);
}



int main() {
   
    int length;
    char lineBuf[128];
    int n = 1;
    
    
    while (n == 1) {
        printf("Enter Length: ");
        // char* fgets (char* str, int num, FILE* stream);
        fgets(lineBuf, sizeof(lineBuf), stdin);
                
        // long int strtol (const char* str, char** endptr, int base);
        length = strtol(lineBuf, NULL, 10);
        
        if (length <= 0) {
            printf("Invalid Input\n");
        } else {
            n = 0;
//             break
        }
    
    }
    
    struct IntArray *array = mallocIntArray(length);
    readIntArray(array);
    sortIntArray(array);
    printIntArray(array);
    freeIntArray(array);
    

    
        
}
