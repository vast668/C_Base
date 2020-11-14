#include <stdio.h>

int main()
{
    char integer;
    int status;

    status = scanf("%d", &integer);         //depend on format %d %c %f
    printf("%d\n", status);
    // status = scanf("%*s");
    // printf("%d\n", status);

    return 0;
}