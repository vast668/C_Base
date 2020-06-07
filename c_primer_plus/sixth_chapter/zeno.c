#include <stdio.h>

int main()
{
    int t_cnt;
    double time, power_of_2;
    int limit;
    printf("Enter the number of terms you want: ");
    scanf("%d", &limit);
    for (time = 0, power_of_2 = 1, t_cnt = 1; t_cnt <= limit; t_cnt++, power_of_2 *= 2.0)
    {
        time += 1.0 / power_of_2;
        printf("time = %f when terms = %d.\n", time, t_cnt);
    }

    return 0;
}