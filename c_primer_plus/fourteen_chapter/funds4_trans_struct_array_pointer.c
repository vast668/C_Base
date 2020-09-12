#include <stdio.h>

#define FUNDLEN 50
#define N 2

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds money[], int n);

int main(int argc, char *argv[])
{
    struct funds stan[N] = {
        {
            "Garlic-Melon Bank",
            4032.27,
            "Lucky's Savings and Loan",
            8543.94
        },
        {
            "Garlic-Melon2 Bank",
            432.27,
            "Lucky's Savings2 and Loan2",
            853.94
        },

    };

    printf("Stan has a toatl of $%.2f.\n", sum(stan, N));  //actual not chage value of stan, just creat a copy file
    
    return 0;
}


double sum(const struct funds moolah[], int n)
{
    double total;
    int i;
    for (i = 0, total = 0; i < n; i++){
        total += moolah[i].bankfund + moolah[i].savefund;
    }

    return(total);
}

/*


*/