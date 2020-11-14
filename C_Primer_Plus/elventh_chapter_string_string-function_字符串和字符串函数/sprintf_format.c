#include <stdio.h>
#define MAX 20
char * s_gets(char * st, int n);

int main(void)
{
    char first[MAX];
    char last[MAX];
    char format[2 * MAX + 10];
    double prize;

    puts("Enter your first name: ");
    s_gets(first, MAX);
    puts("Enter your last_name: ");
    s_gets(last, MAX);
    puts("Enter your prize money:");
    scanf("%lf", &prize);
    sprintf(format, "%s, %-19s: $%6.2f\n", last, first, prize);

    puts(format);

    return 0;
}

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

/*
./a.out 
Enter your first name: 
wang
Enter your last_name: 
jikuo
Enter your prize money:
88
jikuo, wang               : $ 88.00
*/