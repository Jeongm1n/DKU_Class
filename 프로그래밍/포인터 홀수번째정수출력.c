#include<stdio.h>

int main()
{
	int a[5];
	int *p[5];
	int i;
	for (i = 0; i<5; i++)
	{
		p[i] = &a[i];
		scanf("%d", p[i]);
	}

	for (i = 0; i<5; i++)
	{
		if (i % 2 == 0)
			printf("%d ", *p[i]);
	}

	return 0;

}