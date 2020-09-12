#include <stdio.h>
#define MAXTITLE    41
#define MAXAUTL     31

struct book {
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book readfirst;
    int score;

    printf("Enter test score: ");
    scanf("%d", &score);

    if (score >= 84){
        readfirst = (struct book) {
            "Crime and Punishment",
            "Fyodor Dostoyevsky",
            11.25
        };
    } else {
        readfirst = (struct book) {
            "Crime and Punishment",
            "Fyodor Dostoyevsky",
            5.99
        };
    }
    printf("Your assigned reading: \n");
    printf("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);

    return 0;
}