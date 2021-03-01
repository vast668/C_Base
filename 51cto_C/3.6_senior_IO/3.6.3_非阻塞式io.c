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
    int flag = 0;
    memset(buf, 0, sizeof(buf));

    //读取键盘，键盘就是标准输入stdin   0 
    memset(buf, 0, sizeof(buf));

    // 把0号文件描述符（stdin）变成非阻塞式的
	flag = fcntl(0, F_GETFL);		// 先获取原来的flag
	flag |= O_NONBLOCK;				// 添加非阻塞属性
	fcntl(0, F_SETFL, flag);		// 更新flag
	// 这3步之后，0就变成了非阻塞式的了
    while (1){
        read(0, buf, 100);
        cnt = strlen(buf);
        buf[cnt - 1] = 0;
        printf("content of keyboard is [%s]\n", buf);
    }
    


    return 0;
}


/*

 //读取标准输入的内容（其实是要读取鼠标的内容）,鼠标的文件没有找到
    fd = open("/dev/stdin", O_RDONLY | O_NONBLOCK);
    if (fd < 0){
        perror("open");
        return -1;
    }

    printf("before read\n");
    read(fd, buf, 200);
    cnt = strlen(buf);
    buf[cnt - 1] = 0;
    printf("read content is [%s]\n", buf);
*/
