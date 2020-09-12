#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    char last_ch;
    printf("Give me a letter of the alphabet, and I will give ");
    printf("an animals name \nbegining with that letter.\n");
    printf("Please type a in a letter; type # to end my act.\n");

    while ((ch = getchar()) != '#'){
        if ('\n' == ch)
            continue;
        if (islower(ch))
            switch (ch){
                case ('a' | 'd' | 'e'):
                    printf("a\n");
                    break;
                case 'b':
                    printf("b\n");
                    break;
                case 'c':
                    printf("c\n");
                    break;
                default:
                    printf("jiku-wang\n");
            }
        else
            printf("I recognize only lowercase letter.\n");
        //handle the remaining characters   处理剩下的字符
        while ((last_ch = getchar()) != '\n'){
            putchar(last_ch);   //print remaining character
            // printf("appear\n");
            continue;
        }
            
        printf("Please type another letter or a #.\n");        
    }

    printf("Bye!\n");

    return 0;
}

/*
理解标准输入流的概念
输入的就是输入流
getchar就是获取输入流，只能获取一个字符
putchar是从输入流中获取一个字符放在输出流中

*/