#include <stdio.h>

int main()
{
    float salary;
    printf("\aEnter your desired monthly salary:");
    printf(" $_____\b\b\b\b\b");
    scanf("%f", &salary);
    printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12.0);
    printf("\rGee!\n");     //这一行为什么比上一行先执行

    return 0;
}