#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a;
	int size_a, i, j;
	int temp;
	printf("배열의 크기를 입력하시오 : ");
	scanf("%d", &size_a);

	a = (int*)malloc(size_a * sizeof(int));

	for (i = 0; i<size_a; i++)
		scanf("%d", &a[i]);

	for (i = 0; i<size_a - 1; i++)
	{
		for (j = 0; j<size_a; j++)
		{
			if (a[j]<a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i<size_a; i++)
		printf("%d ", a[i]);

	free(a);

	return 0;
}