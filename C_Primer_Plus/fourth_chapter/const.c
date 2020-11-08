#include <stdio.h>

int main()
{
    const int a = 100;
    int const b = 200;

    //a = 1;        //error
    //b = 1;        //error         const在哪没关系
    float c = 2.3456;
    float d = 3.4567;
    printf("%.3f b\n", c);
    printf("%5.3f b\n", d);
    return 0;
}