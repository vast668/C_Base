#include <stdio.h>


int main()
{
    int ret = 0;
    char word[10];
    ret = scanf("%9s", word);

    printf("%s\n", word);
    printf("%d\n", ret);


    return 0;
}