#include<stdio.h>

int main()
{
	int n, a, i;
	int result = 0;

	scanf_s("%d", &n);

	if (n % 2 == 0)
	{
		printf("¦���Դϴ�.\n");
	}
	else if (n % 2 == 1)
	{
		printf("Ȧ���Դϴ�.\n");
	}

	for (a = 1; a <= n; a++)
	{
		result += a;
	}
	printf("%d\n", result);

	return 0;
}
