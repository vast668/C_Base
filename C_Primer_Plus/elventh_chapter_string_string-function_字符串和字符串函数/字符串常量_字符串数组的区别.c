#include <stdio.h>


int main()
{
    char * const_p = "wang_jikuo";
    char p[] = "WANG_JIKUO";

    printf("const_p     = %p\n", const_p);
    printf("&const_p    = %p\n", &const_p);
    printf("        p   = %p\n", p);
    printf("       &p   = %p\n", &p);

    return 0;
}

/*
const_p     = 0x7f05e4f48004
&const_p    = 0x7ffff7ea2b80
        p   = 0x7ffff7ea2b8d
       &p   = 0x7ffff7ea2b8d
解析：
第一个语句const_p指针变量是分配在栈上，而字符串“wang_jikuo”是存储在字符串常量区
故地址相差很多

第二个数组分配在栈上，数组名 == 数组的地址(并没有给数组名分配指针)

====================
嗨翻c语言——这里没有蠢问题
question：
我还是不能理解，为甚数组比那辆不存在存储器中？既然它存在，就应该放在某个地方，不是吗？
answer：
程序在编译期间，会把所有对数组变量的引用替换成数组的地址。也就是说在最后的可执行文件中，

数组变量并不存在。既然数组变量从来不需要指向其他地方，有和没有其实都一样！
-------------------
question：
    当把新数组设为字符串字面值，程序实际上会赋值字符串字面值的内容码？
answer：
    取决于编译器，最后的机器代码极有可能把整个字符串字面值的欸容复制到数组，也有可能根据声明设置每个字符串的值
*/