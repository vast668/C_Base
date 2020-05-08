#include <stdio.h>

int main() {
    int i;
    i = 5;
    printf("i = %#X\n", i);//输出i的16进制 值，（在内存中都是以16进制来表示一个数的值的）
    printf("i_add = %#X\n", &i);//输出变量i的16进制地址值
    printf("**********************\n");
    int *p;//定义一个叫p的地址变量，它的类型是int *类型
    p = &i;//将i的地址值赋给p，注意不能写成&i = p
    //error； &i = p lvalue required as left operand of assignment
    //左值作为赋值的左操作数

    printf("p = %#X\n", p);//输出地址变量p的值，应该和 &i 的值一样
    printf("*p = %#X\n", *p);//输出*p的值，应该和i的值一样
    printf("**********************\n");

    *p = 10;    //等价于   analysis_1的     i = 10;
    printf("*p = %#X\n", *p);//*p应该是变了，变成*p = 0XA（10），
    printf("p = %#X\n", p);
    printf("&i = %#X\n", &i);
    printf("i = %#X\n", i);
    printf("**********************\n");
    return 0;
}
/*result:
 *
 * i = 0X5
i_add = 0XFADF104
**********************
p = 0XFADF104
*p = 0X5
**********************
*p = 0XA
p = 0XFADF104
&i = 0XFADF104
i = 0XA
**********************
 *
 * */


/*这就说明了一点：将变量i的地址存放于地址变量p中，
 *          *p就是i,i就是*p； *p改变，i也就改变；  i改变*p也就改变
 * 指针p指向了i，它存放着i的地址；*p改变，它所指向的目标的值也要改变。
 *
 * */