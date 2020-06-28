// weight.c

#include <stdio.h>

FILE *csis;

#define MERCURY 0.378
#define VENUS   0.907
#define MARS    0.377
#define JUPITER 2.360
#define SATURN  0.916
#define URANUS  0.889
#define NEPTUNE 1.120

int main(void) {
	csis = fopen("csis.txt", "w");
    
    printf(       "%10s:%7.1f\n", "MERCURY", 200*MERCURY);
    printf(       "%10s:%7.1f\n", "VENUS",   200*VENUS);
    printf(       "%10s:%7.1f\n", "MARS",    200*MARS);
    printf(       "%10s:%7.1f\n", "JUPITER", 200*JUPITER);
    printf(       "%10s:%7.1f\n", "SATURN",  200*SATURN);
    printf(       "%10s:%7.1f\n", "URANUS",  200*URANUS);
    printf(       "%10s:%7.1f\n", "NEPTUNE", 200*NEPTUNE);
    fprintf(csis, "%10s:%7.1f\n", "MERCURY", 200*MERCURY);
    fprintf(csis, "%10s:%7.1f\n", "VENUS",   200*VENUS);
    fprintf(csis, "%10s:%7.1f\n", "MARS",    200*MARS);
    fprintf(csis, "%10s:%7.1f\n", "JUPITER", 200*JUPITER);
    fprintf(csis, "%10s:%7.1f\n", "SATURN",  200*SATURN);
    fprintf(csis, "%10s:%7.1f\n", "URANUS",  200*URANUS);
    fprintf(csis, "%10s:%7.1f\n", "NEPTUNE", 200*NEPTUNE);
    
    fclose(csis);
	return 0;
}
