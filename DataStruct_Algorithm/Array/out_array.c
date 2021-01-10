#include <stdio.h>

int i_static = 0;
int main(int argc, char *argv[])
{
    int i = 0;
    int arr[3] = {0};
    for (; i <= 3; i++){
        arr[i] = 0;
        printf("hello world\n");
    }
    printf("&i      is %p\n", &i);          //0x7fffee4f5368
    printf("arr[2]  is %p\n", &arr[2]);     //0x7fffee4f5374
    printf("arr[1]  is %p\n", &arr[1]);     //0x7fffee4f5370
    printf("arr[0]  is %p\n", &arr[0]);     //0x7fffee4f536c  
    printf("&i_static      is %p\n", &i_static);

    return 0;
}

/*
hello world
hello world
hello world
hello world
&i      is 0x7fffee4f5368
arr[2]  is 0x7fffee4f5374
arr[1]  is 0x7fffee4f5370
arr[0]  is 0x7fffee4f536c
*** stack smashing detected ***: terminated
Aborted (core dumped)

编译时加上  -fno-stack-protector  选项，关闭堆栈保护功能
就会导致无线循环打印hello world

why 无限循环？
首先栈是向下增长的, 数组是从高地址往低地址生长的
所以在栈中的情况是 i srr[2], arr[1], arr[0]

由于i和数组中的元素相同，数组是从0开始的，for循环多了一次

故arr[3]其实是i的值，在第四次（arr[3]）的时候，将i的值修改为1

这样循环的判断条件就一直 <= 3 ;故无限打印
==================
arr[3] 数组越界占用了i的内存空间
*/