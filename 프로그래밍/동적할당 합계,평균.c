#include<stdio.h>
#include<stdlib.h>
int main()
{
	double *a;
	int size_a, i;
	double result = 0;
	printf("�迭�� ũ�⸦ �Է��Ͻÿ� : ");
	scanf("%d", &size_a);

	a = (double*)malloc(size_a * sizeof(double));

	for (i = 0; i<size_a; i++)
		scanf("%lf", &a[i]);

	for (i = 0; i<size_a; i++)
	{
		result += a[i];
		printf("%.2f ", a[i]);
	}

	printf("\n�հ� : %.2f", result);
	printf("\n��� : %.2f", result / size_a);

	free(a);

	return 0;
}