//database.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

FILE *csis;

typedef struct {
	char   first[8];
	char   initial[2];
	char   last[10];
	char   street[17];
	char   city[12];
	char   state[3];
	char   zip[6];
	int    age;
	char   sex[2];
	int    tenure;
	double salary;
} Employee;

int main(void);
int    inputData(Employee workers[]);
void   outputData(Employee workers[], int num);
void   menOnPayroll(Employee workers[], int num);
void   highWoman(Employee workers[], int num);
void   lowMan(Employee workers[], int num);
double avgSalary(Employee workers[], int num);
void   womenLessAvg(Employee workers[], int num, double avg);
void   menRatio(Employee workers[], int num, double avg);
void   bigMoney(Employee workers[], int num);
void   raise(Employee workers[], int num);
void   outNameSalary(Employee workers[], int num);
void   insertionSort(Employee workers[], int num);
void   outZipName(Employee workers[], int num);
void  strsub(char *buf, char *s, int start, int end);

int main(void) {
	Employee workers[MAX];
	int num;
	double avg;
	
	csis = fopen("csis.txt", "w");
	if (csis == NULL) {
		puts("File csis.txt could not be opened for output.");
		exit(1);
	}
	num = inputData(workers);
	outputData(workers, num);
	menOnPayroll(workers, num);
	highWoman(workers, num);
	lowMan(workers, num);
	avg = avgSalary(workers, num);
	womenLessAvg(workers, num, avg);
	menRatio(workers, num, avg);
	bigMoney(workers, num);
	raise(workers, num);
	outZipName(workers, num);
	
	system("pause");
	fclose(csis);
	return 0;
}

int inputData(Employee workers[]) {
	int i=0;
	char buf[MAX];
	char temp[MAX];
	FILE *fp;
	
	fp = fopen("payfile.txt", "r");
	if (fp == NULL) {
		puts("File patfile.txt could not be opened for input.");
		exit(1);
	}
	while (!feof(fp)) {
		fgets(buf, MAX, fp);
		strsub(buf, workers[i].first, 0, 6);
		strsub(buf, workers[i].initial, 8, 8);
		strsub(buf, workers[i].last, 10, 18);
		strsub(buf, workers[i].street, 20, 35);
		strsub(buf, workers[i].city, 37, 47);
		strsub(buf, workers[i].state, 49, 50);
		strsub(buf, workers[i].zip, 52, 56);
		strsub(buf, temp, 58, 59);
		workers[i].age = atoi(temp);
		strsub(buf, workers[i].sex, 61, 61);
		strsub(buf, temp, 63, 63);
		workers[i].tenure = atoi(temp);
		strsub(buf, temp, 65, 70);
		workers[i].salary = atof(temp);
		++i;
	}
	fclose(fp);
	return i;
}

void outputData(Employee workers[], int num) {
	int i;
	
	printf("\nOUTPUT DATA\n");
	printf("-----------\n");
	fprintf(csis, "\nOUTPUT DATA\n");
	fprintf(csis, "-----------\n");
	for(i=0; i<num; i++) {
		printf("%s ", workers[i].first);
		printf("%s ", workers[i].initial);
		printf("%s ", workers[i].last);
		printf("%s ", workers[i].street);
		printf("%s ", workers[i].city);
		printf("%s ", workers[i].state);
		printf("%s ", workers[i].zip);
		printf("%d ", workers[i].age);
		printf("%s ", workers[i].sex);
		printf("%d ", workers[i].tenure);
		printf("%6.2f\n", workers[i].salary);
		fprintf(csis, "%s ", workers[i].first);
		fprintf(csis, "%s ", workers[i].initial);
		fprintf(csis, "%s ", workers[i].last);
		fprintf(csis, "%s ", workers[i].street);
		fprintf(csis, "%s ", workers[i].city);
		fprintf(csis, "%s ", workers[i].state);
		fprintf(csis, "%s ", workers[i].zip);
		fprintf(csis, "%d ", workers[i].age);
		fprintf(csis, "%s ", workers[i].sex);
		fprintf(csis, "%d ", workers[i].tenure);
		fprintf(csis, "%6.2f\n", workers[i].salary);
	}
}

void menOnPayroll(Employee workers[], int num) {
	int i;
	
	printf("\nMEN ON PAYROLL");
	printf("\n--------------\n");
	fprintf(csis, "\nMEN ON PAYROLL");
	fprintf(csis, "\n--------------\n");
	for (i=0; i<num; i++)
		if (!strcmp(workers[i].sex, "M")) {
			printf("%s %s\n", workers[i].first, workers[i].last);
			fprintf(csis, "%s %s\n", workers[i].first, workers[i].last);
		}
}

void highWoman(Employee workers[], int num) {
	int i, high;
	double wage=0.0;
	
	printf("\nHIGHEST PAID WOMAN");
	printf("\n------------------\n");
	fprintf(csis, "\nHIGHEST PAID WOMAN");
	fprintf(csis, "\n------------------\n");
	for (i=0; i<num; i++)
		if (!strcmp(workers[i].sex, "F") && workers[i].salary > wage) {
			high = i;
			wage = workers[i].salary;
		}
	printf("%s %s\n", workers[high].first, workers[high].last);
	fprintf(csis, "%s %s\n", workers[high].first, workers[high].last);
}

