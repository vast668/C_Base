#include <stdio.h>

#define COVEAGE 350
int main()
{
    int sq_feet;
    int cans;
    printf("Enter number of square feet to be painted:\n");
    while (scanf("%d", &sq_feet) == 1){
        cans = sq_feet / COVEAGE;
        cans += ((sq_feet % COVEAGE == 0)) ? 0 : 1;
        printf("You need %d %s of paint.\n", cans, cans == 1 ? "can" : "cans");

        printf("Please type next value (q to quit):\n");
    }

    return 0;
}