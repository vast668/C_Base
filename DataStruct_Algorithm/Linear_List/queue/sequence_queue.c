#include <stdio.h>

int EnQueue(int * a, int rear, int data)
{
    a[rear] = data;
    rear++;             //队列是从尾进头出
    return rear;
}

void DeQueue(int * a, int front, int rear)
{
    //如果front == rear, 表示队列为空
    while (front != rear){
        printf("the elementy that go out queue is %d\n", a[front]);
        front++;        //尾进头出
    }
}

int main(void)
{
    int Seq_Q[10] = {0};
    int front, rear;
    front = rear = 0;
    //入队
    rear = EnQueue(Seq_Q, rear, 1);
    rear = EnQueue(Seq_Q, rear, 2);
    rear = EnQueue(Seq_Q, rear, 3);
    rear = EnQueue(Seq_Q, rear, 4);
    rear = EnQueue(Seq_Q, rear, 5);
    //出队
    DeQueue(Seq_Q, front, rear);

    return 0;
}