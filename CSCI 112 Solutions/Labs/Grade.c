// grade.c

#include <stdio.h>

FILE *csis;

void calculateAverage(void);

int main (void) {
    csis = fopen("csis.txt", "w");
    for (int i = 1; i <= 4; ++i)
        calculateAverage();
    fclose(csis);
    return 0;
}

void calculateAverage(void) {
    int grade, count, sum;
    float average;

    count = sum = 0;
    printf("Enter grade: ");
    scanf("%d", &grade);
    fprintf(csis, "Enter grade: %d\n", grade);
    while (grade != -1) {
        sum += grade;
        ++count;
        printf("Enter grade: ");
        scanf("%d", &grade);
        fprintf(csis, "Enter grade: %d\n", grade);
    }
    if (count != 0) {
        average = (float) sum / count;
        printf("The class average is %.2f\n\n", average);
        fprintf(csis, "The class average is %.2f\n\n", average);
    }
    else {
        printf("No grades were entered.\n");
        fprintf(csis, "No grades were entered.\n");
    }
}
