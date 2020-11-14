#include <stdio.h>

#define STLEN 24
int main(void)
{
    char words[STLEN];
    puts("Enter a string, please");
    fgets(words, STLEN, stdin);     //是有换行符的 \n
    printf("Your string twice (puts(), then fputs()): \n");
    puts(words);        //puts给字符串添加了一个换行符，puts()将字符串s和末尾换行符写入标准输出。
    fputs(words, stdout); //fputs不会添加换行符
    puts("Enter another string, Please");
    fgets(words, STLEN, stdin);     //加入了结束符  \0，超过了预定长度STLEN
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done");

    return 0;
}

/*
Enter a string, please
jiku wang
Your string twice (puts(), then fputs()): 
jiku wang           
            //这里有换行符
jiku wang
Enter another string, Please
dfdsafasfdasfdsaf dfasfasd
Your string twice (puts(), then fputs()):
dfdsafasfdasf
dfdsafasfdasfDone

*/

/*

第二次输入，输入大小超过限制，所以fgets()只读入了13个字符，
并把dfdsafasfdasf\0存入数组中。

再次提醒：puts()函数会在待输出字符串末尾添加一个换行符

而fputs（）不会这样做
*/