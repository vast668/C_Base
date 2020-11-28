#include <stdio.h>
#include <string.h>
#include "link_stack.h"

int main(void)
{
    int i = 0;
    Stack s;
    pStack p_s = &s;
    memset(p_s, 0, sizeof(struct stack));
    Create_Stack(&p_s);
    for (i = 100; i < 110; i++){
        Push_Stack(p_s, i);
    }
    Traverse_Stack(p_s);
    Clear_Stack(p_s);
    Traverse_Stack(p_s);

    return 0;
}
