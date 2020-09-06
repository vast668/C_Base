#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = -1;
    char read_buf[100] = {0};
    char write_buf[20] = "I love linux";
    int ret = -1;

    fd = open("jikuo_wang.txt", O_RDWR | O_CREAT);
    if (-1 == fd){
        perror("open file failure");
        _exit(-1);
    } else {
        printf("open file success, fd = %d\n", fd);
    }
    // ret = lseek(fd, 10, SEEK_SET);
    // printf("lseek, ret = %d.\n", ret);

    ret = write(fd, write_buf, strlen(write_buf));
    if (-1 == ret){
        perror("write failure");
        _exit(-1);
    } else {
        printf("write success, %d bytes were writing\n", ret);
    }
    ret = lseek(fd, 0, SEEK_SET);       //移动至文件开始位置
    printf("lseek, ret = %d.\n", ret);
    ret = read(fd, read_buf, 15);
    if (ret < 0){
        perror("read failure");
        _exit(-1);
    } else {
        printf("read success, %d bytes were reading\n", ret);
        printf("the file's content is [%s].\n", read_buf);
    }
    close(fd);


    _exit(0);
}




/*
3.1.4.open函数的flag详解1

3.1.4.1、读写权限：O_RDONLY O_WRONLY O_RDWR


(1)linux中文件有读写权限，我们在open打开文件时也可以附带一定的权限说明

（譬如

O_RDONLY就表示以只读方式打开，

O_WRONLY表示以只写方式打开，

O_RDWR表示以可读可写方式打开）

---------------------------------

(2)当我们附带了权限后，打开的文件就只能按照这种权限来操作。

3.1.4.2、打开存在并有内容的文件时：O_APPEND、O_TRUNC

(1)思考一个问题：当我们打开一个已经存在并且内部有内容的文件时会怎么样？

可能结果1：新内容会替代原来的内容（原来的内容就不见了，丢了）
可能结果2：新内容添加在前面，原来的内容继续在后面
可能结果3：新内容附加在后面，原来的内容还在前面
可能结果4：不读不写的时候，原来的文件中的内容保持不变

------------------------------------
(2)O_TRUNC属性去打开文件时，如果这个文件中本来是有内容的，

则原来的内容会被丢弃。这就对应上面的结果1


(3)O_APPEND属性去打开文件时，如果这个文件中本来是有内容的，

则新写入的内容会接续到原来内容的后面，对应结果3


(4)默认不使用O_APPEND和O_TRUNC属性时就是结果4


(5)如果O_APPEND和O_TRUNC同时出现会怎么样？

-------------------------------------------------------

3.1.4.3、exit、_exit、_Exit退出进程

(1)当我们程序在前面步骤操作失败导致后面的操作都没有可能进行下去时，

应该在前面的错误监测中结束整个程序，不应该继续让程序运行下去了。

(2)我们如何退出程序？

第一种；在main用return，一般原则是程序正常终止return 0，如果程序异常终止则return -1。

第一种：正式终止进程（程序）应该使用exit或者_exit或者_Exit之一。

*/