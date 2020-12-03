#include<stdio.h>
int fn(int a, int b);
int main()
{
	int m, n;
	int result = 0;

	scanf_s("%d %d", &m, &n);

	result = fn(m, n);
	printf("%d", result);
}

int fn(int a, int b)
{
	int res=0;

	res = a + b;

	return res;
}