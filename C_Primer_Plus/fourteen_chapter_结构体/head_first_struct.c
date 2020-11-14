#include <stdio.h>

typedef struct fish {
    const char * name;
    const char * species;
    int teeth;
    int age;
}Fish;

int main()
{
    Fish snappy = {
        "snappy",
        "piranha",
        69,
        4,
    };
    // printf("%p\n", snappy);     //这是错误的，结构体的名字是void *类型的
    printf("&snappy         =%p\n", &snappy);
    printf(" snappy.name    =%p\n", snappy.name);   //字符串常量存储在静态存储区
    printf("&snappy.name    =%p\n", &snappy.name);  //这是结构体中name指针变量的地址，等于结构体的地址


    return 0;
}

/*
为什么结构体的名称不是指针
https://stackoverflow.com/questions/63503142/why-struct-name-is-not-a-pointer-in-c
没有得到官方正确的回答，但得到以下几点：
（1）c语言之父依据b语言创建的C语言， 他想保留B语言数组的语义，但不想保留指向数组第一个元素的指针，
所以去掉了这个指针，用数组名代替了
（2）数组名是指针，用它做的事情很多，比如指针++就能得到下一个元素，而结构体就不行，挤乳沟提中的成员类型不一样
（3）数组名不能互相赋值，结构体可以！（是copy的过程）

*/