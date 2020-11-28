#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

void InitQueue(SqQueue * Q)
{
    Q->rear = Q->front = 0;     //初始化队首、队尾指针（假指针）
}

_Bool IsEmpty(SqQueue * Q)
{
    if (Q->rear == Q->front)
        return true;
    else
        return false;
}

//入队
_Bool EnQueue(SqQueue * Q, ElemType x)
{
    if ((Q->rear + 1) % MaxSize == Q->front)
        return false;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    return true;
}

//出队
_Bool DeQueue(SqQueue * Q, ElemType * x)
{
    if (IsEmpty(Q)){
        return false;
    }
    *x = (Q->data)[Q->front];
    Q->front = (Q->front + 1) % MaxSize;

    return true;
}

//遍历
void Traverse(SqQueue * Q)
{
    int front = Q->front;
    while (Q->front != Q->rear){
        printf("element is %d\n", Q->data[Q->front]);
        Q->front++;
    }
    Q->front = front;
    return;
}


int main()
{
    ElemType i, d_queue;
    _Bool result;
    SqQueue Q;
    memset(&Q, 0, sizeof(SqQueue));
    InitQueue(&Q);
    result = IsEmpty(&Q);
    printf("result is %d\n", result);
    for (i = 0; i < 10; i++){
        EnQueue(&Q, i+100);
    }
    Traverse(&Q);
    for (i = 0; i < 10; i++){
        EnQueue(&Q, i+200);
    }

    for (i = 0; i < 10; i++){
        DeQueue(&Q, &d_queue);
        printf("elem of dequeue is %d\n", d_queue);
    }
    Traverse(&Q);
    
    return 0;
}