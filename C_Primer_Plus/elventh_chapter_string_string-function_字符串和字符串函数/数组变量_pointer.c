#include <stdio.h>

int main(void)
{
    char *p_s = NULL, *p_t = NULL;
    char s[] = "how big is it?";
    char *t = s;

    printf("s = %ld\n", sizeof(s));     //是字符串的大小   15
    printf("t = %ld\n", sizeof(t));     //是字符串指针的大小   8

    printf(" s = %p\n", s);             //数组的地址
    printf("&s = %p\n", &s);            //也是数组的地址
    
    printf(" t = %p\n", t);             //指针t指向s数组，故指针t的值为数组的地址
    printf("&t = %p\n", &t);            //指针t的地址，指针t为一个指针变量，在内存中有单独的地方存储


    return 0;
}

/*
demo讨论的是数组名和指针变量的区别
s = 15
t = 8
 s = 0x7ffff7c99cc9
&s = 0x7ffff7c99cc9
 t = 0x7ffff7c99cc9
&t = 0x7ffff7c99cb0

*/