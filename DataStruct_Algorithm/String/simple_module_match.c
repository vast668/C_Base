#include <stdio.h>
#include <string.h>

#define MAXLEN 16
typedef struct string{
    char ch[MAXLEN];
    int length;
}SString;


int search(SString * S, SString * T)
{
    int i = 1, j = 1;
    while(i <= S->length && j <= T->length){
        // printf("i = [%c] j = [%c]\n", (S->ch)[i], (T->ch)[j]);
        if ((S->ch)[i] == (T->ch)[j]){
            ++i; ++j;
            printf("if true\n");
        }
        else{
            printf("else\n");
            i = i-j+2; j = 1;   //指针后退重新开始匹配
        }
    }
    if (j > T->length){
        return i - T->length;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    int ret = 0;
    SString Str;
    SString sub;
    memset(&Str, 0, sizeof(struct string));
    memset(&sub, 0, sizeof(struct string));
    sprintf(Str.ch, "%s", "jkjikuoo");
    Str.length = 9;
    sprintf(sub.ch, "%s", "-jikuo");    //这个算法是有问题的，是从下标[1]开始，需要在匹配字符串前面加个符号
    sub.length = 5;

    printf("%s\n", Str.ch);
    printf("%s\n", sub.ch);
    ret = search(&Str, &sub);
    printf("%d\n", ret);

    return 0;
}