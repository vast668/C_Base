/*
main.c
DoubleLinledList_headList

Create by wang_jikuo on 2020/11/22

copyright 2020, All rights reserved

function: 实现带头结点和尾节点的非循环双向链表
            Implement no-circle double_linklist with head and tail node
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
typedef struct NodeList{
    ElemType element;
    struct NodeList * prior;
    struct NodeList * next;
}Node;

int jikuo;

//1.初始化带头结点和尾结点的非循环双向链表, initial linklist
void InitialList(Node ** pHead, Node ** pTail);

//2.创建带头结点和尾结点的双向非循环链表，一次创建多个结点，没必要传二重指针
void CreateList(Node *pHead, Node *pTail);

//3. 正序打印链表
void PrintList(Node * pHead, Node * pTail);

//4. 逆序打印链表
void PrintReverseList(Node * pHead, Node * pTail);

//5. 清除链表中的所有元素，使表成为空表
void ClearList(Node * pHead, Node * pTail);

//6. 计算链表的长度
int SizeList(Node * pHead, Node * pTail);

//7. 判断链表是否为空
/*
return:
    1:  空
    0： 不为空
*/
int IsEmptyList(Node * pHead, Node * pTail);

//8. 返回链表中第pos个结点中的元素，若返回-1，表示没有找到
int GetElement(Node * pHead, Node * pTail, int pos);

//9. 把链表中第pos个结点的值修改为X
int ModifyElem(Node * pHead, Node * pTail, int pos, int x);

//10. 头插法
int InsertHeadList(Node * pHead, Node * pTail, int x);

//11. 尾插法
int InsertTailList(Node * pHead, Node * pTail, int x);
