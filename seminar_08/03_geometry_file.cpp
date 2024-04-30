#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
	FILE *sk;
	char *file_name;
	file_name = (char *)malloc(sizeof(char *));
	char *file_number;
	file_number = (char *)malloc(sizeof(char *));

	printf("Set file name:  ");
	scanf("%s", file_name);
	// strcat(file_name,".txt");
	int n;
	printf("Set number of lines: ");
	scanf("%d", &n);

	strcat(file_name, "_");
	sprintf(file_number, "%d", n);
	strcat(file_name, file_number);
	strcat(file_name, ".txt");

	char g;
	sk = fopen(file_name, "w");
	if (sk == NULL)
	{
		printf("File cannot be opened!\n");
		return 0;
	}

	int nr_hap = n - 1;
	int nr_yje = 1;
	for (int i = 1; i <= n; i++)
	{
		// write spaces
		for (int j = 1; j <= nr_hap; j++)
			fprintf(sk, "\t");
		for (int j = 1; j <= nr_yje; j++)
			fprintf(sk, "*\t");
		nr_hap--;
		nr_yje = nr_yje + 2;
		fprintf(sk, "\n");
	}
	fclose(sk);
	printf("\nFile created!\n");
	getch();
	return 0;
}
