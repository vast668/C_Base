#include <stdio.h>
#include <string.h>

#define WORDS "beats"
#define SIZE 40


int main(void)
{
    const char * orig = WORDS;
    char copy[SIZE] = "Be the best that you are";
    char * ps;
    puts(orig);
    puts(copy);
    ps = strncpy(copy+7, orig, 5);      //使用strncpy拷贝一定数量的字符串，去掉空字符
    puts(copy);
    puts(ps);


    return 0;
}


#if 0
int main(void)
{
    const char * orig = WORDS;
    char copy[SIZE] = "Be the best that you are";
    char * ps;
    puts(orig);
    puts(copy);
    ps = strcpy(copy+7, orig);
    puts(copy);
    puts(ps);


    return 0;
}

/*
./a.out 
beats
Be the best that you are
Be the beats                //将空字符也拷贝进来了
beats

*/
#endif