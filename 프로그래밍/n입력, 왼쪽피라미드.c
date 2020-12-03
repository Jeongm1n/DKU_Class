#include<stdio.h>

int main()
{
	int n, x, y;

	scanf_s("%d", &n);

	for (x = 1; x <= n; x++)
	{
		for (y = n; y >= 1 y--)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}