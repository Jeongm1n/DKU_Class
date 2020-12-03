#include<stdio.h>

int main()
{
	int n, x, y, z;

	scanf_s("%d", &n);

	for (x = 1; x <= n; x++)
	{
		for (z = 1; z <= x - 1; z++)
		{
			printf(" ");
		}

		for (y = n; y >= x; y--)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}