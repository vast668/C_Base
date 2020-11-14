#include <stdio.h>

#define STLEN 10

int main(void)
{
    char words[STLEN];
    int i;

    puts("Enter strings (empty line to quit):");

    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n'){

        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n')
            words[i] = '\0';
        else //如果word[i] == '\0'则执行这部分代码
            while(getchar() != '\n')
                continue;
        puts(words);
    }
    
    
    puts("Done.");

    return 0;
}

/*
此demo解决的问题是：fgets会将换行符写入buffer，if(words[i] == '\n' 语句会将换行符改写成结束符)

从而适配puts()函数！！！
*/

