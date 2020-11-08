#include <stdio.h>
#define FORMAT "%s! c is cool!"
#define Ten 10
int main()
{
    int n = 0;
    
    if (n++ == 0){
        printf("1\n");
        printf("%d\n", n);
    }
    else
        printf("0\n");
    
    /*
    while (n++ < Ten)
        printf("%5d", n);
    printf("\n");

    */
    
    
    
    
    
    
    
    
    /*
    char c1, c2;
    int diff;
    float num;

    c1 = 'S';
    c2 = 'O';
    diff = c1 - c2;
    num = diff;

    printf("%c%c%c:%d %5.2f\n", c1, c2, c1, diff, num); 
    */
    
    
    
    /*
    int num = 10;
    int digit = 10;
    int a = 1;
    int b = 1;
    a = num--;      //10
    b = --digit;    //11

    printf("%d\n", a);
    printf("%d\n", b);
    */
    /*
    int num = 10;
    int digit = 10;
    int a = 1;
    int b = 1;
    a = num++;      //10
    b = ++digit;    //11

    printf("%d\n", a);
    printf("%d\n", b);
    */

   /*
    int num = 10;
    // printf(FORMAT, FORMAT);     //两个
    printf("%d\n", ++num);      //11
    printf("%d\n", num++);      //11
    printf("%d\n", num--);      //12
    printf("%d\n", --num);      //10
    printf("%d\n", num);        //10
    */

    return 0;
}












/*
int main()
{
    // int x, y;

    // y = 3 + 2*(x = 7/2);

    // printf("y = %d, x = %d\n", y, x);        // 9  3

    // x = (2 + 3) * 10.5;
    // printf("x = %d\n", x);      // 52!!!!   no 50

    int i= 1;
    float n;
    printf("Watch out!, Here come a bunch of fractions!\n");

    while (i < 30)
        n = 1/i;
        printf(" %f", n);
    printf("That's all, folks!\n");

    return 0;
}
*/

