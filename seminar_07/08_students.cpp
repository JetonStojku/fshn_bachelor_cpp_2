#include <stdio.h>
#include <stdlib.h>
#define M 20
#define N 30

typedef struct
{
	char *name;
	char gender;
	int grades[N];
} student;

typedef struct
{
	char *name;
	char category;
	int credits;
} subject;

void readGrades(subject L[], int dim);
void readStudents(student S[], int dim, subject L[], int dim2);
void getAverage(student S[], int dim, subject L[], int dim2);
int main()
{
	int m, n;
	printf("Set the number of students: ");
	scanf("%d", &m);
	printf("Set the number of subjects: ");
	scanf("%d", &n);

	subject Sub[N];
	student St[M];
	readGrades(Sub, n);
	readStudents(St, m, Sub, n);
	getAverage(St, m, Sub, n);
	return 0;
}
void getAverage(student S[], int dim, subject L[], int dim2)
{
	int Skr = 0;
	for (int j = 0; j < dim2; j++)
	{
		if (L[j].category == 'V')
		{
			Skr = Skr + L[j].credits;
		}
	}

	if (Skr == 0)
	{
		printf("The average cannot be calculated. No crafts subjects\n");
		return;
	}

	for (int i = 0; i < dim; i++)
	{
		int sh = 0;
		for (int j = 0; j < dim2; j++)
		{
			if (L[j].category == 'V')
			{
				sh = sh + S[i].grades[j] * L[j].credits;
			}
		}

		float average = 1.0 * sh / Skr;
		printf("%s has an average %.1f.\n", S[i].name, average);
	}
}
void readStudents(student S[], int dim, subject L[], int dim2)
{
	printf("Set the details of %d student's.\n", dim);
	for (int i = 0; i < dim; i++)
	{
		printf("Student %d\n", i + 1);
		S[i].name = (char *)malloc(sizeof(char *));
		printf("\tName: ");
		scanf("%s", S[i].name);
		printf("\tGender: ");
		scanf(" %c", &S[i].gender);
		for (int j = 0; j < dim2; j++)
		{
			printf("\t%s: ", L[j].name);
			scanf("%d", &S[i].grades[j]);
		}
	}
}
void readGrades(subject L[], int dim)
{
	printf("Set the details of %d subject's.\n", dim);
	for (int j = 0; j < dim; j++)
	{
		printf("Subject %d\n", j + 1);
		L[j].name = (char *)malloc(sizeof(char *));
		printf("\tSubject: ");
		scanf("%s", L[j].name);
		printf("\tCategory: ");
		scanf(" %c", &L[j].category);
		printf("\tCredits: ");
		scanf("%d", &L[j].credits);
	}
}
