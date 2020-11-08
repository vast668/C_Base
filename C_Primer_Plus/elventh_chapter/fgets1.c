#include <stdio.h>

#define STLEN 14
int main(void)
{
    char words[STLEN];
    puts("Enter a string, please");
    fgets(words, STLEN, stdin);     //是有换行符的 \n
    printf("Your string twice (puts(), then fputs()): \n");
    puts(words);
    fputs(words, stdout);       
    puts("Enter another string, Please");
    fgets(words, STLEN, stdin);     //加入了结束符  \0
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done");

    return 0;
}

/*
./a.out 
Enter a string, please
jiku wang
Your string twice (puts(), then fputs()): 
jiku wang           

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