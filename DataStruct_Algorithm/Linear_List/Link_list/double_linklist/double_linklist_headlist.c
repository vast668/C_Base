/*
main.c
DoubleLinledList_headList

Create by wang_jikuo on 2020/11/22, copy from chenyufeng1991(gihub)
                                    摘自GitHub chenyufeng用户

function: 实现带头结点和尾节点的非循环双向链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_linklist.h"

int jikuo = 1000;

//1.初始化带头结点和尾结点的非循环双向链表, initial linklist
void InitialList(Node ** pHead, Node ** pTail)
{
    *pHead = (Node *)malloc(sizeof(Node));
    *pTail = (Node *)malloc(sizeof(Node));
    if (NULL == *pHead || NULL == *pTail){
        printf("malloc failed\n");
        return;
    } else {
        //这个是关键，也是判空的条件
        (*pHead)->prior = NULL;
        (*pTail)->next = NULL;
        //链表为空的时候把头结点和尾结点连接起来
        (*pHead)->next = *pTail;
        (*pTail)->prior = *pHead;
        printf("%s执行成功\n", __FUNCTION__);
    }
}

//2.创建带头结点和尾结点的双向非循环链表，一次创建多个结点，没必要传二重指针
void CreateList(Node *pHead, Node *pTail)
{
    Node * pInsert;
    Node * pMove;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;

    printf("enter number, (lesse than or equal to zero is over!)\n");
    scanf("%d", &(pInsert->element));
    pMove = pHead;
    while (pInsert->element > 0)
    {
        //这是连续创建结点，简单的指针操作，容易理解的
        pMove->next = pInsert;
        pInsert->prior = pMove;
        pInsert->next = pTail;
        pTail->prior = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->prior = NULL;
        pInsert->next = NULL;

        printf("enter number, (lesse than or equal to zero is over!)\n");
        scanf("%d", &(pInsert->element));
    }
    printf("%s函数执行完毕\n", __FUNCTION__);
}

//3. 正序打印链表
void PrintList(Node * pHead, Node * pTail)
{
    Node * pMove;
    pMove = pHead->next;    //直接指向第一个结点
    while (pMove != pTail)
    {
        printf("%d", pMove->element);
        pMove = pMove->next;
    }
    
    printf("\n%s执行成功，正序打印链表结点\n", __FUNCTION__);
}

//4. 逆序打印链表
void PrintReverseList(Node * pHead, Node * pTail)
{
    Node * pMove;
    pMove = pTail->prior;   //逆序，尾指针起作用，直接指向最后一个结点
    while (pMove != pHead)
    {
        printf("%d", pMove->element);
        pMove = pMove->prior;   //最后一个结点通过前置指针来遍历链表
    }
    
    printf("\n%s执行成功，逆序打印链表结点\n", __FUNCTION__);
}

//5. 清除链表中的所有元素，使表成为空表
void ClearList(Node * pHead, Node * pTail){

    Node * pMove;
    pMove = pHead->next;        //指向第一个结点
    while (pMove != pTail){
        pHead->next = pMove->next;  //头指向第一个结点的下一个结点
        pMove->next->prior = pHead; //第一个结点的下一个结点的前置指针指向头

        free(pMove);
        pMove = pHead->next;
    }

    printf("%s执行成功\n", __FUNCTION__);
}

//6. 计算链表的长度
int SizeList(Node * pHead, Node * pTail)
{
    int i = 0;
    Node * pMove;
    pMove = pHead->next;
    while (pMove != pTail){
        i++;
        pMove = pMove->next;
    }
    printf("%s执行成功，链表的长度为%d\n", __FUNCTION__, i);

    return i;
}

//7. 判断链表是否为空
/*
return:
    1:  空
    0： 不为空
*/
int IsEmptyList(Node * pHead, Node * pTail)
{
    if (pHead->next == pTail){
        printf("%s函数执行，当前链表为空\n", __FUNCTION__);
        return 1;
    } else {
        printf("%s函数执行，当前链表为不为空\n", __FUNCTION__);
        return 0;
    }
}

//8. 返回链表中第pos个结点中的元素，若返回-1，表示没有找到
int GetElement(Node * pHead, Node * pTail, int pos)
{
    int i = 1;
    Node * pMove;
    pMove = pHead->next;
    while (pMove != pTail){
        if (i == pos){
            printf("%s执行成功，第pos=%d位置的元素为%d\n", __FUNCTION__, pos, pMove->element);
            return pMove->element;
        }
        i++;
        pMove = pMove->next;
    }
    printf("%s执行，查找pos=%d位置的元素失败\n", __FUNCTION__, pos);

    return -1;
}

//9. 把链表中第pos个结点的值修改为X
int ModifyElem(Node * pHead, Node * pTail, int pos, int x)
{
    int i = 1;
    Node * pMove;
    pMove = pHead->next;
    while (pMove != pTail){
        if (i == pos){
            pMove->element = x;
            printf("%s执行，修改pos=%d位置值为%d成功\n", __FUNCTION__, pos, x);
            return 1;
        }
        i++;
        pMove = pMove->next;
    }
    printf("%s执行，修改pos=%d位置元素失败\n", __FUNCTION__, pos);
    
    return -1;
}

//10. 头插法
int InsertHeadList(Node * pHead, Node * pTail, int x)
{
    Node * pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->element = x;
    pInsert->prior = NULL;
    pInsert->next = NULL;

    pInsert->next = pHead->next;
    pHead->next->prior = pInsert;
    pHead->next = pInsert;
    pInsert->prior = pHead;

    printf("%s执行，在表头插入%d成功\n", __FUNCTION__, x);


    return 0;
}

//11. 尾插法
int InsertTailList(Node * pHead, Node * pTail, int x)
{
    Node * pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->element = x;
    pInsert->prior = NULL;
    pInsert->next = NULL;

    pTail->prior->next = pInsert;
    pInsert->prior = pTail->prior;
    pInsert->next = pTail;
    pTail->prior = pInsert;

    printf("%s执行，在表尾插入%d成功\n", __FUNCTION__, x);


    return 0;
}
