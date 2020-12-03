#include<stdio.h>

int main()
{
	int a[100];
	int i, j;
	int max = -1000;
	int min = 1000;

	for (i = 0; i < 100; i++)
	{
		scanf_s("%d", &a[i]);
		if (a[i] == 999)
			break;
	}
	for (j = 0; j < i; j++)
	{
		if (max < a[j])
			max = a[j];
		else if (min > a[j])
			min = a[j];
	}

	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);

	return 0;
}
