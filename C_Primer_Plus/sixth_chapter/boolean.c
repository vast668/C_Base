#include <stdio.h>

int main()
{
    long num;
    long sum = 0L;
    _Bool input_is_good;

    printf("Please enter an integer tob sumed ");
    printf("(q to quit): ");
    input_is_good = (scanf("%ld", &num) == 1);
    
    while (input_is_good){
        sum += num;
        printf("Please enter the next integer(q to quit): ");
        input_is_good = (scanf("%ld", &num) == 1);

    }
    printf("Those integer sum to %ld.\n", sum);
    return 0;
}