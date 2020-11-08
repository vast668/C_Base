#include <stdio.h>

int main()
{
    #if 1
    int x = 20;
    const int y = 23;
    int * p1 = &x;

    printf("y = %d\n", y);
    printf("&y = %p\n", &y);
    // y = 8;              //error: assignment of read-only variable, y由const修饰，是常量，不可更改
    // printf("y = %d\n", y);
    
    // int * p2 = &y;      //warning! y为常量，不可修改
    const int * p2 = &y;    //no waring, 这样，y的值就不会通过指针改变，const的作用范围是 *p2,  *p2是不能改变的
                            //但是p2是可以指向其他的地址的（存储其他的地址）
    int ** pp2;       
    // *p2 = 88;               //error, can't chenage value of y
    // p1 = p2;            //no security, const variable assign to no const variable, 这里只是报警告，并不会影响程序的执行
    // *p1 = 88;           //这样就会将y的值给修改了
    // printf("y = %d\n", y);

    p2 = p1;        //有效，将非const值赋给const   可以向下传递

    pp2 = &p1;
    printf("x = %d\n", **pp2);
    #endif 
    /*
        二层解引用的指针也是不安全的，如下示例
    */
    const int n = 13;
    const int ** pp222;
    int * p111;
    
    pp222 = &p111;      //非const变量赋值给const变量，c语言编译器只会报警告，不会报错
    *pp222 = &n;      //这里没毛病，n是const，pp2也是常量， 可以赋值。p1指针也就等于了*pp2
    *p111 = 88;       //改写n值    不安全

    printf("n = %d\n", n);      //n = 88, 这样就将n的值改变了

    return 0;
}