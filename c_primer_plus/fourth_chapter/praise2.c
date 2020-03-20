#include <stdio.h>
#include <string.h>

#define PRAISE "You are an extraordinary being."

int main()
{
    char name[40];
    int i;
    printf("What's your name?");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    for(i = 0; i < 40; i++){
        printf("%d\n", name[i]);
    }
    printf("Your name of %zd letters occupies %zd memory cells.\n", strlen(name), sizeof name);

    printf("The pharse of praise has %zd letters ", strlen(PRAISE));

    printf("and occpies %zd memory cells.\n", sizeof PRAISE);


    return 0;
}