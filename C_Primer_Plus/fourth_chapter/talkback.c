#include <stdio.h>
#include <string.h>
#define DENSITY 62.4        //密度

int main()
{
    float weight, volume;
    int size, letters, i;
    char name[10];      //name是一个可容纳40个字符的数组
    memset(name, 1, 100);
    printf("Hi What's your first name?\n");
    scanf("%s", &name);
    
    for(i = 0; i < 19; i++){
        printf("%d\n", name[i]);
    }

    
    printf("%s, What's your weight in pounds?\n", name);
    scanf("%f", &weight);
    size = sizeof(name);
    letters = strlen(name);
    volume = weight / DENSITY;
    printf("Well, %s, your volume is %2.2f cubic feet. \n", name, volume);
    printf("Also, your first name has %d letters, \n", letters);
    printf("and we have %d bytes to store it.\n", size);

    return 0;
}