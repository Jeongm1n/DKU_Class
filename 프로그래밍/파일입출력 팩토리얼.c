#include<stdio.h>

int main()
{
	int n, i;
	
	fscanf(stdin, "%d", &n);

	for (i = n-1; i > 0; i--)
	{
		n *= i;
	}
	fprintf(stdout, "%d\n", n);

	return 0;
}