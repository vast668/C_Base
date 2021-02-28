#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = -1;
    pid_t ret = -1;
    int status = -1;
    pid = fork();

    if (pid > 0){
        //parent process
        printf("parent\n");
        ret = wait(&status);
        printf("child process has been collected, pid = %d.\n", ret);
    }else if (pid == 0){
        //child process
        printf("this is child process\n");
        printf("child pid is %d\n", getpid());
    }else{
        perror("fork");
        exit(-1);
    }


    return 0;
}

/*

wait系统调用是阻塞式的，父进程执行到wait时，就会阻塞，知道子进程的信号传过来

*/