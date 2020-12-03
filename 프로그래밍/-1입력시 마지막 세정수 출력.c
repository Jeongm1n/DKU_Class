#include<stdio.h>

int main()
{
	int a[100];
	int i;

	for (i = 0; i < 100; i++)
	{
		scanf_s("%d", &a[i]);

		if (a[i] == -1)
		{
			break;
		}
	}
	printf("%d %d %d", a[i - 3], a[i - 2], a[i - 1]);

	return 0;
}