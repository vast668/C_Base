#include <stdio.h>
#define SEC_PER_MIN 60

int main()
{
    int sec, min, left;

    printf("Convert seconds to minutes and seconds\n");
    printf("Enter the number of seconds (<= 0 quit!): \n");
    // scanf("%d", &sec);
    printf("sec = %d\n", sec);
    while(sec > 0){
        scanf("%d", &sec);
        min = sec / SEC_PER_MIN;        //截断分钟数
        left = sec % SEC_PER_MIN;       //剩下的秒数
        printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
        printf("Enter next value (<= 0 quit!): \n");
        

    }


    return 0;
}