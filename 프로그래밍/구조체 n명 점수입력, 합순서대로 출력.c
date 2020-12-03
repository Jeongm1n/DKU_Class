#include<stdio.h>

struct point
{	
	char name[20];
	int x, y, z;
	int result;
}a[10], temp;

int main()
{
	int i, j;
	int n;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("이름, 점수를 입력하시오 : ");
		scanf("%s %d %d %d", &a[i].name, &a[i].x, &a[i].y, &a[i].z);

		a[i].result = a[i].x + a[i].y + a[i].z;
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[j].result < a[j + 1].result)
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%s %d %d %d %d\n", a[i].name, a[i].x, a[i].y, a[i].z, a[i].result);

	return 0;
}