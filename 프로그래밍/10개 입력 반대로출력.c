#include<stdio.h>


int main()
{
	int a[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}

	for (i = 9; i >= 0; i--)
	{
		printf("%d", a[i]);
	}

	return 0;
}