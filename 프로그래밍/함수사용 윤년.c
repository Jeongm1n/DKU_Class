#include <stdio.h>
int IsLeapYear(int a);
int main() {
	while (1) {
		int year;
		printf("�⵵�� �Է��Ͻÿ�: ");
		scanf_s("%d", &year);
		if (IsLeapYear(year) == 1)
		{
			printf("�����Դϴ�\n");
		}
		if (IsLeapYear(year) == 0)
		{
			printf("������ �ƴմϴ�\n");
		}
		if (IsLeapYear(year) == 2)
			break;
	}
}

int IsLeapYear(int a)
{
	if (a % 4 == 0 && a % 100 != 0)
	{
		return 1;
	}
	else if (a % 100 == 0 && a % 400 == 0)
		return 1;
	else if (a < 0)
		return 2;
	else
		return 0;
}