#include <stdio.h>
#define BOOK "war and peace"
int main()
{
    float cost = 12.99;
    float percent = 80.0;
    printf("%c %c %c\n", 'A', 105, '\41');
    printf("this is copy of \"%s\" sells for $%2.2f\n", BOOK, cost);
    printf("That is %.0f%%\n", percent);


    return 0;
}