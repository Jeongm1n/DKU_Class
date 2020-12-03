#include<stdio.h>

int fn(int x, int y)
{
	int i;
	int total = x;

	for (i = 1; i<y; i++)
	{
		total *= x;
	}

	return total;
}

int main()
{
	int m, n;
	int result = 0;
	scanf_s("%d %d", &m, &n);

	result = fn(m, n);

	printf("%d\n", result);

	return 0;
}