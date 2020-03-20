#include <stdio.h>
#define BLURB   "Authentic imitation"

int main()
{
    printf("*[%2s]*\n", BLURB);
    printf("*[%24s]*\n", BLURB);
    printf("*[%24.5s]*\n", BLURB);
    printf("*[%-24.5s]*\n", BLURB);

    printf("%d\n", sizeof(long));
    return 0;
}

/*
*[Authentic imitation]*
*[     Authentic imitation]*
*[                   Authe]*
*[Authe                   ]*        .5  保证输出精度，不是小数点后几位，是全部的输出
*/