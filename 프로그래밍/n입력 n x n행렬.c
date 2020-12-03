#include<stdio.h>

int main()
{
	int n, x, y;
	int num = -1;
	scanf_s("%d", &n);

	for (x = 1; x <= n; x++)
	{
		for (y = 1; y <= n; y++)
		{
			if (num >= 9)
			{
				num = -1;
			}
			printf("%2d", num += 2);
		}
		printf("\n");
	}
	return 0;
}