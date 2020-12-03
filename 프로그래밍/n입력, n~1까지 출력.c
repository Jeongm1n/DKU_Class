#include<stdio.h>

int main()
{
	int n, x;

	scanf_s("%d", &n);

	for (x = n; x >= 1; x--)
	{
		printf("%d\n", x);
	}

	return 0;
}