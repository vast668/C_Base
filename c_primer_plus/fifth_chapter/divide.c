#include <stdio.h>

int main()
{

    int a = 7;
    float b = 0;
    double c = 3.4;
    printf("sizeof(a) = %d\n", sizeof(a));
    printf("sizeof(b) = %d\n", sizeof(b));
    printf("sizeof(c) = %d\n", sizeof(c));

    printf("%d\n", a);
    
    printf("integer division : 5/4 is %d\n", 5 / 4);
    printf("integer division : 6/3 is %d\n", 6 / 3);
    printf("integer division : 7/4 is %d\n", 7 / 4);
    printf("floating division : 7./4 is %1.2f\n", 7. / 4);
    printf("max division : 7./4 is %1.2f\n", 7. / 4);
    

    return 0;
}
/*
sizeof(a) = 4
sizeof(b) = 4
sizeof(c) = 8
7
integer division : 5/4 is 1         截断整数和小数部分
integer division : 6/3 is 2
integer division : 7/4 is 1
floating division : 7./4 is 1.75
max division : 7./4 is 1.75

混合类型：浮点值除以整数型。
计算机不会用浮点数除以整数，会先将整数转换成浮点数，再进行运算

*/