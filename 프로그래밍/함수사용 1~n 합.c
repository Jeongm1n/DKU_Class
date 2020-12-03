#include<stdio.h>

int fn(int a)
{
	int i;
	int fact = 0;

	for (i = 1; i <= a; i++)
	{
		fact += i;
	}

	return fact;
}

int main()
{
	int n, result;

	scanf_s("%d", &n);


	result = fn(n);


	printf("%d\n", result);

	return 0;
}