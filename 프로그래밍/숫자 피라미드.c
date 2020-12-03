#include<stdio.h>

int main()
{
	int n, i, j;

	printf("하나의 정수를 입력하시오 : ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" %d", n);
		}
		printf("\n");
	}
	return 0;
}