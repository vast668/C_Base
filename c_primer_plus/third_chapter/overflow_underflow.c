#include <stdio.h>

int main()
{
    float toobig = 3.4E38 * 100.0f;
    printf("%e\n", toobig);             //输出inf    infinite   表示无穷大

    return 0;
}