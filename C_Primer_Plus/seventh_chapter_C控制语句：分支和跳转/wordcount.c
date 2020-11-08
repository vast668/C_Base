#include <stdio.h>
#include <ctype.h>      //provide function for isspace()
#include <stdbool.h>    //provide define for true, false and bool
#define STOP '|'

int main()
{
    char c;     //read-in character
    char prev;  //prev character
    long n_chars = 0L;
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;    //no complete lines
    bool inword = false;
    printf("Enter text to be analyzed (| to terminate); \n");
    prev = '\n';
    while ((c = getchar()) != STOP){
        n_chars++;  //include all characters(\n, space)
        if (c == '\n')
            n_lines++;
        if (!isspace(c) && !inword){
            inword = true;      //start a new word
            n_words++;          //count words
        }
        if (isspace(c) && inword)
            inword = false;     //the end of word
        prev = c;       //save character 
    }
    if (prev != '\n')
        p_lines = 1;
    printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);

    return 0;
}