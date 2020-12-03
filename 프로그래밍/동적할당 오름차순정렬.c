#include<stdio.h>
#include<stdlib.h>
int compare(const void *e1, const void *e2)
{
	int*p1 = (int*)e1;
	int*p2 = (int*)e2;

	return(*p1 - *p2);
}
int main()
{
	int size, i;
	int *arr;

	scanf("%d", &size);

	arr = (int*)malloc(sizeof(int)*size);

	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, size, sizeof(int), compare);

	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

	return 0;
}