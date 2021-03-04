#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char buf[100];

void *func(void * arg)
{
    int fd = -1;
    while(1){
        fd = open("/dev/input/mouse0", O_RDONLY);
        
        memset(buf, 0, sizeof(buf));
        read(fd, buf, 100);
        printf("content of mouse0 is [%s]\n", buf);
    }
}

int main()
{
    pthread_t pt = -1;
    int ret = -1;
    ret = pthread_create(&pt, NULL, func, NULL);
    if (ret != 0){
        printf("pthread_creat faile\n");
    }

    while(1){
        memset(buf, 0, sizeof(buf));
        read(0, buf, 100);
        printf("content of keyboard is [%s]\n", buf);
    }

  
        

    return 0;
}