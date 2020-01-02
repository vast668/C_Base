#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t p1 = -1, p2 = -1;
    printf("hello\n");
    p1 = getpid();
    printf("children id p1 = %d\n", p1);
    p2 = getppid();
    printf("parent id p2 = %d\n", p2);

    return 0;
}