#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "link_stack.h"

//栈判空
_Bool Is_Empty(pStack s)
{   
    if (s->pTop == s->pBottom)
        return true;
    else
        return false;
}

//遍历栈中的元素
void Traverse_Stack(pStack s)
{
    pNode p = s->pTop;
    printf("element of stack is \n");
    while (p != s->pBottom){
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

//创建一个空栈,， 里面没有任何数据
void Create_Stack(pStack * s)
{
    (*s)->pBottom = (struct node *)malloc(sizeof(struct node));
    if (NULL == (*s)->pBottom){
        printf("malloc failed\n");
        exit(-1);
    }
    (*s)->pTop = (*s)->pBottom;
    (*s)->pTop->data = 0;
    (*s)->pTop->pNext = NULL;
}
//压栈算法
/*
(1)创建一个节点p，并修改节点的指针域使其指向栈顶数据元素； p->pNext = pTop
(2)修改栈顶指针，使其指向栈顶元素，pTop = p;
*/
void Push_Stack(pStack s, int val)
{
    pNode p = (struct node *)malloc(sizeof(struct node));
    if (NULL == p){
        printf("malloc failed\n");
        exit(-1);
    }
    p->data = val;
    p->pNext = s->pTop;
    s->pTop = p;
}

//弹栈算法
/*
(1)先用P指针保存要删除的地址，用于便于释放节点的内存，即p = pTop;
(2)修改栈顶指针的指向，使其指向栈顶元素；pTop = pTop->pNext;
*/
_Bool Pop_Stack(pStack s, int * val)
{
    if (Is_Empty(s))
        return true;
    else
    {
        pNode p = s->pTop;      //保存栈顶指针
        *val = s->pTop->data;
        s->pTop = s->pTop->pNext;
        free(p);
        p = NULL;   //防止野指针

        return true;
    }    
}

void Clear_Stack(pStack s)
{
    if(Is_Empty(s))
        return;
    else
    {
        pNode p = NULL;
        while (s->pTop != s->pBottom){
            p = s->pTop;
            s->pTop = s->pTop->pNext;
            free(p);
            p = NULL;
        }
    }
}
