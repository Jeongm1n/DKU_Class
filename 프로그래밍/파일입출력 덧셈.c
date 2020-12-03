#include<stdio.h>

int main()
{
	double a, b;

	fscanf(stdin, "%lf %lf", &a, &b);
	fprintf(stdout, "%.2lf %.2lf %.2lf", a, b, a + b);

	return 0;		
}