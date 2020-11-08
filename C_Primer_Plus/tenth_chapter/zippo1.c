#include <stdio.h>


int main()
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    
    printf("&zippo      = %p\n", &zippo);       //虽是指针，但是是数组名，所以   取指针的地址 = 数组名  
    // &zippo = 0x7ffe351780c0
    printf("&zippo[0]   = %p\n", &zippo[0]);    //一维数组的首元素的地址，也是二维数组的地址  = 数组名   
    // &zippo = 0x7ffe351780c0

    printf("&zippo[0][0] = %p\n", &zippo[0][0]);
    // &zippo[0][0] = 0x7ffe351780c0        //二维数组的首元素 的地址   等于数组名


    printf("zippo    = %p, zippo + 1    = %p\n", zippo, zippo + 1);
    //zippo     =   0x7ffe351780c0,     数组名就是数组的地址    等同于   &zippo
    //zippo + 1 =   0x7ffe351780c8      相差8个字节，因为int占4个字节，zippo数组里面有两个int型变量

    printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);
    //zippo[0]      = 0x7ffe351780c0 
    //zippo[0] + 1  = 0x7ffe351780c4    相差4个字节


    printf("*zippo   = %p, *zippo + 1   = %p\n", *zippo, *zippo + 1);
    // *zippo       = 0x7ffe351780c0
    // *zippo + 1   = 0x7ffe351780c4
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    //zippo[0][0] = 2

    printf("  *zippo[0] = %d\n", *zippo[0]);
    // *zippo[0] = 2
    printf("    **zippo = %d\n", **zippo);
    // **zippo = 2
    // printf("    *zippo  = %d\n", *zippo);
    printf("    zippo[2][1]   = %d\n", zippo[2][1]);
    // zippo[2][1]   = 3
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo+2) + 1));
    // *(*(zippo+2) + 1) = 3
    //解读一下：  
    // （1）首先是zippo +2 是二维数组的第三个元素的地址，
    // （2）解引用得到二维数组的第三个元素：一维数组的第一个元素，也是一个地址
    // （3）二维数组的第三个元素中的第一个元素  再 + 1，得到第二个元素
    // （4）解引用得到其值3！！！

    
    return 0;
}