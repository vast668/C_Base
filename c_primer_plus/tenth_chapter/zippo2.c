#include <stdio.h>

int main()
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}   };
    int (*pz)[2];   //[] 的优先级 大于 *，故使用括号，pz先是一个指针，指向的数组中有两个元素    
    // int *pz[2];  //error: assignment to expression with array type
    //pz首先是一个数组，数组有两个元素，两个元素是指针，指向int类型  故不匹配
    pz = zippo;

    printf("&pz      = %p\n", &pz);
    // &pz = 0x7ffecc7cc3a8                 //这里的pz是程序定义的指针，指针的地址和数组的地址不同
    printf("&pz[0]   = %p\n", &pz[0]);    //一维数组的首元素的地址，也是二维数组的地址  = 数组名   
    // &pz = 0x7ffecc7cc3b0

    printf("&pz[0][0] = %p\n", &pz[0][0]);
    // &pz[0][0] = 0x7ffecc7cc3b0        //二维数组的首元素 的地址   等于数组名


    printf("pz    = %p, pz + 1    = %p\n", pz, pz + 1);
    //pz     =   0x7ffecc7cc3b0,     数组名就是数组的地址    等同于   &pz
    //pz + 1 =   0x7ffecc7cc3b8      相差8个字节，因为int占4个字节，pz数组里面有两个int型变量

    printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
    //pz[0]      = 0x7ffecc7cc3b0 
    //pz[0] + 1  = 0x7ffecc7cc3b4    相差4个字节


    printf("*pz   = %p, *pz + 1   = %p\n", *pz, *pz + 1);
    // *pz       = 0x7ffecc7cc3b0
    // *pz + 1   = 0x7ffecc7cc3b4   相差4个字节

    printf("pz[0][0] = %d\n", pz[0][0]);
    //pz[0][0] = 2

    printf("  *pz[0] = %d\n", *pz[0]);
    // *pz[0] = 2
    printf("    **pz = %d\n", **pz);
    // **pz = 2
    // printf("    *pz  = %d\n", *pz);
    printf("    pz[2][1]   = %d\n", pz[2][1]);
    // pz[2][1]   = 3
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz+2) + 1));
    // *(*(pz+2) + 1) = 3
    //解读一下：  
    // （1）首先是pz +2 是二维数组的第三个元素的地址，
    // （2）解引用得到二维数组的第三个元素：一维数组的第一个元素，也是一个地址
    // （3）二维数组的第三个元素中的第一个元素  再 + 1，得到第二个元素
    // （4）解引用得到其值3！！！



    return 0;
}