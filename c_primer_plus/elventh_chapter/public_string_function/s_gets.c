/*
作用：读取一行字符串，将换行符换成空行'\0'
*/


#include <stdio.h>


char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);

    if (ret_val){
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
        
    }



    return ret_val;
}