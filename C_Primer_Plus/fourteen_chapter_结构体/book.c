#include <stdio.h>
#include <string.h>

char * s_gets(char * st, int n);

#define MAXTITLE    41
#define MAXAUTL     31

struct book{
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
};

int main(int argc, char *argv[])
{
    #if 0
    struct book library = {
        "war and peace",
        "jjjj",
        4.88
    };
    #endif
    struct book library = {
        .author = "jjj",
        .value = 99.33,
        .title = "jijijdijidji"
    };


    int ret = -1;
    #if 0
    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITLE);
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    #endif

    printf("%s by %s: &%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf("Done\n");


    ret = sizeof(float);
    printf("ret = %d\n", ret);
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        } else {
            while (getchar() != '\n')
            {
                continue;
            }
            
        }
    }
    return ret_val;

}