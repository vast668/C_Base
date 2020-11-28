#include <stdio.h>
#include "double_linklist.h"


typedef struct test {
    int data;
    char p;
}Test_rt;

int main(void)
{
    Test_rt jikuo;
    Node * pHead;
    Node * pTail;
    InitialList(&pHead, &pTail);
    CreateList(pHead, pTail);
    PrintList(pHead, pTail);
    PrintReverseList(pHead, pTail);
    // ClearList(pHead, pTail);
    SizeList(pHead, pTail);
    IsEmptyList(pHead, pTail);
    GetElement(pHead, pTail, 3);
    ModifyElem(pHead, pTail, 3, 19);
    InsertHeadList(pHead, pTail, 100);
    InsertTailList(pHead, pTail, 101);
    PrintList(pHead, pTail);

    return 0;
}
