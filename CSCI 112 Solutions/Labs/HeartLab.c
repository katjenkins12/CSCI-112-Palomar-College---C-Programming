// heart.c

#include <stdio.h>

FILE *csis;

int main(void) {
	long sec, min, hr, day, yr, beats;
	
	csis = fopen("csis.txt", "w");
	sec = 60;
	min = 60;
	hr = 24;
	day = 365;
	yr = 50;
	beats = sec * min * hr * day * yr;
	printf("There are %ld heartbeats in 50 years.\n", beats);
	fprintf(csis, "There are %ld heartbeats in 50 years.\n", beats);
	fclose(csis);
	return 0;
}
