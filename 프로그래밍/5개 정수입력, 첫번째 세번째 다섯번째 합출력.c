#include<stdio.h>

int main()
{
	int a[5];
	int i;

	for (i = 0; i<5; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("%d", a[0] + a[2] + a[4]);

	return 0;
}