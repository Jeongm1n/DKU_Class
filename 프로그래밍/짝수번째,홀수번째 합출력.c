#include<stdio.h>

int main()
{
	int a[10];
	int i, j;
	int cnt = 0;
	int cnt1 = 0;

	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (j = 0; j<10; j++)
	{
		if ((j + 1) % 2 == 0)
			cnt += a[j];
		else
			cnt1 += a[j];
	}
	printf("짝수번째의합:%d\n", cnt);
	printf("홀수번째의합:%d\n", cnt1);

	return 0;
}