#include<stdio.h>

int main()
{
	double a[5];
	double *p[5];
	int i;

	for (i = 0; i<5; i++)
	{
		p[i] = &a[i];
		scanf("%lf", p[i]);
	}
	for (i = 0; i<5; i++)
		printf("%.1f ", *p[i]);

	return 0;
}