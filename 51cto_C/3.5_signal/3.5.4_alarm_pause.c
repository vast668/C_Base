#include <stdio.h>
#include <unistd.h>     //unix stand
#include <signal.h>

void func(int sig)
{

}

void my_sleep(unsigned int seconds)
{
    struct sigaction act = {0};
    act.sa_handler = func;
    sigaction(SIGALRM, &act, NULL);

    alarm(seconds);
    pause();
}

int main()
{
    printf("before my_sleep\n");
    my_sleep(5);
    printf("after my_sleep\n");


    return 0;
}















/*
void func(int sig)
{
    printf("sig = %d\n", sig);
}

int main()
{
    unsigned int ret = -1;
    struct sigaction myact = {0};
    myact.sa_handler = func;
    sigaction(SIGALRM, &myact, NULL);
    // signal(SIGALRM, func);
    // signal(SIGALRM, NULL);  //如果未设置信号SIGALRM的处理函数，那么alarm()默认终止进程

    ret = alarm(3);     //0
    printf("1.st after alarm ret = %d\n", ret);
    sleep(1);

    ret = alarm(5);     //
    printf("2.st after alarm ret = %d\n", ret);


    ret = alarm(9);
    sleep(20);
    printf("3.st after alarm ret = %d\n", ret);

    return 0;
}
*/