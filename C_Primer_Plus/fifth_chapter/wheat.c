#include <stdio.h>
#define SQUARES 64

int main(){
    const double CROP = 2E16;    //世界小麦年产量
    double current, total;
    int count = 1;

    printf("square      grains      total       ");
    printf("fraction    of  \n");

    printf("           . added      grains      ");
    printf(" world total\n");
    total = current = 1.0;  
    printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    while( count < SQUARES){
        count += 1;
        current = 2.0 * current;
        total += current;       //total = total + current;
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    }
    printf("That is all\n");


    return 0;
}