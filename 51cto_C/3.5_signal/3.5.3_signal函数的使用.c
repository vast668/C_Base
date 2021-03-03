#include <stdio.h>
#include <signal.h>


void func(int sig)
{
    printf("func for signal: %d\n", sig);
}

int main()
{
    // signal(SIGINT, SIG_IGN);
    // signal(SIGINT, SIG_DFL);
    signal(SIGINT, func);       //捕获到SIFINT之后，调用func函数
    printf("before signal\n");
    while (1);
    printf("after signal\n");

    return 0;
}