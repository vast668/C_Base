#include <stdio.h>

#define FUNDLEN 50

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(struct funds moolah);
double p_sum(const struct funds * moolah);

int main(int argc, char *argv[])
{
    char * p = NULL;
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };

    printf("Stan has a toatl of $%.2f.\n", sum(stan));  //actual not chage value of stan, just creat a copy file
    printf("Stan has a toatl of $%.2f.\n", p_sum(&stan));
    printf("%ld\n", sizeof(p));
    return 0;
}

double sum(struct funds moolah)
{
    return((moolah.bankfund +1) + moolah.savefund);
}

double p_sum(const struct funds * moolah)
{
    return(moolah->bankfund + moolah->savefund);
}

/*
Stan has a toatl of $12577.21.
Stan has a toatl of $12576.21.


*/