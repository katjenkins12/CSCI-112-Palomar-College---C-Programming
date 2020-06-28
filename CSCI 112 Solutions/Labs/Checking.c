// checking.c

#include <stdio.h>
#include <stdlib.h>

FILE *csis, *fp;

void outputHeaders(void);
void initialBalance(double amount, double *balance, double *service, double *openBalance);
void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit);
void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck);
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance);

int main(void) {
	char code;
	double amount, service, balance, amtCheck, amtDeposit, openBalance, closeBalance;
	int numCheck, numDeposit;
	
	if (!(fp = fopen("account.txt", "r"))) {
        printf("account.txt could not be opened for input.");
        exit(1);
    }
	if (!(csis = fopen("csis.txt", "w"))) {
        printf("csis.txt could not be opened for output.");
        exit (1);
    }
	
	amount = service = balance = amtCheck = amtDeposit = openBalance = closeBalance = 0.0;
	numCheck = numDeposit = 0;
	
    outputHeaders();
	while (!feof(fp)) {
		fscanf(fp, "%c %lf\n", &code, &amount);
		if (code == 'I')
            initialBalance(amount, &balance, &service, &openBalance);
		else if (code == 'D')
            deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
		else
            check(amount, &balance, &service, &numCheck, &amtCheck);
	}
	closeBalance = balance - service;
    outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);
		
	fclose(csis);
	fclose(fp);
	return 0;
}

void outputHeaders(void) {
    printf(       "TRANSACTION\t\t\tDEPOSIT\t     CHECK\t\tBALANCE\n");
	printf(       "-----------\t\t\t-------\t     -----\t\t-------\n");
	fprintf(csis, "TRANSACTION\t\tDEPOSIT\t     CHECK\t   BALANCE\n");
	fprintf(csis, "-----------\t\t-------\t     -----\t   -------\n");
}

void initialBalance(double amount, double *balance, double *service, double *openBalance) {
        *balance = *balance + amount;
        *service = *service + 3.0;
        *openBalance = amount;
        printf(       "Initial Balance\t\t\t\t\t\t\t%11.2f\n", *balance);
        fprintf(csis, "Initial Balance\t\t\t\t\t%10.2f\n", *balance);
}

void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit) {
    *balance += amount;
    *numDeposit = *numDeposit + 1;
    *amtDeposit = *amtDeposit + amount;
    *service = *service + 0.03;
    printf(       "Deposit\t\t     %10.2f\t\t\t     %10.2f\n", amount, *balance);
    fprintf(csis, "Deposit\t\t     %10.2f\t\t\t%10.2f\n", amount, *balance);
}

void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck) {
    *balance = *balance - amount;
    *numCheck = *numCheck +1;
    *amtCheck = *amtCheck + amount;
    *service = *service + 0.06;
    printf(       "Check\t\t\t\t\t\t%10.2f   %10.2f\n", amount, *balance);
    fprintf(csis, "Check\t\t\t\t%10.2f\t%10.2f\n", amount, *balance);
    if (*balance < 0)
        *service = *service + 5;
}
    
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance) {
    printf("\n\n");
	printf("Total number deposits: %8d\n", numDeposit);
	printf("Total amount deposits: %8.2f\n", amtDeposit);
	printf("  Total number checks: %8d\n", numCheck);
	printf("  Total amount checks: %8.2f\n", amtCheck);
	printf("\n");
	printf("      Opening balance: %8.2f\n", openBalance);
	printf(" Total service charge: %8.2f\n", service);
	printf("      Closing balance: %8.2f\n", closeBalance);
	
	fprintf(csis, "\n\n");
	fprintf(csis, "Total number deposits: %8d\n", numDeposit);
	fprintf(csis, "Total amount deposits: %8.2f\n", amtDeposit);
	fprintf(csis, "  Total number checks: %8d\n", numCheck);
	fprintf(csis, "  Total amount checks: %8.2f\n", amtCheck);
	fprintf(csis, "\n");
	fprintf(csis, "      Opening balance: %8.2f\n", openBalance);
	fprintf(csis, " Total service charge: %8.2f\n", service);
	fprintf(csis, "      Closing balance: %8.2f\n", closeBalance);    
}

