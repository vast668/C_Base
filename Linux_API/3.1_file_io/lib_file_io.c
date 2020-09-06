#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME    "1.txt"

int main()
{
    FILE * fp = NULL;
    size_t len = -1;
    // int array[10] = {1, 2, 3, 4, 5};
    // char * buf = "I love C lanaguage";
    char buf[100] = {0};

    fp = fopen(FILENAME, "r+");
    if (NULL == fp){
        perror("fopen");
        exit(-1);
    }
    printf("fopen success. fp = %p.\n",fp);
    memset(buf, 0, sizeof(buf));
    len = fread(buf, 1, 100, fp);
    printf("buf is : [%s].\n", buf);

#if 0
    // memset(buf, 0, sizeof(buf));
    len = fwrite(buf, 1, 20, fp);

    fclose(fp);
#endif


    return 0;
}




/*
3.1.14.标准IO库介绍
3.1.14.1、标准IO和文件IO有什么区别
(1)看起来使用时都是函数，但是：标准IO是C库函数，而文件IO是linux系统的API
(2)C语言库函数是由API封装而来的。库函数内部也是通过调用API来完成操作的，但是库函数因为多了一层封装，所以比API要更加好用一些。
(3)库函数比API还有一个优势就是：API在不同的操作系统之间是不能通用的，但是C库函数在不同操作系统中几乎是一样的。所以C库函数具有可移植性而API不具有可移植性。
(4)性能上和易用性上看，C库函数一般要好一些。譬如IO，文件IO是不带缓存的，而标准IO是带缓存的，因此标准IO比文件IO性能要更高。

3.1.14.2、常用标准IO函数介绍
(1)常见的标准IO库函数有：fopen、fclose、fwrite、fread、ffulsh、fseek

3.1.14.3、一个简单的标准IO读写文件实例

*/