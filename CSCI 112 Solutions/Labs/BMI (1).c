// bmi.c

// #define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>

FILE *csis;

void calculateBMI(void);

int main (void) {
    csis = fopen("csis.txt", "w");
    for (int i = 1; i <= 4; ++i)
        calculateBMI();
    fclose(csis);
    return 0;
}

void calculateBMI(void) {
    double weight, height, bmi;
    
    printf("Enter weight in pounds and height in inches: ");
    scanf("%lf %lf", &weight, &height);
    fprintf(csis, "Enter weight in pounds and height in inches: : %.1lf %.1lf\n", weight, height);
    
    bmi = (weight * 703) / (height * height);
    printf(       "BMI = %.1lf", bmi);  
    fprintf(csis, "BMI = %.1lf", bmi);  
    
    if (bmi < 18.5) {
        printf(       " Underweight");
        fprintf(csis, " Underweight");
    }            
    else if (bmi < 24.9) {
        printf(       " Normal");
        fprintf(csis, " Normal");
    }
    else if (bmi < 29.9) {
        printf(       " Overweight");
        fprintf(csis, " Overweight");
    }
    else {
        printf(       " Obese");
        fprintf(csis, " Obese");
    }
    printf("\n\n");
    fprintf(csis, "\n\n");
}
