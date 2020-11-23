#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char * one_p = NULL;
    char ** double_p = NULL;
    
    double_p = &one_p;      //important
    
    printf("double_p = %p\n", double_p);
    printf("&double_p = %p\n", &double_p);
    printf("*double_p = %p\n", *double_p);  //(如果没有11line)会发生段错误，原因如下：

    /*
    douple_p是二重指针，初始值为NULL，
    而*double_p类型上为一重指针，*为取地址运算符，
    现在double_p的值为NULL，* NULL,是取不到地址的，故发生段错误
    解决方法是:先定义一个一重指针，
    一重指针变量的地址赋给二重指针，这样保证double_p是有值的
    *double_p可以获取到地址，即使获取到的地址中的值为NULL
    */
    *double_p = malloc(11);
    memset(*double_p, 0, 11);
    strcpy(*double_p, "wang_jikuo");
    // printf("%s\n", one_p);
    // printf("%c\n", *one_p);
    for (int i = 0; i < 11; i++)
    {
        printf("i = %d %c\n", i, *(one_p+i));
    }

    return 0;
}




#if 0
char *p = "wang_jikuo";
    char **p2 = &p;

    
    printf("   p     = %p\n", p);
    printf("  &p     = %p\n", &p);
    printf("  p2     = %p\n", p2);
    printf(" &p2     = %p\n", &p2);
    printf(" *p2     = %p\n", *p2);
    printf("**p2     = %c\n", **p2);
    printf("*(*p2+1) = %c\n", *(*p2+1));
    // printf(" p2 = %p\n", p2);
    // printf("**p = %p\n", **p);

#endif