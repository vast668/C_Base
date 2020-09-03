#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int cal_len(const char * pathname)
{
    int fd = -1;
    // FILE * fp;
    int ret = -1;
    
    fd = open(pathname, O_RDONLY);
    
    if (-1 == fd){
        perror("Error");
        return -1;
    }
    #if 0
    open is system api, return value is int
    if (NULL == fp){
        perror("Error");
        _exit(-1);
    }
    #endif
    // ret = lseek(fd, 0, SEEK_END);

    return ret;

}
int main(int argc, char *argv[])
{
    int fd = -1;
    int ret = -1;

    if (argc != 2){
        printf("Usage: %s filename\n", argv[0]);
        _exit(-1);
    }
    ret = cal_len(argv[1]);
    return 0;
}