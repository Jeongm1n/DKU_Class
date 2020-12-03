#include<stdio.h>

int main()
{
	int n, i;
	int result = 0;

	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		if (i % 5 == 0)
		{
			result += i;
		}
	}
	printf("%d\n", result);

	return 0;
}