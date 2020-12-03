#include<stdio.h>


int main()
{
	int a, i;
	int result1 = 0;
	int result2 = 0;
	printf("5개의 정수를 입력하시오:\n");
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
	printf("짝수의 합은 %d\n", result1);
	printf("홀수의 합은 %d\n", result2);

	return 0;
}