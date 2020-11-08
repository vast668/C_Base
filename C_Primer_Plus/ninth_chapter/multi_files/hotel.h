#define QUIT        5
#define HOTEL1      180.00
#define HOTEL2      225.00
#define HOTEL3      255.00
#define HOTEL4      355.00

#define DISCOUNT    0.95
#define STARS "=================="

//show list
int menu(void);

//return days of reserve
int getnights(void);

//show price
void showprice(double rate, int nights);
