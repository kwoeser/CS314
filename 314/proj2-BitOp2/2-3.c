#include <stdio.h>
#include <stdlib.h>


int ge(float x, float y) {
    unsigned int ux = *((unsigned int*) &x); // convert x raw bits
    unsigned int uy = *((unsigned int*) &y); // convert y raw bits
    unsigned int sx = ux >> 31; // extract sign bit of ux
    unsigned int sy = uy >> 31; // extract sign bit of uy
    ux <<= 1; // drop sign bit of ux
    uy <<= 1; // drop sign bit of uy
    // TODO: return using sx, sy, ux, uy
    
    // signs by cases
    // values by cases

    
    // If x is pos and y negative grab positive number
    int xPosyneg = (sx == 0 && sy == 1 && ux >= uy);
    
    // If x and y are negative check if x is greater then or equal to y; vice versa for bothNeg
    int bothPos = (sx == 0 && sy == 0 && ux >= uy);
    int bothNeg = (sx == 1 && sy == 1 && ux <= uy);

    // if x and y are either +0.0 or -0.0
    int zero = (ux == 0 && uy == 0);
    
    // If x is positive zero and y is negative get x
    int xZerogreater = ((sx == 0 && ux == 0) && sy == 1);
  
    
    // Will print 1 if any of these are true otherwise 0 (OR)
    printf("%d\n",  xPosyneg || zero || bothPos || bothNeg || xZerogreater);


}



int main() {
    
    ge(0.0f, 0.0f);// 1 
    ge(-0.0f, 0.0f);// 1 
    ge(0.0f, -0.0f);// 1 
    ge(-0.0f, -0.0f);// 1 
    ge(1.0f, 1.0f);// 1
    ge(-1.0f, 1.0f);// 0 
    ge(1.0f, -1.0f);// 1 
    ge(-1.0f, -1.0f);// 1 
    ge(-1.0f, 0.0f);// 0  
    ge(0.0f, -1.0f);// 1  
    ge(1.0f, 0.0f);// 1 
    ge(0.0f, 1.0f);// 0
    ge(1.0f, 2.0f);// 0
    ge(2.0f, 1.0f);// 1 
    ge(-1.0f, -2.0f);// 1  
    ge(-2.0f, -1.0f);// 0 
    
}



