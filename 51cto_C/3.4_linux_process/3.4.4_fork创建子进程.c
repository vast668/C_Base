#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = -1;

    pid = fork();

    if (pid > 0){
        //parent process
    }else if (pid == 0){
        //child process
    }else{
        perror("fork");
        exit(-1);
    }
    printf("hello world, pid = %d\n", getpid());
    printf("hello world, ppid = %d\n", getppid());


    return 0;
}