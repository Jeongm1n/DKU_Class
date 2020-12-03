#include<stdio.h>
#include<stdlib.h>
int main()
{
	double *a;
	int size_a, i;
	double result = 0;
	printf("배열의 크기를 입력하시오 : ");
	scanf("%d", &size_a);

	a = (double*)malloc(size_a * sizeof(double));

	for (i = 0; i<size_a; i++)
		scanf("%lf", &a[i]);

	for (i = 0; i<size_a; i++)
	{
		result += a[i];
		printf("%.2f ", a[i]);
	}

	printf("\n합계 : %.2f", result);
	printf("\n평균 : %.2f", result / size_a);

	free(a);

	return 0;
}