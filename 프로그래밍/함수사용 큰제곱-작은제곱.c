#include<stdio.h>

int fn(int a, int b)
{
	int res;

	if (a > b)
		res = (a*a) - (b*b);
	else
		res = (b*b) - (a*a);

}

int main()
{
	int m, n;
	int result;

	scanf_s("%d %d", &m, &n);

	result = fn(m, n);

	printf("%d\n", result);

	return 0;
}