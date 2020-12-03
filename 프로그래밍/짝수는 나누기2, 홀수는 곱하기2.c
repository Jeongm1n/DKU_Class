#include<stdio.h>

int main()
{
	int a[100];
	int i, j;
	int cnt = 0;
	for (i = 0; i < 100; i++)
	{
		scanf_s("%d", &a[i]);
		cnt++;
			if (a[i] == 0)
				break;
	}
	printf("%d °³\n", cnt - 1);
	for (j = 0; j < i; j++)
	{
		if (a[j] % 2 == 0)
			a[j] = a[j] / 2;
		else if (a[j] % 2 == 1)
			a[j] = a[j] * 2;

		printf("%d ", a[j]);
	}
	printf("\n");

	return 0;
}