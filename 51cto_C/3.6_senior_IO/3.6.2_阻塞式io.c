#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = -1;
    char buf[200];
    unsigned long cnt = 0;
    memset(buf, 0, sizeof(buf));

    fd = open("/dev/stdin", O_RDONLY);
    if (fd < 0){
        perror("open");
        return -1;
    }

    printf("before read\n");
    read(fd, buf, 200);
    cnt = strlen(buf);
    buf[cnt - 1] = 0;
    printf("read content is [%s]\n", buf);


    return 0;
}

/*
int main()
{

    //读取键盘，键盘就是标准输入stdin   0 
    char buf[100];
    unsigned long cnt = 0;
    memset(buf, 0, sizeof(buf));

    printf("before read\n");
    read(0, buf, 100);
    cnt = strlen(buf);
    printf("the keyboard content size is %lu\n", cnt);
    buf[cnt - 1] = 0;
    printf("content of keyboard is [%s]\n", buf);

    return 0;
}
*/