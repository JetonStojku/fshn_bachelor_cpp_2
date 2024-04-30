#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct
{
	char *name;
	char surname[20];
	char gender;
	char age;
} person;

void read(person Person[], int dim);
void display(person Person[], int dim);
void orderPersons(person Person[], int dim);

int main()
{
	person P[N];
	int n;
	printf("Set the number of persons: ");
	scanf("%d", &n);
	read(P, n);
	orderPersons(P, n);
	display(P, n);

	char *names[N];
	char *surnames[N];
	char genders[N];
	int ages[N];

	n = 3;
	for (int i = 0; i < n; i++)
	{
		printf("Set person %d details (name, surname, gender, age):\n", i + 1);
		names[i] = (char *)malloc(sizeof(char *));
		scanf("%s", names[i]);
		surnames[i] = (char *)malloc(sizeof(char *));
		scanf("%s", surnames[i]);
		scanf(" %c", &genders[i]);
		scanf("%d", ages[i]);
	}

	return 0;
}
void orderPersons(person Person[], int dim)
{
	for (int i = 0; i < dim - 1; i++)
	{
		for (int j = i + 1; j < dim; j++)
		{
			if (Person[i].age > Person[j].age)
			{
				person tmp = Person[i];
				Person[i] = Person[j];
				Person[j] = tmp;
			}
		}
	}
}
void read(person Person[], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		printf("Set person %d details (name, surname, gender, age):\n", i + 1);
		Person[i].name = (char *)malloc(sizeof(char *));
		scanf("%s", Person[i].name);
		scanf("%s", Person[i].surname);
		scanf(" %c", &Person[i].gender);
		scanf("%d", &Person[i].age);
	}
}
void display(person Person[], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		printf("%s %s %c %d\n", Person[i].name, Person[i].surname, Person[i].gender, Person[i].age);
	}
}
