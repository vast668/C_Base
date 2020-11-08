#include <stdio.h>
#include <string.h>

#define LEN 20
const char * msgs[5] = {
    "   Thank you for the wonderful evening, ",
    "You certainly prove that a ",
    "is a special kind of guy. We must together",
    "over a delicious ",
    " and have a few laughs"

};

struct names {
    char first[LEN];
    char last[LEN];
};

struct guy {
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(int argc, char *argv[])
{
    struct guy fellow[2] = {
        {
            {"Even", "Villard"},
            "grilled salmon",
            "personality coach",
            68112.00
        },
        {
            { "Rodney", "Swillbelly" },
            "Tripe",
            "tabloid editor",
            432400.00
        }
    };

    struct guy * him;

    printf("address #1: %p #2 %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf("address #1: %p #2 %p\n", him, him+1);

    printf("hime->income is $%.2f: (*him).income is $%.2f\n", 
            him->income, (*him).income);

    printf("him->favfood is %s: him->handle.last is %s\n",
            him->favfood, him->handle.last);



    return 0;
}