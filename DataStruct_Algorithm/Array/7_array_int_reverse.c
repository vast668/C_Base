#include <stdio.h>

int reverse(int a);

int main()
{
    int a = 1534236412;
    int ret = 0;
    long jikuo;
    //printf("size = %d\n", sizeof(long));
    ret = reverse(a);
    printf("ret = %d\n", ret);
    return 0;
}

int reverse(int x)
{
    long count = 0;
    while (x != 0){
        count = count * 10 + x % 10;
        x = x / 10;
    }
    
    return count > 2147483647 || count < -2147483648 ? 0 : count;
}
