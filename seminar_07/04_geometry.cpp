#include <stdio.h>
#include <conio.h>

struct cylinder
{
	int x;
	int y;
	int radius;
	int height;
};

struct point
{
	int x;
	int y;
};
struct circle
{
	struct point center;
	int radius;
};

struct cylinder2
{
	struct circle base;
	int hight;
};

struct cone
{
	struct circle base;
	int hight;
};

int main()
{
	struct cylinder c[3];
	for (int i = 0; i < 3; i++)
	{
		printf("Cylinder i %d\n", i + 1);
		printf("Coordinate X: ");
		scanf("%d", &c[i].x);
		printf("Coordinate Y: ");
		scanf("%d", &c[i].y);
		printf("Radius: ");
		scanf("%d", &c[i].radius);
		printf("Height: ");
		scanf("%d", &c[i].height);
	}

	struct cylinder2 cn[3];
	for (int i = 0; i < 3; i++)
	{
		printf("Cylinder i %d\n", i + 1);
		printf("Coordinate X: ");
		scanf("%d", &cn[i].base.center.x);
		printf("Coordinate Y: ");
		scanf("%d", &cn[i].base.center.y);
		printf("Radius: ");
		scanf("%d", &cn[i].base.radius);
		printf("Height: ");
		scanf("%d", &cn[i].hight);
	}

	getch();
	return 0;
}
