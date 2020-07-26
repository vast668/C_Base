#include <stdio.h>

#define SIZE 4
int main()
{
    short index;
    short dates[SIZE];
    short * pti;
    double bills[SIZE];
    double * ptf;
    pti = dates;    //assign address's name to pointer 
    ptf = bills;
    printf("%23s %15s\n", "short", "double");
    for (index = 0; index < SIZE; index++){
        printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
    }

    return 0;
}