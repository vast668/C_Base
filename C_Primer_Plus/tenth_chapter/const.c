#include <stdio.h>

#define MONTHS 12

int main()
{

    #if 0
    const int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int * p_days = NULL;

    // p_days = days;       //error, 因为p_days是普通指针，而数组是常量，不可被修改

    // days[9] = 89;    //error! can't modify 
    double rates[5] = {88.9, 88.33, 99.9, 56.3, 78.1};
    const double * pd = rates;
    printf("*pd = %lf\n", *pd);
    // *pd = 0.77;      //error, *pd为const常量，不可更改

    rates[0] = 99;
    printf("*pd = %lf\n", *pd);     //it's ok
    printf("*pd++ = %lf\n", *pd++);     //后置++，先*p，再p++ *pd++ = 99.000000
    printf("*pd = %lf\n", *pd);     //*pd = 88.330000  pd 可以指向其他的地方，没有对pd指针做限制，只对指向的值做了限制
    #endif
    //position of const 
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int * const p_days = days;
    printf("*p_days = %d\n", *p_days);      //*p_days = 31

    // p_days = &days[8];       //error !!! p_days can't pointer other palce
    *p_days = 99;
    printf("*p_days = %d\n", *p_days);  //correct! can change value of pointer argument

    return 0;
}