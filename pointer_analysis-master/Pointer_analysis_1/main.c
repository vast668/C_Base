#include <stdio.h>

int main() {
    int i;
    i = 5;
    printf("i_add = %#X\n", &i);
    printf("i = %#X\n", i);

    i = 4294967295;//int占4B，4*8=32位，2^32 - 1=4294967295
//    数值跟地址无关

    printf("i_add = %#X\n", &i);
    printf("i = %#X\n", i);
    return 0;
}

/*      result:
 i_add = 0X203770DC
i = 0X5
i_add = 0X203770DC
i = 0XFFFFFFFF
 */


//int类型是一个整形，占4个字节，变量i的地址是0X203770DC,变量的地址是不会变的，
//变量的值和地址无关，int只能存放的最大数是4294967295
//变量i的值改变，不会影响i的地址，它还是存放在内存单元0X203770DC中！！！