#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd1 = 1, fd2 = -1;
    char read_buf[100] = {0};
    char writebuf[20] = "I love linux";
    int ret = -1;
    int i = 10;
    //open file
    fd1 = open("jikuo_wang.txt", O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0666);
    fd2 = open("jikuo_wang.txt", O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0666);

    if ((-1 == fd1 ) || (-1 == fd2)){
        perror("Open file error");
        _exit(-1);
    }
    while (i)
    {
        //write file
        ret = write(fd1, "ab", 2);
        if (-1 == ret){
            perror("write failure");
            _exit(-1);
        }

        ret = write(fd2, "cd", 2);
        if (-1 == ret){
            perror("write failure");
            _exit(-1);
        }
        sleep(1);
        i--;
    }

    close(fd1);
	close(fd2);

    _exit(0);

}


