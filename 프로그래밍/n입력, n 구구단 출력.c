#include<stdio.h>

int main()
{
	int n, x;

	scanf_s("%d", &n);

	for (x = 1; x < 10; x++)
	{
		printf("%d x %d = %d\n", n, x, n*x);
	}
	return 0;
}