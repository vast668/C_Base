#include <stdio.h>

int main()
{
    const int FIRST_OZ = 46;
    const int NEXT_OZ = 23;
    int ounces, cost;
    printf(" opunces cost\n");
    for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
        printf("%5d, $%4.2f\n", ounces, cost / 100.0);

    return 0;
}

/*
for 循环中的表达式可以有逗号的
*/