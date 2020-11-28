#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node * next;
}LinkNode;

typedef struct {
    LinkNode * front, * rear;
}LinkQueue;

//初始化
void InitQueue(LinkQueue * Q)
{
    Q->front =  Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}

//判断队是否为空
_Bool IsEmpty(LinkQueue * Q)
{
    if (Q->front == Q->rear) 
        return true;
    else
        return false;

}

//入队
void EnQueue(LinkQueue * Q, ElemType x)
{
    LinkNode * s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;     //创建新的额节点插入到链尾
    Q->rear->next = s;  //插入之前的尾的next指针指向s
    Q->rear = s;        //s成为新的尾

}

//遍历
void Traverse(LinkQueue * Q)
{
    LinkNode * p = Q->front;
    while (p->next != NULL){
        printf("element is %d\n", p->next->data);
        p = p->next;
    }
}

//出队
_Bool DeQueue(LinkQueue * Q, ElemType *x)
{
    if (Q->front == Q->rear) 
        return false;
    LinkNode * p = Q->front->next;  //第一个节点
    *x = p->data;    //取值
    Q->front->next = p->next;   //front指向第二个（下一个）节点
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);

    return true;

}


int main(int agrc, char *argb[])
{
    int i, d_queue;
    LinkQueue Q;
    InitQueue(&Q);
    IsEmpty(&Q);
    for (i = 0; i < 10; i++){
        EnQueue(&Q, i+100);
    }
    
    Traverse(&Q);
    for (i = 0; i < 10; i++){
        DeQueue(&Q, &d_queue);
        printf("element of dequeue is %d\n", d_queue);
    }

    return 0;
}