#include <stdio.h>

#define SIZE 4
int sump(int * start, int * end);

int main(void)
{
    int marbles[SIZE] = {100, 200, 300, 400};
    long answer;
    answer = sump(marbles, marbles + SIZE);     //这里加的SIZE！！！
    printf("%d\n", answer);

    return 0;   
}

int sump(int * start, int * end)
{
    int total = 0;
    printf("start = %p end = %p\n", start, end);
    while (start < end){
        total += *start++;
        // start++;        //pointer self addd
    }

    return total;
}

/*
    [root@localhost tenth_chapter]# ./a.out 
    start = 0x7ffd962d7760 end = 0x7ffd962d7770
    1000
    [root@localhost tenth_chapter]# 

    marbles 是数组的首元素的首地址，内存都是以字节为单位编址的
    整型变量占4个字节
    所以首元素所占的范围是
    0x7ffd962d7760-0x7ffd962d7763       100
    0x7ffd962d7764-0x7ffd962d7767       200
    0x7ffd962d7768-0x7ffd962d776b       300
    0x7ffd962d776c-0x7ffd962d776f       400


    而0x7ffd962d7770则是跟数组无关的地址
    while (start < end)这个判断条件很恰当
    ==============================
    total += *start;
    start++;
    ================
    等同于
    total += *start++;

    ++ & * 有着相同的优先级，顺序是从右到左
    也就是start先和++相结合，然后再与*结合
    但是，后置++，
    所以先是*start，再是start++
*/