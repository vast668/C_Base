#include <stdio.h>

int main()
{
    float num1 = 333333.33333333333333;
    double num2 = 333333.33333333333333;

    printf("src data: 333333.33333333333333\n   float: %.14f\n  doubele: %.14lf \n", num1, num2);


    
    return 0;
}
/*
src data: 333333.33333333333333
   float: 333333.34375000000000         有7位有效数字   
  doubele: 333333.33333333331393        有16位有效数字
*/