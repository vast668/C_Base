#include <stdio.h>
#define PAGES 959

int main()
{
    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);
    printf("*%10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);

    return 0;
}

/*
*959*
*959*
*       959*
*959       *        2、10代表输出空间的大小，如果不能容拿要输出的字符，系统使用更宽的字段
*/