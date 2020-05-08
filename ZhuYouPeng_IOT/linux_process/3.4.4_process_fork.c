#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t p1 = -1;
    p1 = fork();        //return twice

    if (p1 == 0)
    {
        //this is child process
        printf("child process, pid = %d\n", getpid());
        printf("hello jiku\n");
        printf("his parent process is %d\n", getppid());
    }

    if (p1 > 0)
    {
        //this is parent process
        printf("parent process, pid = %d\n", getpid());
        printf("hello jiku\n");
        printf("parent's parent process is %d\n", getppid());

    }
    if (p1 < 0)
    {
        //there was error
    }

    return 0;
}

/*
parent process, pid = 1349
hello jiku
parent's parent process is 1130
child process, pid = 1350
hello jiku
his parent process is 1349
*/