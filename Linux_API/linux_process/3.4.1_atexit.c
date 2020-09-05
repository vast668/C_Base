#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
       

void func1(void)
{

    printf("this is func1\n");
}

void func2(void)
{

    printf("this is func2\n");
}

int main()
{
    printf("hello world!\n");

    atexit(func1);      //先执行func2，再执行func1，像栈的原理，先进后出压栈，
    atexit(func2);



    // return 0;
    // exit(0);
    _exit(0);
}











