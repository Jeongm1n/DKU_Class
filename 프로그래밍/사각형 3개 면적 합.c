#include <stdio.h>

typedef struct rect
{
	int x1, y1;
	int x2, y2;
}RECT;

int SumArea(RECT *rectarr, int n);

int main()
{
	RECT rec[3];
	int i, j;

	for (i = 0; i<3; i++)
	{
		printf(" %d 번째를 입력하세요 : ", i + 1);
		scanf("%d %d %d %d", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2);
	}

	printf("면적의 합은 : %d 입니다", SumArea(rec, 3));


	return 0;
}
int SumArea(RECT *rectarr, int n)
{

	int sum = 0, i, temp;

	for (i = 0; i<n; i++)
	{
		temp = (rectarr[i].x2 - rectarr[i].x1)*(rectarr[i].y2 - rectarr[i].y1);
		if (temp<0)
			temp = -temp;
		printf("%d ", temp);

		sum = sum + temp;
	}
	return sum;
}