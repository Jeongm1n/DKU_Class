#include<stdio.h>

int main()
{
	int n,i;
	int result1 = 0;
	int result2 = 0;

	for (i = 1; i <= 10; i++)
	{
		scanf_s("%d", &n);

		if (n % 2 == 0)
		{
			result1++;
		}
		else
		{
			result2++;
		}
	}
	printf("¦�� : %d��\n", result1);
	printf("Ȧ�� : %d��\n", result2);
	return 0;
}