#include <stdio.h>

void printBytes(unsigned char *start, int len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
    
}
    
void printInt(int x) {
    printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
    printBytes((unsigned char *) &x, sizeof(float));
}



void printShort(short int x) {
    printBytes((unsigned char *) &x, sizeof(short int));
}

void printLong(long int x) {
    printBytes((unsigned char *) &x, sizeof(long int));
}

void printLongLong(long long int x) {
    printBytes((unsigned char *) &x, sizeof(long long int));
}

void printDouble(double x) {
    printBytes((unsigned char *) &x, sizeof(double));
}



/*
Comments
The amount of numbers each function prints is based off the the size of the data type. 
For instance a int will print 4 numbers because integers are 4 bytes. While a long int 
will print 8. There is also something off on some all of them. Some end with what seems
to be randomness like f0 3f or 80 3f. While some start with 01. I tried changing the input
to 5 instead of 1 and what happened was that the 01's turned into 05's. The rest of the 00's
stayed the same but the sam places that had f0 3f and 80 3f changed to different numbers like 14 40 or a0 40. 

Endianness the order in which a sequence of bytes is stored in computer memory. I just saw the Piazza post after finishing this.
*/
int main () {
    printInt(1);
    printFloat(1.);
    printShort(1);
    printLong(1);
    printLongLong(1);
    printDouble(1.);
    
    
       
//     printInt(5);
//     printFloat(5.);
//     printShort(5);
//     printLong(5);
//     printLongLong(5);
//     printDouble(5.);
}
