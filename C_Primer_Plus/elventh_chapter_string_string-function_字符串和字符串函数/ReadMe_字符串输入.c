/*
综合fgets1,2,3 demo程序：

fgets()会将换行符输入到缓存区

fputs()不会输出换行符

puts()会输出换行符

遂，总结一个自定义函数 s_gets()

功能如下：
读取整行输入，并用空字符代替换行符，或者读取一部分输入，并丢弃一部分输入
*/

#include <stdio.h>
#include <string.h>


char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;
    char residue;
    ret_val = fgets(st, n, stdin);
    printf("st is %s\n", st);
    if (ret_val){
        while (st[i] != '\n' && st[i] != '\0'){
            printf(" i = %d times\n", i);
            i++;
        }
            
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n'){
                residue = getchar();
                printf("residue is %c\n", residue);
                printf(" i = %d 剩余字符\n", i);    //fgets()会根据n的数量将输入的字符截断
                                                //那么剩余的字符串在这里处理
                continue;
            }
                
        
    }
    
    return ret_val;
}

int main()
{
    char words[10] = {0};
    s_gets(words, 10);

    return 0;
}