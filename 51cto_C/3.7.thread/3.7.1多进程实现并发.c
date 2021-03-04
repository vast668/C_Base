#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    pid_t pid = -1;
    int fd = -1;
    char buf[100];
    pid = fork();

    if(pid > 0){
        //parent process, handle keyboard
        while(1){
            memset(buf, 0, sizeof(buf));
            read(0, buf, 100);
            printf("content of keyboard is [%s]\n", buf);
        }

    } else if (pid == 0){
        //child process
        while(1){
            fd = open("/dev/input/mouse0", O_RDONLY);
            if (fd < 0){
			    perror("open:");
			    return -1;
		    }
            memset(buf, 0, sizeof(buf));
            read(fd, buf, 100);
            printf("content of mouse0 is [%s]\n", buf);
        }

    } else {
        perror("fork\n");
        return -1;
    }

    return 0;
}