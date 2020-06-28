#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *fpIn, *fpOut;

void processFile(char buf[]);
void cipher(char buf[]);
void outputCode(char buf[]);

int main(void) {
    char buf[100000];

    processFile(buf);
    cipher(buf);
    outputCode(buf);
    return 0;
}

void processFile(char buf[]) {
    int i, c;
    
    if (!(fpIn = fopen("congress.txt", "r"))) {
        printf("File could not be opened for input.\n");
        exit(1);
    }
    i = 0;
    while((c = getc(fpIn)) != EOF) {
        if (isalpha(c))
            buf[i++] = toupper(c);
    }
    buf[i] = '\0';
    fclose(fpIn);
}

void cipher(char buf[]) {
    int shift = 13;
    int i = 0;
    
    while (buf[i] != '\0') {
        buf[i] = (char) (buf[i] + shift);
        if (buf[i] > 'Z')
            buf[i] = (char) (buf[i]-26);
        i++;
    }
}

void outputCode(char buf[]) {
    int num = 0;
    int i = 0;
    
    if (!(fpOut = fopen("csis", "w"))) {
        printf("File could not be opened for input.\n");
        exit(1);
    }
    while (buf[i] != '\0') {
        putchar(buf[i]);
        fputc(buf[i], fpOut);
        ++i;
        if (++num % 50 == 0) {
            putchar('\n');
            fputc('\n', fpOut);
        }
        else if (num % 5 == 0) {
            putchar(' ');
            fputc(' ', fpOut);
        }
    }
}
