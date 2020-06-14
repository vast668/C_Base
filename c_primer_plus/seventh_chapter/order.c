#include <stdio.h>


int main()
{
    //type string
    char c;
    char d;
    c = '\n';
    printf("line break is %d\n", c);
    d = ' ';
    printf("line break is %d\n", d);



    #if 0
    while ((c = getchar()) != ' ' && c != '\n'){
        printf("no space or line-break\n");
        return 0;
    }
    printf("space or line-break\n");
    #endif


    return 0;
}