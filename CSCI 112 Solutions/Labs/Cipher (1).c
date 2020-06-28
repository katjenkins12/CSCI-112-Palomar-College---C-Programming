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

void processFile(char *buf) {
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

void cipher(char *buf) {
    int shift = 13;
    
    while (*buf) {
        *buf = (char) (*buf + shift);
        if (*buf > 'Z')
            *buf = (char) (*buf-26);
        ++buf;
    }
}

void outputCode(char *buf) {
    int i = 0;
    
    if (!(fpOut = fopen("csis", "w"))) {
        printf("File could not be opened for input.\n");
        exit(1);
    }
    while (*buf) {
        putchar(*buf);
        fputc(*buf, fpOut);
        ++buf;
        if (++i % 50 == 0) {
            putchar('\n');
            fputc('\n', fpOut);
        }
        else if (i % 5 == 0) {
            putchar(' ');
            fputc(' ', fpOut);
        }
    }
}
