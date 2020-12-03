#include<stdio.h>

int main()
{
	int n, m, x;

	scanf_s("%d %d", &n, &m);

	if (m > n)
	{
		int temp;
		temp = m;
		m = n;
		n = temp;
	}

	for (x = m; x <= n; x++)
	{
		printf("%3d", x);
	}

	return 0;
}