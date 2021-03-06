#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>


char buf[200] = {0};
sem_t sem;
unsigned int close_falg = 0;

//子线程程序，作用是统计buf中的字符各树并打印
void * func(void * arg)
{
    //子线程首先应该有个循环
    //循环中阻塞在等待主线程激活的时候，子线程被激活后就去取buf中的字符
    //长度，然后打印；完成后再次被阻塞
    sem_wait(&sem);
    while (close_falg == 0){
        printf("length of strings is %ld\n", strlen(buf));
        memset(buf, 0 ,sizeof(buf));
        sem_wait(&sem);
    }
    pthread_exit(NULL);
    printf("pthread termination!!!\n");
}

int main()
{
    int ret = -1;
    pthread_t pt;
    ret = pthread_create(&pt, NULL, func, NULL);
    if (ret != 0){
        printf("pthread create faile\n");
        exit(-1);
    }

    while (scanf("%s", buf)){
        if (!strncmp(buf, "end", 3)){
            printf("process termination\n");
            close_falg = 1;
            sem_post(&sem);
            break;
        }

        //主线程在收到用户收入的字符串，并且确认不是end后
        //就去发信号激活子线程来计数
        //子线程被阻塞，主线程可以激活，这就是线程同步问题
        //信号量就可以用来实现这个线程同步
        printf("content of strings is %s\n", buf);
        sem_post(&sem);
    }
    sem_post(&sem);
    printf("wait recycle pthread\n");

    ret = pthread_join(pt, NULL);
    if (ret != 0){
        printf("pthread_join create faile\n");
        exit(-1);
    }

    printf("process termination!!!\n");
    return 0;
}