void lowMan(Employee workers[], int num) {
	int i, low=0;
	double wage;
	
	printf("\nLOWEST PAID MAN");
	printf("\n---------------\n");
	fprintf(csis, "\nLOWEST PAID MAN");
	fprintf(csis, "\n---------------\n");
	wage = workers[0].salary;
	for (i=1; i<num; i++)
		if (!strcmp(workers[i].sex, "M") && workers[i].salary < wage) {
			low = i;
			wage = workers[i].salary;
		}
	printf("%s %s\n", workers[low].first, workers[low].last);
	fprintf(csis, "%s %s\n", workers[low].first, workers[low].last);
}

double avgSalary(Employee workers[], int num) {
	int i;
	double sum=0.0, avg=0.0;
	
	printf("\nAVERAGE SALARY");
	printf("\n--------------\n");
	fprintf(csis, "\nAVERAGE SALARY");
	fprintf(csis, "\n--------------\n");
	for (i=0; i<num; i++)
		sum += workers[i].salary;
	avg = sum / num;
	printf("$%6.2f\n", avg);
	fprintf(csis, "$%6.2f\n", avg);
	return avg;
}

void womenLessAvg(Employee workers[], int num, double avg) {
	int i;
	
	printf("\nWOMAN LESS THAN AVERAGE SALARY");
	printf("\n------------------------------\n");
	fprintf(csis, "\nWOMAN LESS THAN AVERAGE SALARY");
	fprintf(csis, "\n------------------------------\n");
	for (i=0; i<num; i++)
		if (!strcmp(workers[i].sex, "F") && workers[i].salary < avg) {
			printf("%s %s\n", workers[i].first, workers[i].last);
			fprintf(csis, "%s %s\n", workers[i].first, workers[i].last);
		}
}

void menRatio(Employee workers[], int num, double avg) {
	int i, above=0, below=0;
	
	printf("\nRATIO OF MEN BELOW AND ABOVE AVERAGE SALARY");
	printf("\n-------------------------------------------\n");
	fprintf(csis, "\nRATIO OF MEN BELOW AND ABOVE AVERAGE SALARY");
	fprintf(csis, "\n-------------------------------------------\n");
	for (i=0; i<num; i++)
		if (!strcmp(workers[i].sex, "M") && workers[i].salary < avg)
			below++;
		else if (!strcmp(workers[i].sex, "M") && workers[i].salary > avg)
			above++;
	printf("%6.3f\n", (double)above/below);
	fprintf(csis, "%6.3f\n", (double)above/below);
}

void bigMoney(Employee workers[], int num) {
	int i;
	
	printf("\nBIG MONEY");
	printf("\n---------\n");
	fprintf(csis, "\nBIG MONEY");
	fprintf(csis, "\n---------\n");
	for (i=0; i<num; i++)
		if (workers[i].salary*52 > 35000.0 && workers[i].tenure >=5 && workers[i].age > 30) {
			printf("%s %s\n", workers[i].first, workers[i].last);
			fprintf(csis, "%s %s\n", workers[i].first, workers[i].last);
		}
}

void raise(Employee workers[], int num) {
	int i;
	
	printf("\nRAISES");
	printf("\n------\n");
	fprintf(csis, "\nRAISES");
	fprintf(csis, "\n------\n");
	for (i=0; i<num; i++)
		if (workers[i].salary < 350.00) {
			workers[i].salary *= 1.1;
			printf("%s %s %6.2f\n", workers[i].first, workers[i].last, workers[i].salary);
			fprintf(csis, "%s %s %6.2f\n", workers[i].first, workers[i].last, workers[i].salary);
		}
	
}

void outNameSalary(Employee workers[], int num) {
	int i;
	
	printf("\nNAMES AND SALARIES");
	printf("\n------------------\n");
	fprintf(csis, "\nNAMES AND SALARIES");
	fprintf(csis, "\n------------------\n");
	for (i=0; i<num; i++) {
		printf("%s %s %6.2f\n", workers[i].first, workers[i].last, workers[i].salary);
		fprintf(csis, "%s %s %6.2f\n", workers[i].first, workers[i].last, workers[i].salary);
	}
}

void insertionSort(Employee workers[], int max) {
	int i, j;
	Employee temp;
	
	for (i = 1; i < max; i++)	{
		temp = workers[i];
		j = i - 1;
		while (j >= 0 && strcmp(temp.zip, workers[j].zip) < 0) {
			workers[j+1] = workers[j];
			j--;
		}
		workers[j+1] = temp;
	}
}

void outZipName(Employee workers[], int num) {
	int i;
	
	printf("\nZIP CODES AND NAMES");
	printf("\n-------------------\n");
	fprintf(csis, "\nZIP CODES AND NAMES");
	fprintf(csis, "\n-------------------\n");
	insertionSort(workers, num);
	for (i=0; i<num; i++) {
		printf("%s %s %s\n", workers[i].first, workers[i].last, workers[i].zip);
		fprintf(csis, "%s %s %s\n", workers[i].first, workers[i].last, workers[i].zip);
	}
}

void strsub(char buf[], char sub[], int start, int end) {
	int i, j;
	
	for (j=0, i=start; i<=end; i++, j++)
		sub[j] = buf[i];
	sub[j] = '\0';
}
