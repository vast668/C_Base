#include <stdio.h>

#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node 
{
    Item item;
    struct node * next;
} Node;

typedef Node List;

void InitializeList(List * plist)
{
    plist == NULL;
}

int main()
{
    List movies;
    // printf("movies = %p\n", movies);
    printf("sizeof movies = %d\n", sizeof(movies));

    printf("&movies = %p\n", &movies);
    printf("sizeof &movies = %d\n", sizeof(&movies));
    Item temp;
    InitializeList(&movies);
    printf("======================\n");
    // printf("movies = %p\n", movies);
    printf("sizeof movies = %d\n", sizeof(movies));

    printf("&movies = %p\n", &movies);
    printf("sizeof &movies = %d\n", sizeof(&movies));

    return 0;
}


/*
好像传指针也是可以的

需要搜更多的资料，为什么是传二重指针


*/
