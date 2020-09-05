#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd = -1;        //file describe
    char buf[100] = {0};
    char writebuf[20] = "I am jiku_wang";
    int ret = -1;


    //first step: open files
    fd = open("b.txt", O_RDWR | O_APPEND | O_TRUNC);
    if(-1 == fd){
        printf("file opening error!\n");
        _exit(-1);
    } else {
        printf("file opening sucessful!\n");
    }
    // second step: write or read files
    // write files
    ret = write(fd, writebuf, strlen(writebuf));
    if (ret < 0){
        printf("write error!\n");
        _exit(-1);
    } else {
        printf("write successful, write %d characters\n", ret);
    }
    
    //read files
    ret = read(fd, buf, 5);
    if (ret < 0){
        printf("read error!\n");
    } else {
        printf("read %d Bytes\n", ret);
        printf("The content of the file is [%s]\n", buf);
    }

}