#include <stdio.h>
#include <stdlib.h>
// #define CNTL_Z '\32'
#define SLEN 81

int main()
{
    char file[SLEN];
    char ch;
    FILE * fp;
    long count, last;

    puts("Enter the name of file to be processed:");
    scanf("%80s", file);
    if ((fp = fopen(file, "rb")) == NULL){
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    for (count = 1L; count <= last; count++){
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch != EOF && ch != '\r')
            putchar(ch);
    }
    putchar('\n');
    fclose(fp);

    return 0;
}