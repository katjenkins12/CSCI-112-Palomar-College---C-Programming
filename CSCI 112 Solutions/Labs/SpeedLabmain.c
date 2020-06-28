// speed.c

#include <stdio.h>

FILE *csis;

int main(void) {
	double miles, hours, speedMPH, speedMPS;
	
	csis = fopen("csis.txt", "w");
	miles = 425.5;
	hours = 7.5;
	
	printf("       Miles car travelled = %8.2f\n", miles);
	fprintf(csis, "       Miles car travelled = %8.2f\n", miles);
	printf("       Hours car travelled = %8.2f\n", hours);
	fprintf(csis, "       Hours car travelled = %8.2f\n", hours);
	
	printf("\n");
	fprintf(csis, "\n");
	
	speedMPH = miles / hours;
	printf("   Speed in miles per hour = %8.2f\n", speedMPH);
	fprintf(csis, "   Speed in miles per hour = %8.2f\n", speedMPH);
	
	speedMPS = speedMPH * 1600 / 3600;
	printf("Speed in meters per second = %8.2f\n", speedMPS);
	fprintf(csis, "Speed in meters per second = %8.2f\n", speedMPS);
	
	fclose(csis);
    return 0;
}
