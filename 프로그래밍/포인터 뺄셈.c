#include<stdio.h>

int main()
{
	int n, m, l;
	int *x = &n;
	int *y = &m;
	int *z = &l;

	scanf("%d %d", x, y);

	if (*x>*y)
		*z = *x - *y;
	else
		*z = *y - *x;

	printf("%d", *z);

	return 0;
}