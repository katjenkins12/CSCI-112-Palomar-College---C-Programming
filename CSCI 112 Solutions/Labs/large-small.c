//  LargeSmall.c

#include <stdio.h>

FILE *csis;

void compare(void);

int main (void) {
    csis = fopen("csis.txt", "w");
    for (int i = 1; i <= 4; ++i)
        compare();
    fclose(csis);
    return 0;
}

void compare(void) {
    int num1, num2, num3, num4;
    int min1, min2, smallest, largest;
    
    printf("Enter 4 integers: ");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
    fprintf(csis, "Enter 4 integers: %d %d %d %d\n", num1, num2, num3, num4);
    
    if (num1 > num2 && num1 > num3 && num1 > num4)
        largest = num1;
    else if (num2 > num1 && num2 > num3 && num2 > num4)
        largest = num2;
    else if (num3 > num1 && num3 > num2 && num3 > num4)
        largest = num3;
    else largest = num4;
    printf(       "Largest: %d\n", largest);
    fprintf(csis, "Largest: %d\n", largest);
    
    min1 = num1 < num2 ? num1 : num2;
    min2 = num3 < num4 ? num3 : num4;
    smallest = min1 < min2 ? min1 : min2;
    printf(       "Smallest: %d\n\n", smallest);
    fprintf(csis, "Smallest: %d\n\n", smallest);
}
