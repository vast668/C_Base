#include <stdio.h>
#include <string.h>

#define LISTSIZE 6

int main(void)
{
    const char * list[LISTSIZE] = {
        "astronomy", "astounding",
        "astronodfsssmy", "astoundindfdg",
        "astrosdfnomy", "astoundiddng",
    };

    int count = 0;
    int i;

    #if 0
    printf("%c\n", list[0][1]);
    list[0][1] = 'L';       //即使没有const，也不能修改，因为字符串是字面量，保存在数据区
    printf("%c\n", list[0][1]);
    #endif
    for (i = 0; i < LISTSIZE; i++)
        if (strncmp(list[i], "astro", 5) == 0){
            printf("Found: %s\n", list[i]);
            count++;
        }
    
    printf("The list contained %d words beginning" " with astro.\n", count);

    return 0;
}