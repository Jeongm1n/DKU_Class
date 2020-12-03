#include<stdio.h>

int main()
{
	int n, a, i;
	int result = 0;

	scanf_s("%d", &n);

	if (n % 2 == 0)
	{
		printf("짝수입니다.\n");
	}
	else if (n % 2 == 1)
	{
		printf("홀수입니다.\n");
	}

	for (a = 1; a <= n; a++)
	{
		result += a;
	}
	printf("%d\n", result);

	return 0;
}
