#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int countChar(char *fileName);
void printFile(char *fileName);
int countLetters(char *fileName);
int countVowel(char *fileName);
int main()
{
	// Example char fileName[]="leksion.txt";
	char *fileName;
	fileName = (char *)malloc(sizeof(char *));
	printf("File: ");
	scanf("%s", fileName);
	strcat(fileName, ".txt");
	printFile(fileName);
	printf("\n");
	printf("The file has %d characters\n", countChar(fileName));
	printf("The file has %d letters\n", countLetters(fileName));
	printf("The file has %d vowels\n", countVowel(fileName));
	return 0;
}
int countVowel(char *fileName)
{
	FILE *sk;
	sk = fopen(fileName, "r");
	if (sk == NULL)
	{
		printf("The file cannot be opened!\n");
		return 0;
	}
	char g;
	int nr = 0;
	while ((g = getc(sk)) != EOF)
	{
		if (tolower(g) == 'a' || tolower(g) == 'e' || tolower(g) == 'i' || tolower(g) == 'o' ||
			tolower(g) == 'u' || tolower(g) == 'w')
			nr++;
	}
	return nr;
}
int countLetters(char *fileName)
{
	FILE *sk;
	sk = fopen(fileName, "r");
	if (sk == NULL)
	{
		printf("The file cannot be opened!\n");
		return 0;
	}
	char g;
	int nr = 0;
	while ((g = getc(sk)) != EOF)
	{
		if (tolower(g) >= 'a' && tolower(g) <= 'z') //(g>='a' && g<='z' || g>='A' && g<='Z')
			nr++;
	}
	return nr;
}
int countChar(char *fileName)
{
	FILE *sk;
	sk = fopen(fileName, "r");
	if (sk == NULL)
	{
		printf("The file cannot be opened!\n");
		return 0;
	}
	char g;
	int nr = 0;
	while ((g = getc(sk)) != EOF)
	{
		nr++;
	}
	return nr;
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
	for (g = getc(sk); g != EOF; g = getc(sk))
	{
		printf("%c", g);
		// sleep(1);
	}
	/*M.2
	while((g=getc(sk))!=EOF){
		printf("%c",g);
		sleep(1);
	}
	*/
	/*M.1
	g=getc(sk);
	while(g!=EOF){
		printf("%c",g);
		sleep(1);
		g=getc(sk);
	}
	*/
	fclose(sk);
}
