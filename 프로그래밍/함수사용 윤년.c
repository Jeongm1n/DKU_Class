#include <stdio.h>
int IsLeapYear(int a);
int main() {
	while (1) {
		int year;
		printf("년도를 입력하시오: ");
		scanf_s("%d", &year);
		if (IsLeapYear(year) == 1)
		{
			printf("윤년입니다\n");
		}
		if (IsLeapYear(year) == 0)
		{
			printf("윤년이 아닙니다\n");
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