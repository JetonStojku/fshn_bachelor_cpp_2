#include <stdio.h>
#include <stdlib.h>
#define M 100
#define N 1000

typedef struct person
{
	char *name;
	int age;
	char gender;
};

typedef struct student
{
	person personalData;
	char course[20];
};

typedef struct pedagogue
{
	person personalData;
	char degree[10];
};

void readStudent(student S[], int dim);
void readPedagogues(pedagogue P[], int dim);

int main()
{
	student St[M];
	pedagogue Pg[N];
	int m, n;
	printf("Set the number of students: ");
	scanf("%d", &m);
	readStudent(St, m);
	printf("Set the number of pedagogues: ");
	scanf("%d", &n);
	readPedagogues(Pg, n);

	return 0;
}

void readStudent(student S[], int dim)
{
	printf("Set the details of students\n");
	for (int i = 0; i < dim; i++)
	{
		printf("%d\n", i + 1);
		S[i].personalData.name = (char *)malloc(sizeof(char *));
		printf("\tName: ");
		scanf("%s", S[i].personalData.name);
		printf("\tAge: ");
		scanf("%d", &S[i].personalData.age);
		printf("\tGender: ");
		scanf(" %c", &S[i].personalData.gender);
		printf("\tCourse: ");
		scanf("%s", S[i].course);
	}
}

void readPedagogues(pedagogue P[], int dim)
{
	printf("Set the details of pedagogues\n");
	for (int i = 0; i < dim; i++)
	{
		printf("%d\n", i + 1);
		P[i].personalData.name = (char *)malloc(sizeof(char *));
		printf("\tName: ");
		scanf("%s", P[i].personalData.name);
		printf("\tAge: ");
		scanf("%d", &P[i].personalData.age);
		printf("\tGender: ");
		scanf(" %c", &P[i].personalData.gender);
		printf("\tDegree: ");
		scanf("%s", P[i].degree);
	}
}
