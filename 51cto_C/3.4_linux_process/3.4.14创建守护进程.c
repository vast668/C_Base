#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>


void create_deamon(void);

int main()
{
    create_deamon();
    while (1) {
        printf("I am running\n");
        sleep(1);
    }

    return 0;
}

void create_deamon(void)
{
    int cnt = 0, i = 0;
    pid_t pid = -1;
    pid = fork();
    if (pid < 0){
        perror("fork\n");
        exit(-1);
    }
    if (pid > 0){

        printf("child pid = %d\n", pid);
        exit(0);        //父进程退出！
    }
    //设置新的会话
    pid = setsid();
    if (pid < 0){
        perror("setsid");
        exit(-1);
    }
    //将当前进程工作目录修改为根目录
    chdir("/");

    //umask设置为0，确保将来进程有最大的文件描述符
    umask(0);
    
    //关闭所有文件描述符
    //先要获取当前系统中所允许打开的最大文件描述符输目
    cnt = sysconf(_SC_OPEN_MAX);
    for (i = 0; i < cnt; i++){
        close(i);
    }

    open("/dev/null", O_RDWR);
	open("/dev/null", O_RDWR);
	open("/dev/null", O_RDWR);

    return;
}


/*
void create_deamon(void)
{
    pid_t pid = -1;
    pid = fork();
    if (pid < 0){
        perror("fork\n");
        exit(-1);
    }
    if (pid > 0){
        printf("parent's parent pid = %d\n", getppid());
        printf("parent pid = %d\n", getpid());
        printf("child pid = %d\n", pid);
        // printf("parent pid = ")
        exit(0);        //父进程退出！
    }
    sleep(1);
    printf("child pid = %d\n", getpid());
    printf("child's parent pid = %d\n", getppid());
    printf("this is child process\n");


    return;
}
*/