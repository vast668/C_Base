#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv[])
{
    
    int val = 0, i = 0;
    if (argc != 2){
        printf("usage: %s number\n", argv[0]);
        return -1;
    }
    // srand(atoi(argv[1]));
    srand(time(NULL));
    for (i = 0; i < 6; i++){
        val = rand();
        printf("%d ", val % 6);
    }
    puts("\n");


    return 0;
}