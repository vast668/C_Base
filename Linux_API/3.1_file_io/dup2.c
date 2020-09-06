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
	// close(1);       //close stdoutput
	// copy file descriptor
	fd2 = dup2(fd1, 16);
	printf("fd2 = %d.\n", fd2);
	
    while (i){
        write(fd1, "aa", 2);
        sleep(1);
        write(fd2, "bb", 2);
        i--;
    }

	close(fd1);

	return 0;
}

/*
result:
aabbaabbaabbaabbaabbaabbaabbaabbaabbaabb

the file decriptor from dump2 is continue write
接续写

*/