#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITLE    40
#define MAXAUTL     40
#define MAXBKS      10

char * s_gets(char * st, int n);

struct book {
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book libray[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.bat", "a+b")) == NULL){
        fputs("can't open book.bat file\n", stderr);
        exit(-1);
    }
    rewind(pbooks);
    while (count < MAXBKS && fread(&libray[count], size, 1, pbooks) == 1){
        if (count == 0){
            puts("Current contents of book.bat:");
        }
        printf("%s by %s $%.2f\n", libray[count].title,
            libray[count].author, libray[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS){
        fputs("The book.bat file is full.", stderr);
        exit(2);
    }
    puts("Please add new book titles.");
    puts("Please [enter] at the start of a line to stop.");

    while (count < MAXBKS && s_gets(libray[count].title, MAXTITLE) != NULL
        && libray[count].title[0] != '\0')
    {
        puts("Now enter the author");
        s_gets(libray[count].author, MAXAUTL);
        puts("Now enter value");
        scanf("%f", &libray[count++].value);
        while (getchar() != '\n'){
            continue;
        }
        if (count < MAXBKS){
            puts("Enter the next title.");
        }
    }

    if (count > 0){
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++){
            printf("%s by %s $%.2f\n", libray[index].title,
            libray[index].author, libray[index].value);
        }
        fwrite(&libray[filecount], size, count - filecount, pbooks);
    } else {
        puts("No books? Too bad.\n");
    }
    puts("Bye.\n");
    fclose(pbooks);



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