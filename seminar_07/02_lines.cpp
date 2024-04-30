#include <stdio.h>
#include <math.h>
#define pi 3.14
#define nmax 5

typedef struct
{
	int x;
	int y;
} point;
typedef struct
{
	point start;
	point end;
	float length;
} line;
float lengthFromValues(int x1, int y1, int x2, int y2);
float lengthFromPoints(point pk1, point pk2);
float lineLength(line line);
void setLineLength(line *line);
int main()
{
	point p1, p2;
	line v;

	printf("Input coordinates of first point: ");
	scanf("%d%d", &p1.x, &p1.y);
	printf("Input coordinates of second point: ");
	scanf("%d%d", &p2.x, &p2.y);
	v.start = p1;
	v.end = p2;
	setLineLength(&v);
	printf("Length of line with coordinates (%d,%d) and (%d,%d) is %.2f\n", v.start.x, v.start.y, v.end.x, v.end.y, v.length);

	return 0;
}
float lengthFromValues(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
float lengthFromPoints(point pk1, point pk2)
{
	return sqrt(pow(pk1.x - pk2.x, 2) + pow(pk1.y - pk2.y, 2));
}
float lineLength(line line)
{
	return sqrt(pow(line.start.x - line.end.x, 2) + pow(line.start.y - line.end.y, 2));
}

void setLineLength(line *line)
{
	(*line).length = lineLength(*line);
}
