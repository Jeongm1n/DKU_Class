#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *a;
	int size_a, i;
	int max = -1000;
	int min = 1000;

	printf("�迭 ũ�� �Է�: ");
	scanf("%d", &size_a);

	a = (int*)malloc(size_a * sizeof(int));

	printf("���� �Է�: ");
	for (i = 0; i<size_a; i++)
		scanf("%d", &a[i]);

	for (i = 0; i<size_a; i++)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i]<min)
			min = a[i];
	}

	printf("�ִ밪 : %d\n", max);
	printf("�ּҰ� : %d\n", min);

	free(a);

	return 0;
}