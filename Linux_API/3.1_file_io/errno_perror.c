#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    FILE * pf;
    int errnum;
    pf = fopen("jikuo.txt", "rb");

    if (pf == NULL){
        errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("Error printed by perror");
        fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
    } else {
        fclose(pf);
    }

    return 0;
}





#if 0
int main()
{
    FILE * fp;
    fp = fopen("jikuo.txt", "r");

    if (fp == NULL){
        printf("Error: %s\n", strerror(errno));
    }

    return 0;
}
#endif


#if 0
int main()
{
    FILE * fp;

    //first rename if there is any file
    rename("file.txt", "new_file.txt");
    
    //now let's try open same file
    fp = fopen ("file.txt", "r");
    if (fp == NULL){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    return 0;
}
#endif