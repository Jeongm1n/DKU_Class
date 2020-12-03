#include<stdio.h>

int main()
{
	int n;
	int i;
	int *p = &n;
	scanf("%d", &n);

	for (i = 0; i<*p; i++)
		printf("*");

	return 0;
}