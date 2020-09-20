#include <stdio.h>
#include <math.h>

#define PR(X, ...)  printf("Message " #X ": " "__VA_ARGS__")
#define PR2(...) printf(__VA_ARGS__)

int main(void)
{
    double x = 48;
    double y;
    y = x*x;

    float wt = 9;
    float sp = 0;

    PR(1, "x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);
    PR2("howdy");
    PR2("weight = %d, shipping = $%.2f\n", wt, sp);

    return 0;
}

/*
这里不需要指定参数的数量
*/