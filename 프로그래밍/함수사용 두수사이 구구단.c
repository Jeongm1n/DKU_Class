#include<stdio.h>

int fn(int a, int b)
{
	int i, j;
	if (b>a)
	{
		for (i = a; i <= b; i++)
		{
			for (j = 1; j <= 9; j++)
			{
				printf("%d * %d = %d\n", i, j, i*j);
			}
		}
	}
	else
	{
		for (i = b; i <= a; i++)
		{
			for (j = 1; j <= 9; j++)
			{
				printf("%d * %d = %d\n", i, j, i*j);
			}
		}
	}

}

int main()
{
	int m, n;

	scanf_s("%d %d", &m, &n);

	fn(m, n);

	return 0;
}