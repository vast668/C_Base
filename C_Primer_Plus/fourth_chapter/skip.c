#include <stdio.h>

int main()
{
    int n;
    printf("Please enter three integers:\n");
    scanf("%*d %*d %d", &n);

    printf("The last integer was %d\n", n);

    return 0;
}

/*
Please enter three integers:
2 3 4
The last integer was 4
*/