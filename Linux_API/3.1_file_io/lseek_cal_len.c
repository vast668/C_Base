#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int cal_len(const char * patchname)
{
    int fd = -1;
    int ret = -1;

    fd = open(patchname, O_RDONLY);
    if (-1 == fd){
        perror("Error");
        return -1;
    }

    ret = lseek(fd, 0, SEEK_END);       //located the EOF, and EOF offset 1 byte!!!

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
    printf("len of file is %d bytes\n", cal_len(argv[1]));

    return 0;
}




/*
3.1.8.lseek详解

3.1.8.1、lseek函数介绍

(1)文件指针：当我们要对一个文件进行读写时，

一定需要先打开这个文件，所以我们读写的所有文件都是动态文件。

动态文件在内存中的形态就是文件流的形式。


(2)文件流很长，里面有很多个字节。

那我们当前正在操作的是哪个位置？

GUI模式下的软件用光标来标识这个当前正在操作的位置，这是给人看的。

graphical user interface		图形  用户界面
---------------------------------
(3)在动态文件中，我们会通过文件指针来表征这个正在操作的位置。

所谓文件指针，就是我们文件管理表这个结构体里面的一个指针。

所以文件指针其实是vnode中的一个元素。

这个指针表示当前我们正在操作文件流的哪个位置。

这个指针不能被直接访问，linux系统用lseek函数来访问这个文件指针。


(4)当我们打开一个空文件时，默认情况下文件指针指向文件流的开始。

所以这时候去write时写入就是从文件开头开始的。

write和read函数本身自带移动文件指针的功能，所以当我write了n个字节后，

文件指针会自动向后移动n位。

如果需要人为的随意更改文件指针，那就只能通过lseek函数了


(5)read和write函数都是从当前文件指针处开始操作的，

所以当我们用lseek显式的将文件指针移动后，

那么再去read/write时就是从移动过后的位置开始的。


(6)回顾前面一节中我们从空文件，先write写了12字节，

然后read时是空的（但是此时我们打开文件后发现12字节确实写进来了）。

===================================

3.1.8.2、用lseek计算文件长度

(1)linux中并没有一个函数可以直接返回一个文件的长度。

但是我们做项目时经常会需要知道一个文件的长度，怎么办？

自己利用lseek来写一个函数得到文件长度即可。


3.1.8.3、用lseek构建空洞文件

(1)空洞文件就是这个文件中有一段是空的。

(2)普通文件中间是不能有空的，因为我们write时文件指针是依次从前到后去移动的，

不可能绕过前面直接到后面。


(3)我们打开一个文件后，用lseek往后跳过一段，再write写入一段，就会构成一个空洞文件。


(4)空洞文件方法对多线程共同操作文件是及其有用的。

有时候我们创建一个很大的文件，如果从头开始依次构建时间很长。

有一种思路就是将文件分为多段，然后多线程来操作每个线程负责其中一段的写入。

======================================

*/