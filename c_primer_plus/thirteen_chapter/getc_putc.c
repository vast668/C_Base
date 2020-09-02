#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char ch_1;
    char ch_2;

    FILE *fp = fopen(argv[1], "r");
    ch_1 = getchar();
    ch_2 = getc(fp);

    // printf("ch_1 is %c\n", ch_1);
    // printf("ch_2 is %c\n", ch_2);

    putchar(ch_1);
    putc(ch_2, stdout);

    return 0;
}