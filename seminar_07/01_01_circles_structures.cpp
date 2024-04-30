#include <stdio.h>
#include <math.h>
#define pi 3.14
#define nmax 5
int main()
{

	typedef struct circle
	{
		int x;
		int y;
		int radius;
	};
	circle rr;

	printf("Input center of circle coordinates: ");
	scanf("%d%d", &rr.x, &rr.y);
	printf("Input radius: ");
	scanf("%d", &rr.radius);

	float sip = 1.0 * pi * pow(rr.radius, 2);

	printf("Square of circle with center (%d,%d) and radius %d is %.2f\n", rr.x, rr.y, rr.radius, sip);

	return 0;
}
