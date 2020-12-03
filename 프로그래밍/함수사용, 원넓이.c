#include<stdio.h>

double fn(int a)
{
	int res = 0;
	double x = 3.14;

	res = a*a*x;

	return a*a*x;

}

int main()
{
	int n;
	double result = 0;
	scanf_s("%d", &n);

	result = fn(n);

	printf("%.2lf", result);

	return 0;
}