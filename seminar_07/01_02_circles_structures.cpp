#include <stdio.h>
#include <math.h>
#define pi 3.14
#define nmax 5
int main()
{
	struct point
	{
		int x;
		int y;
	};
	struct circle
	{
		point center;
		int radius;
	};

	circle rr;
	point center;
	printf("Input center of circle coordinates: ");
	scanf("%d%d", &center.x, &center.y);
	rr.center = center;

	printf("Input radius: ");
	scanf("%d", &rr.radius);

	float sip = 1.0 * pi * pow(rr.radius, 2);

	printf("Square of circle with center (%d,%d) and radius %d is %.2f\n", rr.center.x, rr.center.y, rr.radius, sip);

	return 0;
}
