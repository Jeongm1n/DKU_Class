#include<stdio.h>

int fn(int a)
{
	int i, j;
	int cnt = 1;
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= a; j++)
		{
			printf("%5d ", cnt);
			cnt++;
		}
		printf("\n");
	}
}

int main()
{
	int n;

	scanf_s("%d", &n);

	fn(n);

	return 0;

}