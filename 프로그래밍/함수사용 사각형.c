#include<stdio.h>

int fn(int a)
{
	int i,j;

	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= a; j++)
		{
			printf("%4d", i*j);
		}
		printf("\n");
	}
	return;
}
int main()
{
	int n;
	int res;

	scanf_s("%d", &n);

	fn(n);

	return 0;
}