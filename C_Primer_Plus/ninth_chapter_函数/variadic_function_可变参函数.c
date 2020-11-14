#include <stdio.h>
#include <stdarg.h>

void  print_ints(int args, ...)
{
    va_list ap;
    va_start(ap, args);
    int i;
    for (i = 0; i < args; i++){
        printf("argument: %d\n", va_arg(ap, int));
    }
    va_end(ap);
}

int main()
{
    print_ints(3, 14, 200, 398);


    return 0;
}

/*

(1)需要包含<stdarg.h>头文件
(2)三个点表示 有很多的参数
(3)va_list ap用来保存传给函数的其他参数
(4)将普通参数传递给va_start，本例中是args，va_start将参数依次赋值给ap
(5)然后用va_arg来读取ap中的内容
*/