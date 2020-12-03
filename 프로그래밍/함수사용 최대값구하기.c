#include<stdio.h>

int fn(int x, int y, int z)
{
	int k;

	if (x>y&&x>z)
		k = x;
	else if (y>x&&y>z)
		k = y;
	else
		k = z;

	return k;
}

int main()
{
	int a, b, c;
	int result;
	scanf_s("%d %d %d", &a, &b, &c);

	result = fn(a, b, c);

	printf("%d\n", result);

	return 0;
}