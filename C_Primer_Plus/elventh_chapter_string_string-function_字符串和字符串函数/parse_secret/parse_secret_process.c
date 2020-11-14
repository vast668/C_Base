#include <stdio.h>

int main(void)
{
    char word[10];
    int i = 0;
    while(scanf("%9s", word) == 1){
        printf("%s\n", word);
        i = i + 1;
        #if 0 
        if(i % 2){
            fprintf(stdout, "%s\n", word);
        }else{
            fprintf(stderr, "%s\n", word);
        }
        #endif
    }

    return 0;
}