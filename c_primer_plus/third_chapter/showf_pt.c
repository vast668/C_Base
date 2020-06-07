#include <stdio.h>

int main()
{
    float aboat = 32000.0;
    double abet = 2.14e9;       //这里的e 和  E  都是一样的效果
    long double dip = 5.32e-5;

    printf("%f can be wrriten %e\n", aboat, aboat);

    printf("And it's %a in hexadcimal, power of 2 notation\n", aboat);
    printf("%f can be written %e\n", abet, abet);
    printf("%Lf can be written %Le \n", dip, dip);

    return 0;
}

/*
32000.000000 can be wrriten 3.200000e+04
And it's 0x1.f4p+14 in hexadcimal, power of 2 notation
2140000000.000000 can be written 2.140000e+09
0.000053 can be written 5.320000e-05
*/