#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd = -1;
    pid_t pid = -1;

    pid = fork();
    if (pid > 0){
        //this is parent process
        printf("parent\n");
        // fd = open("1.txt", O_RDWR);
        fd = open("1.txt", O_RDWR | O_APPEND);
        if (fd < 0){
            perror("open");
            return -1;
        }
        write(fd, "hello", 5);
        sleep(1);
    } else if (pid == 0){
        //this is child process
        printf("child\n");
        // fd = open("1.txt", O_RDWR);
        fd = open("1.txt", O_RDWR | O_APPEND);
        if (fd < 0){
            perror("open");
            return -1;
        }
        write(fd, "world", 5);
        sleep(1);
    }else{
        perror("fork\n");
        exit(-1);
    }
    close(fd);      



    return 0;
}






