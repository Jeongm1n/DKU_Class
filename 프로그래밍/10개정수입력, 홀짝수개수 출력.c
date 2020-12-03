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
	printf("Â¦¼ö : %d°³\n", result1);
	printf("È¦¼ö : %d°³\n", result2);
	return 0;
}