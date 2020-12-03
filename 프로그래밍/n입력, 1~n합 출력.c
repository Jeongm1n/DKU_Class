#include<stdio.h>

int main()
{
	int n, x;
	int result = 0;

	scanf_s("%d", &n);

	for (x = 1; x <= n; x++)
	{
		result += x;
	}

	printf("%d\n", result);

	return 0;
}