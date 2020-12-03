#include<stdio.h>
#include<stdlib.h>
int maxnum(int size_b, int *b)
{
	int max = 0;
	int i;

	for (i = 0; i<size_b; i++)
	{
		if (b[i]>b[max])
		{
			max = i;
		}
	}
	return max;
}

int main()
{
	int *a;
	int size_a;
	int i;
	int result;
	printf("배열의 크기를 입력하시오 : ");
	scanf("%d", &size_a);

	a = (int*)malloc(size_a * sizeof(int));

	for (i = 0; i<size_a; i++)
		scanf("%d", &a[i]);

	result = maxnum(size_a, a);

	printf("최대값 : %d\n", a[result]);
	printf("첨자 : %d\n", result);

	return 0;
}