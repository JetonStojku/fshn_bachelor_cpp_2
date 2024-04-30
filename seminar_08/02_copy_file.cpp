#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void printFile(char *fileName);
void copyFile(char *fileName, char *extension);
void createFileUppercase(char *fileName, char *extension);
int main()
{
	// INFO: char fileName[]="leksion.txt";
	char *fileName;
	fileName = (char *)malloc(sizeof(char *));
	fprintf(stdout, "File: ");
	fscanf(stdin, "%s", fileName);
	createFileUppercase(fileName, ".txt");
	printFile(strcat(fileName, "_copy.txt"));
	printf("\n");

	return 0;
}
void createFileUppercase(char *fileName, char *extension)
{
	char *copyFileName, *originalFileName;
	copyFileName = (char *)malloc(sizeof(char *));
	originalFileName = (char *)malloc(sizeof(char *));
	strcpy(originalFileName, fileName);
	strcpy(copyFileName, fileName);
	strcat(copyFileName, "_copy");
	strcat(copyFileName, extension);
	strcat(originalFileName, extension);
	FILE *sk, *skKopje;
	skKopje = fopen(copyFileName, "w");
	sk = fopen(originalFileName, "r");
	if (sk == NULL || skKopje == NULL)
	{
		printf("One of the files cannot be opened!\n");
		return;
	}
	char g;
	while ((g = getc(sk)) != EOF)
	{
		fprintf(skKopje, "%c", toupper(g));
	}

	fclose(sk);
	fclose(skKopje);
}
void copyFile(char *fileName, char *extension)
{
	char *copyFileName, *originalFileName;
	copyFileName = (char *)malloc(sizeof(char *));
	originalFileName = (char *)malloc(sizeof(char *));
	strcpy(originalFileName, fileName);
	strcpy(copyFileName, fileName);
	strcat(copyFileName, "_copy");
	strcat(copyFileName, extension);
	strcat(originalFileName, extension);
	FILE *sk, *copyFile;
	copyFile = fopen(copyFileName, "w");
	sk = fopen(originalFileName, "r");
	if (sk == NULL || copyFile == NULL)
	{
		printf("One of the files cannot be opened!\n");
		return;
	}
	char g;
	while ((g = getc(sk)) != EOF)
	{
		fprintf(copyFile, "%c", g);
	}

	fclose(sk);
	fclose(copyFile);
}

void printFile(char *fileName)
{
	FILE *sk;
	sk = fopen(fileName, "r");
	if (sk == NULL)
	{
		printf("The file cannot be opened!\n");
		return;
	}
	char g;
	while ((g = getc(sk)) != EOF)
	{
		printf("%c", g);
		// sleep(1);
	}
	fclose(sk);
}
