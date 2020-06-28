// penny.c

#include <stdio.h>

FILE *fp;

void outputHeader(void);
int createTable(double MaxAmount);

int main (void) {
    int days;
    double amount;
    
    fp = fopen("csis.txt", "w");
    printf(     "Please enter the amount of money you want to accumulate: ");
    fprintf(fp, "Please enter the amount of money you want to accumulate: ");
    scanf("%lf", &amount);
    fprintf(fp, "%12.2lf\n", amount);
    outputHeader();
    days = createTable(amount);
    printf(     "\nIt took %d days to accumulate at least $%10.2lf.", days, amount);
    fprintf(fp, "\nIt took %d days to accumulate at least $%10.2lf.", days, amount);
    return 0;
}

void outputHeader(void) {
    printf(     "\n%10s %15s %15s\n", "DAY", "DEPOSIT", "BALANCE");
    printf(     "%10s %15s %15s\n",   "---", "-------", "-------");
    fprintf(fp, "\n%10s %15s %15s\n", "DAY", "DEPOSIT", "BALANCE");
    fprintf(fp, "%10s %15s %15s\n",   "---", "-------", "-------");
   
}

int createTable(double amount) {
    int day = 0;
    double deposit = 0.01, balance = 0.0;
    while (balance < amount) {
        ++day;
        balance += deposit;
        printf(     "%10d %15.2f %15.2f\n", day, deposit, balance);
        fprintf(fp, "%10d %15.2f %15.2f\n", day, deposit, balance);
        deposit *= 2;
    }
    return day;
}
