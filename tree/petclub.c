/*petclub.c --使用二叉树找数*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"


char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);

int main()
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while((choice = menu()) != 'q')
    {
        switch(choice)
        {
            case 'a': addpet(&pets);
                break;
            case 'l': showpets(&pets);
                break;
            case 'f': findpet(&pets);
                break;
            case 'n': printf("%d pets in club\n", TreeItemCount(&pets)); 
                break;
            case 'd': droppet(&pets);
                break;
            default: puts("Switching error!");
        }
    }
    DeleteALL(&pets);
    puts("Bye.");

    return 0;
}

char menu(void)
{
    int ch;
    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice: ");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    while((ch = getchar()) != EOF)
    {
        while((ch = getchar()) != '\n') //处理函数剩余内容
            continue;
        ch = tolower(ch);
        if(strchr("alrfndq", ch) == NULL)
            puts("Please enter an a,l,f,n,d or q:");
        else
            break;
    }
    if(ch == EOF)
        ch = 'q';

    return ch;
}

void addpet(Tree * pt)
{
    Item temp;

    if(TreeIsFull(pt))
        puts("NO room in the club!");
    else
    {
        puts("Plese enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Plese enter kind of pet:");
        s_gets(temp.petkind, SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree * pt)
{
    if(TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree * pt)
{
    Item temp;
    if(TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }
    puts("Plese enter name of pet you wish ti find:");
    s_gets(temp.petname, SLEN);
    puts("Plese enter kind of pet:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s", temp.petname, temp.petkind);
    if(InTree(&temp, pt))
        printf("is a member.\n");
    else
        printf("is not a member.\n");
}

void droppet(Tree * pt)
{
    Item temp;
    if(TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;         //如果树为空则退出该函数
    }
    puts("Plese enter name of pet you wish ti delete:");
    s_gets(temp.petname, SLEN);
    puts("Plese enter kind of pet:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s", temp.petname, temp.petkind);
    if(DeleteItem(&temp, pt))
        printf("is dropped from club.\n");
    else
        printf("is not a member.\n");
}

void uppercase(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');    //查找换行符
        if(find)                    //如果地址不是NULL
            *find = '\0';           //在此处放置一个空字符
        else
            while(getchar() != '\n')
                continue;           //处理输入行的剩余内容
    }
    return ret_val;
}
