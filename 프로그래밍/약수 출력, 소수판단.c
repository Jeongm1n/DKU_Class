#include<stdio.h>

int main()
{
	int n;
	int i;
	int cnt = 0;

	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%d ", i);
			cnt++;
		}
	}
	printf("\n");

	if (cnt == 2)
	{
		printf("�Ҽ��Դϴ�.\n");
	}

	return 0;
}