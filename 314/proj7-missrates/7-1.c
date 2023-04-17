#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int cache_numSets = 256;
int cache_size = 16;


// Functions similar to lab 8
unsigned int getOffset(unsigned int address) 
{
    // 8 OFFSET BITS (lowest sig byte)
    // int cache_size = log2(256);
    return address & (cache_size - 1);

}



unsigned int getSet(unsigned int address)
{
    // Shift adress to lower 4 bits
    int bt = address >> 4;
    
    return bt & cache_numSets - 1;
}



unsigned int getTag(unsigned int address)
{   
    return address >> 12;
}


int main() 
{
    unsigned int testAddr1 = 0x12345678;
    unsigned int testAddr2 = 0x87654321;
    printf("0x%08x: offset - %x, tag - %x, set - %x.\n", testAddr1, getOffset(testAddr1), getTag(testAddr1), getSet(testAddr1));
    
    printf("0x%08x: offset - %x, tag - %x, set - %x.\n", testAddr2, getOffset(testAddr2), getTag(testAddr2), getSet(testAddr2));
    
    //     0x12345678: offset: 8 - tag: 12345 - set: 67
    //     0x87654321: offset: 1 - tag: 87654 - set: 32
}
