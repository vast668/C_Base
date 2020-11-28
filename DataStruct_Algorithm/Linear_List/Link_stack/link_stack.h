#ifndef _CONFLICT_DEFINE
#define _CONFLICT_DEFINE

typedef int Elementype;

typedef struct node {
    Elementype data;
    struct node * pNext;
}Node, *pNode;

typedef struct stack {
    pNode pTop;         //栈顶指针
    pNode pBottom;      //栈底指针
}Stack, *pStack;

//栈判空
_Bool Is_Empty(pStack s);
//遍历栈中的元素
void Traverse_Stack(pStack s);

//创建一个空栈,， 里面没有任何数据
void Create_Stack(pStack * s);
//压栈算法
/*
(1)创建一个节点p，并修改节点的指针域使其指向栈顶数据元素； p->pNext = pTop
(2)修改栈顶指针，使其指向栈顶元素，pTop = p;
*/
void Push_Stack(pStack s, int val);

//弹栈算法
/*
(1)先用P指针保存要删除的地址，用于便于释放节点的内存，即p = pTop;
(2)修改栈顶指针的指向，使其指向栈顶元素；pTop = pTop->pNext;
*/
_Bool Pop_Stack(pStack s, int * val);

void Clear_Stack(pStack s);

#endif







