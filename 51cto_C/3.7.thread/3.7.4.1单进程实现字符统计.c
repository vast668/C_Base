#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char buf[200] = {0};

    printf("Please enter strings\n");
    while(scanf("%s", buf)){
        if(!strncmp(buf, "end", 3)){
            printf("process termination!\n");
            exit(0);
        }
        printf("length of string is %ld\n", strlen(buf));
        memset(buf, 0, sizeof(buf));
    }



    return 0;
}