#include <stdio.h>

#define SQUARE(X) X*X
#define PR(X) printf("The result is %d\n", X);

int main(void)
{
    int x = 5;
    int z;
    printf("x = %d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x): ");
    PR(z);
    
    return 0;
}