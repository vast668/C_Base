#include <stdio.h>

int main()
{
    int age;
    float assets;
    char prt[30];

    printf("Enter your age, assets, and favorite pet.\n");

    scanf("%d, %f", &age, &assets);
    // scanf("%s", prt);
    printf("%d $%.2f %s\n", age, assets, prt);



    return 0;
}

/*
9
8.3
dsjfksljfdl
9 $8.30 dsjfksljfdl
*/