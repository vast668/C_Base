#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define InitSize 100
#define MaxSize 100
typedef struct {
    int * data;
    int length;
}SeqList;

#if 0
#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int length;
}SeqList;
#endif

#if 1
_Bool ListInser(SeqList *L, int i, int e)
{
    if (i < 1 || i > L->length + 1)
        return false;
    if (L->length >= MaxSize)
        return false;
    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j-1];

    L->data[i-1] = e;
    L->length++;

    return true;
}
#endif

_Bool ListShow(SeqList *L)
{
    printf("=========show start=========\n");
    for (int i = 0; i < L->length; i++){
        printf("L->data[%d] = %d\n", i, L->data[i]);
    }
    
    return true;
}

_Bool ListDelete(SeqList * L, int i, int e)
{
    if (i < 1 || i > L->length + 1){
        return false;
    }
    e = L->data[i-1];

    for (int j = i; j < L->length; j++){
        L->data[j-1] = L->data[j];
    }

    L->length--;
    
    return true;
}
int main(void)
{
    SeqList L;
    _Bool ret = 0;
    int delete;
    memset(&L, 0, sizeof(SeqList));
    // printf("&L = %p\n", &L);

    L.data = (int *)malloc(sizeof(int) * InitSize);
    memset(L.data, 0, sizeof(int) * InitSize);
    for (int i = 0; i < 10; i++){
        ListInser(&L, i+1, 900+i);
    }
    ListShow(&L);
    printf("%d\n", L.length);
    ListDelete(&L, 10, delete);
    ListShow(&L);

    return 0;
}







