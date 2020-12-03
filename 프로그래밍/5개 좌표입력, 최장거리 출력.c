#include <stdio.h>
#include <math.h>

struct point
{
	int x, y;
}typedef POINT;

struct line
{
	POINT start;
	POINT end;
}

typedef LINE;

int main()
{

	LINE aline[3];
	double len, max, temp;
	int i, n;
	for (i = 0; i<3; i++)
	{
		printf("시작점 : ");
		scanf_s("%d %d", &aline[i].start.x, &aline[i].start.y);

		printf("끝점 : ");
		scanf_s("%d %d", &aline[i].end.x, &aline[i].end.y);
	}


	max = sqrt(pow((double)(aline[0].start.x - aline[0].end.x), 2) + pow((double)(aline[0].start.y - aline[0].end.y), 2));


	for (i = 1; i<3; i++)
	{
		temp = sqrt(pow((double)(aline[i].start.x - aline[i].end.x), 2) + pow((double)(aline[i].start.y - aline[i].end.y), 2));

		if (max<temp)
		{
			max = temp;
		}
	}
	printf("긴 선의 길이 : %.2f", max);
	
	return 0;
}