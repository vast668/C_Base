#include <stdio.h>

int imax();

int main()
{
    imax(1);
    printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3));
    printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));
    return 0;
}

int imax(int n, int m)
// int n, m;
{
    return (n > m ? n : m);
}