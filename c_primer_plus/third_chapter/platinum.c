#include <stdio.h>

int main()
{
    float weight;
    float value;

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds\n");
    getchar();
    //获取用户输入
    scanf("%f", &weight);   //note: 这里不需要加换行符
    getchar();
    getchar();
    value = 1700.0 * weight * 14.5833;
    printf("Your weight in platinum is worth $%.5f.\n", value);
    printf("You are easily worth that! if paltinum price drop, \n");



    return 0;
}