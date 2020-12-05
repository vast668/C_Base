#include <stdio.h>
#include <string.h>

#define MAXLEN 16
typedef struct string{
    char ch[MAXLEN];
    int length;
}SString;


void get_next(SString * T, int next[])
{
    int i = 1, j = 0;   //从数组的下标[1]开始
    next[1] = 0;
    while (i < T->length){
        if(j == 0 || T->ch[i] == T->ch[j]){
            ++i; ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int Index_KMP(SString * S, SString * T, int next[])
{
    int i = 1, j = 1;
    while (i < S->length && j <= T->length){
        if (j == 0 || S->ch[i] == T->ch[j]){
            ++i; ++j;
        }
        else
            j = next[j];
    }
    if (j > T->length){
        return i - T->length;
    } else {
        return 0;
    }

}


int main()
{
    int ret = 0;
    SString Str;
    SString sub;
    int next_arr[10] = {0};
    memset(&Str, 0, sizeof(struct string));
    memset(&sub, 0, sizeof(struct string));
    sprintf(Str.ch, "%s", "ababcabcacbab");
    Str.length = strlen(Str.ch);
    sprintf(sub.ch, "%s", "-abcac"); //这个算法是有问题的，是从下标[1]开始，需要在匹配字符串前面加个符号
    sub.length = strlen(sub.ch);
    printf("%s\n", Str.ch);
    printf("%s\n", sub.ch);
    printf("%d\n", Str.length);
    printf("%d\n", sub.length);
    printf("=================\n");
    get_next(&sub, next_arr);
    for (int i = 0; i < 10; i++){
        printf("%d\n", next_arr[i]);
    }
    memset(&sub, 0, sizeof(struct string));
    sprintf(sub.ch, "%s", "abcac"); //这个算法是有问题的，是从下标[1]开始，需要在匹配字符串前面加个符号
    sub.length = strlen(sub.ch);
    ret = Index_KMP(&Str, &sub, next_arr);
    printf("match value is %d\n", ret);

    return 0;
}