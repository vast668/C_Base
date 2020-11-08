#include <stdio.h>

struct {
    unsigned int field1 : 1;
    unsigned int        : 2;
    unsigned int field2 : 1;
    unsigned int        : 1;
    unsigned int field3 : 1;
} stuff;

int main()
{
    int size = 0;
    printf("the size of stuff is %lu\n", sizeof(stuff));

    return 0;
}


#if 0
struct {
    unsigned int autfd : 1;
    unsigned int bldfc : 1;
    unsigned int undln : 1;
    unsigned int itals : 1;
    unsigned int itals1 : 1;
    unsigned int itals2 : 1;
    unsigned int itals3 : 1;
    unsigned int itals5 : 1;
    unsigned int itals6 : 1;
    unsigned int itals7 : 1;
    unsigned int itals8 : 1;
    unsigned int itals9 : 1;
    unsigned int itals11 : 1;
    unsigned int itals12 : 1;
    unsigned int itals13 : 1;
    unsigned int itals14 : 1;
    unsigned int autfd1 : 1;
    unsigned int bldfc2 : 1;
    unsigned int undln3 : 1;
    unsigned int italsd1 : 1;
    unsigned int itals15 : 1;
    unsigned int itals22 : 1;
    unsigned int itals33 : 1;
    unsigned int itals54 : 1;
    unsigned int itals63 : 1;
    unsigned int itals72 : 1;
    unsigned int itals83 : 1;
    unsigned int itals92 : 1;
    unsigned int itals112 : 1;
    unsigned int itals122 : 1;
    unsigned int itals113 : 1;
    unsigned int itals142 : 1;
    unsigned int italdfds142 : 1;
} prnt;

int main()
{
    int size = 0;
    printf("the size of prnt is %lu\n", sizeof(prnt));

    return 0;
}


#endif