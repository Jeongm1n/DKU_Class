#include<stdio.h>

int swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void main()
{
	int a, b;
	a = 10;
	b = 5;

	printf("%d %d\n", a, b);
	
	swap(&a, &b);

	printf("%d %d\n", a,b);

	return 0;
}