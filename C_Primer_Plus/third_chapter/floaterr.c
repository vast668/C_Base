#include <stdio.h>

int main()
{
    float a, b;
    b = 2.0e7 + 1.0;
    a = b - 2.0e7;
    printf("%f\n", a);

    int cost = 12.99;
    float pi = 3.141592663;
    printf("%d\n", cost);       //12        小数点后面的直接截掉

    printf("%f\n", pi);         //3.141593      保留6位有效数字，四舍五入
    return 0;
}