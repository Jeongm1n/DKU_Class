#include<stdio.h>

int fn1(int x)
{
	return x / 2;
}
int fn2(int y)
{
	return y * 2;
}
int main()
{
	int a, b;

	scanf_s("%d %d", &a, &b);

	if (a>b)
	{
		printf("%d ", fn1(a));
		printf("%d", fn2(b));
	}
	else
	{
		printf("%d ", fn2(a));
		printf("%d", fn1(b));
	}
	return 0;
}