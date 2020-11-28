#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


void showmovies(Item item);

char * s_gets(char * st, int n);

int main()
{
    List movies;                //指针
    Item temp;

    //初始化
    InitializeList(&movies);    //改变指针的值，就把指针的地址传过去
    if (ListIsFull(&movies)){
        fprintf(stderr, "No memory avaliable! Bye!\n");
        exit(1);
    }
    
    //获取用户输入并存储
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }

    //显示
    if (ListIsEmpty(&movies)){
        printf("No data entered. ");
    } else {
        printf("Here is the movie list: \n");
        Traverse(&movies, showmovies);
    }

    printf("You entered %d movies.\n", ListItemCount(&movies));

    //清理
    EmptyTheList(&movies);
    printf("Bye\n");


    return 0;
}

void showmovies(Item item)
{
    printf("movie: %s Rating %d\n", item.title, item.rating);
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');
        if (find){
            *find = '\0';
        } else {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}