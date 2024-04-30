#include <stdio.h>
#include <math.h>
#define nmax 5
typedef struct
{
	int x;
	int y;
} point;

void getQuadrant(point *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i].x >= 0 && p[i].y >= 0)
		{
			printf("Quadrant 1\n");
		}
		else if (p[i].x <= 0 && p[i].y >= 0)
		{
			printf("Quadrant 2\n");
		}
		else if (p[i].x <= 0 && p[i].y <= 0)
		{
			printf("Quadrant 3\n");
		}
		else
		{
			printf("Quadrant 4\n");
		}
	}
}
int main()
{
	point p[nmax];

	for (int i = 0; i < nmax; i++)
	{
		printf("Input coordinates of point %d: ", i + 1);
		scanf("%d%d", &p[i].x, &p[i].y);
	}

	getQuadrant(p, nmax);

	return 0;
}
