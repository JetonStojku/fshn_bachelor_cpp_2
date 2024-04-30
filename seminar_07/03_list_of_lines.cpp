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
float lineLength(line line);
void setLineLength(line *line);
void setLineLengthByIndex(line lines[], int index);
int main()
{
	int n = 3;
	point P[n];
	line V[n];
	for (int i = 0; i < n; i++)
	{
		printf("Set coordinates of point %d: ", i + 1);
		scanf("%d%d", &P[i].x, &P[i].y);
	}

	for (int i = 0; i < n; i++)
	{
		V[i].start = P[i];
		V[i].end = P[(i + 1) % n];
		// INFO: All three ways work
		// V[i].length=lineLength(V[i]);
		// setLineLength(&V[i]);
		// setLineLength(V+i);
		setLineLengthByIndex(V, i);
	}

	float perimeter = 0;
	for (int i = 0; i < n; i++)
	{
		printf("Line %d with coordinates (%d,%d) and (%d,%d) has length %.2f\n", i + 1, V[i].start.x, V[i].start.y, V[i].end.x, V[i].end.y, V[i].length);
		perimeter = perimeter + V[i].length;
	}

	printf("Perimeter is %.2f\n", perimeter);

	return 0;
}
float lineLength(line line)
{
	return sqrt(pow(line.start.x - line.end.x, 2) + pow(line.start.y - line.end.y, 2));
}

void setLineLength(line *line)
{
	(*line).length = lineLength(*line);
}
void setLineLengthByIndex(line lines[], int index)
{
	lines[index].length = lineLength(lines[index]);
}
