#include <stdio.h>

#define STLEN 8

int main()
{
    char words[STLEN];
    puts("Enter a string, Please.");
    gets(words);
    printf("Your string twice: \n");
    printf("%s\n", words);
    puts(words);
    puts("Done");


    return 0;
}