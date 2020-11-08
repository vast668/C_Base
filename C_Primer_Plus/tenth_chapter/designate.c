#include <stdio.h>

#define MONTHS 12

int main()
{
    int i;
    int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};

    for (i = 0; i < MONTHS; i++){
        printf("%2d    %d\n", i, days[i]);
    }


    return 0;
}