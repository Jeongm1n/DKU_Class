#include<stdio.h>

int main()
{
	int a[100];
	int i,j;
	int cnt = 0;
	int total = 0;
	double result = 0;

	for (i = 0; i < 100; i++)
	{
		scanf_s("%d", &a[i]);
		if (a[i] == 0)
			break;
	}
	for (j = 0; j < i; j++)
	{
		if (a[j] % 5 == 0)
		{
			total += a[j];
			cnt++;
		}
	}
	result = total / cnt;

	printf("%d ��\n", cnt);
	printf("�� : %d\n", total);
	printf("��� : %.2lf\n", result);

	return 0;

}