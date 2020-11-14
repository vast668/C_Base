#include <stdio.h>
#include <stdlib.h>


int plus(int a, int b)
{
    exit(-1);
}

int main(void)
{
    int a = 9;
    int b = 8;
    int c = plus(a, b);
    printf("%d\n", c);

    return 0;
}