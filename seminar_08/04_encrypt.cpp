#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int encryptAlgorithm(int key)
{
	return 3 * pow(key, 3) + 2 * pow(key, 2) + 18;
}
void encrypt(const char *name, int key)
{
	FILE *sk, *sk2;
	char *name1 = (char *)malloc(sizeof(char *));
	char *name2 = (char *)malloc(sizeof(char *));
	name1 = strcpy(name1, name);
	name2 = strcpy(name2, name);
	strcat(name1, ".txt");
	strcat(name2, "_encrypt.txt");
	sk = fopen(name1, "r");
	if (sk == NULL)
	{
		printf("File cannot be opened!\n");
		return;
	}

	sk2 = fopen(name2, "w");
	if (sk2 == NULL)
	{
		printf("Error in creating encrypt file!\n");
		return;
	}
	int moveValue = encryptAlgorithm(key);
	char g;
	while ((g = getc(sk)) != EOF)
	{
		g = (g + moveValue) % 256;
		fprintf(sk2, "%c", g);
	}
	fclose(sk);
	fclose(sk2);
}
void printOriginal(char *name, int key)
{
	FILE *sk;
	char *name1 = (char *)malloc(sizeof(char *));
	strcpy(name1, name);
	strcat(name1, "_encrypt.txt");
	sk = fopen(name1, "r");
	if (sk == NULL)
	{
		printf("File cannot be opened!\n");
		return;
	}
	int moveValue = encryptAlgorithm(key);
	char g;
	while ((g = getc(sk)) != EOF)
	{
		g = (256 + g - moveValue) % 256;
		printf("%c", g);
	}
	fclose(sk);
}
void printEncrypt(char *name)
{
	FILE *sk;
	char *name1 = (char *)malloc(sizeof(char *));
	strcpy(name1, name);
	strcat(name1, "_encrypt.txt");
	sk = fopen(name1, "r");
	if (sk == NULL)
	{
		printf("File cannot be opened!\n");
		return;
	}
	char g;
	while ((g = getc(sk)) != EOF)
	{
		printf("%c", g);
	}
	fclose(sk);
}
int main()
{
	char *name = (char *)malloc(sizeof(char *));
	printf("File: ");
	scanf("%s", name);
	// Function will create a new file with encrypted data
	encrypt(name, 3);
	printEncrypt(name);
	printf("\n");
	// Function will read the encrypted file and print the original message
	printOriginal(name, 3);

	return 0;
}
