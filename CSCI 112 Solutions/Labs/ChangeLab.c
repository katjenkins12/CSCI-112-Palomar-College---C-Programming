// change.c

#include <stdio.h>

FILE *csis;

int main(void) {
	double cost, payment;
	int twenty, ten, five, one, quarter, dime, nickel, penny, change;
	
	csis = fopen("csis.txt", "w");
	
	cost = 21.17;
	payment = 100;
	change = (int)((payment - cost) * 100);
	
	twenty = change / 2000;
	change %= 2000;
	
	ten = change / 1000;
	change %= 1000;
	
	five = change / 500;
	change %= 500;
	
	one = change / 100;
	change %= 100;
	
	quarter = change / 25;
	change %= 25;
	
	dime = change / 10;
	change %= 10;
	
	nickel = change / 5;
	change %= 5;
	
	penny = change;
	
	printf("    Cost: %6.2f\n", cost);
	printf("Tendered: %6.2f\n", payment);
	printf("----------------\n");
	printf("  Twenty: %d\n", twenty);
	printf("     Ten: %d\n", ten);
	printf("    Five: %d\n", five);
	printf("     One: %d\n", one);
	printf(" Quarter: %d\n", quarter);
	printf("    Dime: %d\n", dime);
	printf("  Nickel: %d\n", nickel);
	printf("   Penny: %d\n", penny);
	
	fprintf(csis, "    Cost: %6.2f\n", cost);
	fprintf(csis, "Tendered: %6.2f\n", payment);
	fprintf(csis, "----------------\n");
	fprintf(csis, "  Twenty: %d\n", twenty);
	fprintf(csis, "     Ten: %d\n", ten);
	fprintf(csis, "    Five: %d\n", five);
	fprintf(csis, "     One: %d\n", one);
	fprintf(csis, " Quarter: %d\n", quarter);
	fprintf(csis, "    Dime: %d\n", dime);
	fprintf(csis, "  Nickel: %d\n", nickel);
	fprintf(csis, "   Penny: %d\n", penny);
	
	fclose(csis);
	return 0;
}
