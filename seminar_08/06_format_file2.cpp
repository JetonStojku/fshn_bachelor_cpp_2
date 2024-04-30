#include <stdio.h>
#define mmax 100
#define nmax 30

typedef struct person
{
	char name[20];
	char surname[20];
	int age;
	char gender;
};
typedef struct student
{
	person credentials;
	// int nrGrades;
	int grades[nmax];
};

void readValues2(FILE *file, student S[], int *dim1, int *dim2);
void printValues(student S[], int dim1, int dim2);
float average(int V[], int dim);
void calcAverage(student S[], float mes[], int dim1, int dim2);
void printAverage(char *fileName, student S[], float mes[], int dim, float minLimit);
void sortAverage(student S[], float mes[], int dim);
int main()
{
	FILE *sk;
	sk = fopen("persons2.txt", "r");
	if (sk == NULL)
	{
		printf("File cannot be opened!\n");
		return 1;
	}
	student St[mmax];
	int m, n;
	readValues2(sk, St, &m, &n);
	fclose(sk);
	float average[mmax];
	calcAverage(St, average, m, n);
	printValues(St, m, n);
	printAverage("averageValues1.txt", St, average, m, 1);
	sortAverage(St, average, m);
	printAverage("averageValues2.txt", St, average, m, 1);
	return 0;
}
float average(int V[], int dim)
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
	{
		sum += V[i];
	}
	return 1.0 * sum / dim;
}
void calcAverage(student S[], float mes[], int dim1, int dim2)
{
	for (int i = 0; i < dim1; i++)
	{
		mes[i] = average(S[i].grades, dim2);
	}
}
void readValues2(FILE *file, student S[], int *dim1, int *dim2 /*, int * dimMax*/)
{
	int i = 0;
	int j;
	// max=0;
	while (fscanf(file, "%s", S[i].credentials.name) != EOF)
	{
		fscanf(file, "%s", S[i].credentials.surname);
		fscanf(file, "%d", &S[i].credentials.age);
		fscanf(file, " %c", &S[i].credentials.gender);
		j = 0;
		while (fscanf(file, "%d", &S[i].grades[j]) == 1)
		{
			j++;
		}
		// S[i].nrGrades=j;

		/*if(j>max){
			max=j;
		}
		*/
		i++;
	}
	//*dimMax=max;
	*dim2 = j;
	*dim1 = i;
}
void printValues(student S[], int dim1, int dim2)
{
	FILE *skRi;
	skRi = fopen("printPersons.txt", "w");
	if (skRi == NULL)
	{
		printf("File cannot be opened!\n");
		return;
	}
	for (int i = 0; i < dim1; i++)
	{
		fprintf(skRi, "%s %s %d %c ", S[i].credentials.name, S[i].credentials.surname, S[i].credentials.age, S[i].credentials.gender);
		for (int j = 0; j < dim2; j++)
		{
			fprintf(skRi, "%d ", S[i].grades[j]);
		}
		fprintf(skRi, "\n");
	}
	fclose(skRi);
}
void printAverage(char *fileName, student S[], float mes[], int dim, float minLimit)
{
	FILE *newFile;
	newFile = fopen(fileName, "w");
	if (newFile == NULL)
	{
		printf("File cannot be opened!\n");
		return;
	}
	for (int i = 0; i < dim; i++)
	{
		if (mes[i] >= minLimit)
		{
			fprintf(newFile, "%s %s %d %c --->%.1f\n", S[i].credentials.name, S[i].credentials.surname, S[i].credentials.age, S[i].credentials.gender, mes[i]);
		}
	}
	fclose(newFile);
}
void sortAverage(student S[], float mes[], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = i + 1; j < dim; j++)
		{
			if (mes[i] < mes[j])
			{
				float tmp = mes[i];
				mes[i] = mes[j];
				mes[j] = tmp;
				student tmpSt = S[i];
				S[i] = S[j];
				S[j] = tmpSt;
			}
		}
	}
}
