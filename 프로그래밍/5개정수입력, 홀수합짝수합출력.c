#include<stdio.h>


int main()
{
	int a, i;
	int result1 = 0;
	int result2 = 0;
	printf("5���� ������ �Է��Ͻÿ�:\n");
	for (a = 1; a <= 5; a++)
	{
		scanf_s("%d", &i);

		if (i % 2 == 0)
		{
			result1 += i;
		}
		else if (i % 2 == 1)
		{
			result2 += i;
		}
	}
	printf("¦���� ���� %d\n", result1);
	printf("Ȧ���� ���� %d\n", result2);

	return 0;
}