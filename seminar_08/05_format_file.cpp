#include <stdio.h>
#define max 100

typedef struct person
{
	char name[20];
	char surname[20];
	int age;
	char gender;
};
int readValues(FILE *file, person P[]);
void readValues2(FILE *file, person P[], int *dim);
void printValues(person P[], int dim, int limitAge);
int main()
{
	FILE *sk;
	sk = fopen("persons1.txt", "r");
	if (sk == NULL)
	{
		printf("File cannot be opened!\n");
		return 1;
	}
	person P[max];
	int m;

	// m=readValues(sk,P);
	readValues2(sk, P, &m);
	fclose(sk);
	printValues(P, m, 21);

	printf("Program finished! Press any key...\n");
	scanf("%d");
	return 0;
}
int readValues(FILE *file, person P[])
{
	int i = 0;
	/*
	while(fscanf(file,"%s%s%d %c",P[i].name, P[i].surname, &P[i].age, &P[i].gender)!=EOF){
		i++;
	}
	*/
	while (fscanf(file, "%s", P[i].name) != EOF)
	{
		// fscanf(file,"%s%d %c", P[i].surname, &P[i].age, &P[i].gender);
		fscanf(file, "%s", P[i].surname);
		fscanf(file, "%d", &P[i].age);
		fscanf(file, " %c", &P[i].gender);
		i++;
	}
	return i;
}

void readValues2(FILE *file, person P[], int *dim)
{
	int i = 0;
	/*
	while(fscanf(file,"%s%s%d %c",P[i].name, P[i].surname, &P[i].age, &P[i].gender)!=EOF){
		i++;
	}
	*/
	while (fscanf(file, "%s", P[i].name) != EOF)
	{
		// fscanf(file,"%s%d %c", P[i].surname, &P[i].age, &P[i].gender);
		fscanf(file, "%s", P[i].surname);
		fscanf(file, "%d", &P[i].age);
		fscanf(file, " %c", &P[i].gender);
		i++;
	}
	*dim = i;
}
void printValues(person P[], int dim, int limitAge)
{
	FILE *newFile;
	newFile = fopen("printPersons.txt", "w");
	if (newFile == NULL)
	{
		printf("File cannot be opened!\n");
		return;
	}
	for (int i = 0; i < dim; i++)
	{
		if (P[i].age > limitAge)
		{
			fprintf(newFile, "%s %s %d %c\n", P[i].name, P[i].surname, P[i].age, P[i].gender);
		}
	}
	fclose(newFile);
}
