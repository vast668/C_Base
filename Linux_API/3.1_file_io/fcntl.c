#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define FILENAME	"1.txt"


int main(void)
{
	int fd1 = -1, fd2 = -1;
    int i = 10;
	fd1 = open(FILENAME, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0)
	{
		perror("open");
		return -1;
	}
	printf("fd1 = %d.\n", fd1);
	
	close(1);        //close 1, stdout is repaced to 1.txt
	
	fd2 = fcntl(fd1, F_DUPFD, 0);
	printf("fd2 = %d.\n", fd2);

	while (i)
	{
		write(fd1, "aa", 2);
		sleep(1);
	    write(fd2, "bb", 2);
        i--;
	}


	
	close(fd1);
	return -1;
}

/*
关闭 1，标准输出就被换成了1.txt

输出的内容回被放进1.txt中
fd2 = 1.
aabbaabbaabbaabbaabbaabbaabbaabbaabbaabb

3.1.13.fcntl函数介绍
3.1.13.1、fcntl的原型和作用
(1)fcntl函数是一个多功能文件管理的工具箱，接收2个参数+1个变参。第一个参数是fd表示要操作哪个文件，第二个参数是cmd表示要进行哪个命令操作。变参是用来传递参数的，要配合cmd来使用。
(2)cmd的样子类似于F_XXX，不同的cmd具有不同的功能。学习时没必要去把所有的cmd的含义都弄清楚（也记不住），只需要弄明白一个作为案例，搞清楚它怎么看怎么用就行了，其他的是类似的。其他的当我们在使用中碰到了一个fcntl的不认识的cmd时再去查man手册即可。

3.1.13.2、fcntl的常用cmd
(1)F_DUPFD这个cmd的作用是复制文件描述符（作用类似于dup和dup2），这个命令的功能是从可用的fd数字列表中找一个比arg大或者和arg一样大的数字作为oldfd的一个复制的fd，和dup2有点像但是不同。dup2返回的就是我们指定的那个newfd否则就会出错，但是F_DUPFD命令返回的是>=arg的最小的那一个数字。

3.1.13.3、使用fcntl模拟dup2






*/