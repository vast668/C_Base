#ifdef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>
//在这里插入Item类型的定义
typedef int Item;       //用于use_q.c
#define MAXQUEUE 10
typedef struct node
{
    Item item;
    struct node * next;
}Node;

//定义队列的数据结构
typedef struct queue{
    Node * front;       //指向队列首项的指针
    Node * rear;        //指向队列尾项的指针
    int items;          //队列中的项数
}Queue;

//操作：            初始化队列
//前提条件：        pq指向一个队列
//后置条件：        队列被初始化为空
void InitializeQueue(Queue * pq);

//操作：           检查队列是否已满
//前提条件：        pq指向一个已初始化的队列
//后置条件：        满返回true，否则返回false
bool QueueIsFull(const Queu * pq);

//操作：            检查队列是否为空
//前提条件：        pq指向之前被初始化的队列
//后置条件：        如果队列为空则返回true，否则返回false






#endif