#include <stdio.h>
#include "hotel.h"

int menu(void)
{
    int code, status;

    printf("%s\n", STARS);
    printf("Enter the number of the desired hotel:\n");
    
    while ((status = scanf("%d", &code)) != 1 || (code < 1 || code > 5)){
        if (status != 1)
            scanf("%*s");   //handle no interger input
        printf("Enter an interger from 1 to 5, please.\n");
    }
    return code;
}

int getnights(void)
{
    int nights;

    printf("how many nights are needed? ");
    while (scanf("%d", &nights) != 1){
        scanf("%*s");
        printf("Please enter an interger, such as 2.\n");
    }

    return nights;
}

void showprice(double rate, int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;
    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
        total += rate * factor;
    printf("The total cost will be $%0.2f.\n", total);
    return;
}



#if 0

scanf() success return 1, failed return 0
scanf("%*s"); 表示将剩余的字符串输入到s中

#include <stdio.h>

int main()
{
    char integer;
    int status;

    status = scanf("%d", &integer);         //depend on format %d %c %f
    printf("%d\n", status);
    status = scanf("%*s");
    printf("%d\n", status);

    return 0;
}
#endif