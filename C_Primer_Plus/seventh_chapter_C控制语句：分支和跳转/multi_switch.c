#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    int mark = 0;

    // printf("%d\n", (a|b|c));
    switch (c)
    {
    case (1 || 2 || 3):
        printf("ok\n");
        break;
    
    default:
        printf("no\n");
        break;
    }




    return 0;
}