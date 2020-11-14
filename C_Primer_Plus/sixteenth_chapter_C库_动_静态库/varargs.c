#include <stdio.h>
#include <stdarg.h>

double sum(int, ...);

int main(void)
{
    double s, t;
    s = sum(3, 3.4, 2.5, 3.9);
    t = sum(6, 8.4, 8.2, 9.3, 3.9, 3.0, 7.4);

    printf("s = %g\n", s);
    printf("t = %g\n", t);

    return 0;
}


double sum(int lim, ...)
{
    va_list ap;
    double tot = 0;
    int i;

    va_start(ap, lim);
    for (i = 0; i < lim; i++)
    {
        tot += va_arg(ap, double);
    }
    va_end(ap);

    return tot;
}