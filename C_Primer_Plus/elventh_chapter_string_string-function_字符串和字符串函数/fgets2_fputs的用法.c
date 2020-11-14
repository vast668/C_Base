#include <stdio.h>

#define STLEN 10

int main(void)
{
    char words[STLEN];

    puts("Enter a string, please");

    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')      
        fputs(words, stdout);
    puts("Done.");

    return 0;
}
//第一个字符不是换行符 为真，执行fputs的语句
/*
Enter a string, please
By the way, the gets() funtion also returns a null pointer if it encounters end-of-file.
By the way, the gets() funtion also returns a null pointer if it encounters end-of-file.

                //空行输入，结束
Done.
分析：
    STLEN为10，fgets()会一次性读取10 - 1个字符，所以开始只读入了 by the wa, 
    并存储为by the wa\0,接着fputs并不会打印结束符\0,循环继续

    直到遇到换行符，fputs会打印换行符

*/