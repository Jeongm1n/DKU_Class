#include<stdio.h>

struct stu
{
	char name[20];
	char num[20];
	char loc[20];
}s1;

int main()
{
	scanf("%s %s %s", s1.name, s1.num, s1.loc);
	printf("�̸� : %s\n", s1.name);
	printf("����ȣ : %s\n", s1.num);
	printf("������� : %s\n", s1.loc);

	return 0;
}