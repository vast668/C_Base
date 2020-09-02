#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch;
    FILE * fp;
    fp = fopen("wacky.txt", "r");
    #if 0
    ch = getc(fp);
    while (ch != EOF){
        putchar(ch);    //handle input
        ch = getc(fp);      //handle output
    }
    #endif

    while ((ch = getc(fp)) != EOF){
        putchar(ch);        //handle input
    }
    




    return 0;
}