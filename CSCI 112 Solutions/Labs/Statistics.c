// statistics.c

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

FILE *fp;

void outputScores(int scores[MAX]);
void insertionSort(int list[MAX], int max);
void getFrequency(int scores[MAX], int freq[101]);
void passFail(int scores[MAX]);
void calcMean(int scores[MAX]);
void calcMode(int freq[101]);
void calcMedian(int scores[MAX]);

int main(void) {
    int scores[MAX] = {
        90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95,
        80, 100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65
    };
    int freq[101];
    
    if (!(fp = fopen("csis", "w"))) {
        printf("File could not be opened for input.\n");
        exit(1);
    }
    printf(     "Raw Scores\n");
    printf(     "----------");
    fprintf(fp, "Raw Scores\n");
    fprintf(fp, "----------");
    outputScores(scores);
    insertionSort(scores, MAX);
    printf(     "Sorted Scores\n");
    printf(     "-------------");
    fprintf(fp, "Sorted Scores\n");
    fprintf(fp, "-------------");
    outputScores(scores);
    getFrequency(scores, freq);
    passFail(scores);
    calcMean(scores);
    calcMode(freq);
    calcMedian(scores);
    fclose(fp);
    return 0;
}

void outputScores(int scores[MAX]) {
    for (int i=0; i < MAX; ++i) {
        if (i % 5 == 0) {
            printf(     "\n");
            fprintf(fp, "\n");
        }
        printf(     "%3d  ", scores[i]);
        fprintf(fp, "%3d  ", scores[i]);
    }
    printf(     "\n\n");
    fprintf(fp, "\n\n");
}

void insertionSort(int list[MAX], int max) {
    int i, j, temp;
    
    for (i = 1; i < max; i++) {
        temp = list[i];
        j = i - 1;
        while (j >= 0 && temp < list[j]) {
            list[j+1] = list[j];
            j = j - 1;
        }
        list[j+1] = temp;
    }
}

void getFrequency(int scores[MAX], int freq[101]) {
    int i;
    
    for (i=0; i <= 100; ++i)
        freq[i] = 0;
    for (i=0; i < MAX; ++i)
        ++freq[scores[i]];
    printf(     "Value  Frequency\n");
    printf(     "-----  ---------\n");
    fprintf(fp, "Value  Frequency\n");
    fprintf(fp, "-----  ---------\n");
    for (i=100; i >= 0; --i)
        if (freq[i] != 0) {
            printf(     "%4d   %5d\n", i, freq[i]);
            fprintf(fp, "%4d   %5d\n", i, freq[i]);
        }
    printf("\n");
    fprintf(fp, "\n");
}

void passFail(int scores[MAX]) {
    int pass=0;
    int fail=0;
    printf(     "Pass-Fail Percentage\n");
    printf(     "--------------------\n");
    fprintf(fp, "Pass-Fail Percentage\n");
    fprintf(fp, "--------------------\n");
    
    for (int i=0; i < MAX; ++i)
        scores[i] >= 60 ? ++pass : ++fail;
    printf(     "Pass = %5.1f\n", (float)pass/MAX*100.0);
    printf(     "Fail = %5.1f\n", (float)fail/MAX*100.0);
    printf(     "\n");
    fprintf(fp, "Pass = %5.1f\n", (float)pass/MAX*100.0);
    fprintf(fp, "Fail = %5.1f\n", (float)fail/MAX*100.0);
    fprintf(fp, "\n");
}

void calcMean(int scores[MAX]) {
    int sum=0;
    
    for (int i=0; i < MAX; ++i)
        sum += scores[i];
    printf(     "Mean = %5.1f\n\n", (float)sum/MAX);
    fprintf(fp, "Mean = %5.1f\n\n", (float)sum/MAX);
}

void calcMode(int freq[101]) {
    int largestIndex = 0;
    
    for (int i=1; i<101; ++i)
        if (freq[i] > freq[largestIndex])
            largestIndex = i;
    printf(     "Mode = %3d\n\n", largestIndex);
    fprintf(fp, "Mode = %3d\n\n", largestIndex);
}

void calcMedian(int scores[MAX]) {
    float median;
    
    if (MAX % 2 != 0)
        median = (float)scores[MAX/2];
    else {
        
        median = (float)(scores[MAX/2] + scores[MAX/2 - 1])/2.0;
    }
    printf(     "Median = %5.1f\n\n", median);
    fprintf(fp, "Median = %5.1f\n\n", median);
}



