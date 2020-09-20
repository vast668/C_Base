#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

int main(void)
{
    int n;
    atexit(sign_off);

    puts("Enter an integer:");
    if (scanf("%d", &n) != 1)
    {
        puts("That's no integer!");
        atexit(too_bad);
        printf("EXIT_FAILURE = %d\n", EXIT_FAILURE);
        exit(EXIT_FAILURE);
    }

    printf("%d is %s.\n", n, (n % 2 == 0) ? "even" : "odd");



    return 0;
}

void sign_off(void)
{
    puts("Thus terminates another magnificent program from");
    puts("SeeSaw SoftWare");
}
void too_bad(void)
{
    puts("SeeSaw Softweare extends its heartfelt condolences");
    puts("to your upon the failure of your program.");
}


/*
exit函数运行时首先会执行由atexit()函数登记的函数，然后会做一些自身的清理工作，同时刷新所有输出流、关闭所有打开的流并且关闭通过标准I/O函数tmpfile()创建的临时文件。
exit()函数用于在程序运行的过程中随时结束程序，exit的参数state是返回给操作系统,返回0表示程序正常结束，非0表示程序非正常结束。
atexit函数：
atexit函数是一个特殊的函数，它是在正常程序退出时调用的函数，我们把他叫为登记函数
（函数原型：int atexit (void (*)(void))

=======================
jikuo-understand:

exit 会终止程序，在终止程序之前，exit函数回去调用 atexit()注册的函数，

而atexit()不会终止程序，但会在程序正常结束之前调用自己注册的函数


*/