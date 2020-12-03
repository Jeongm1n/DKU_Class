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
	printf("이름 : %s\n", s1.name);
	printf("폰번호 : %s\n", s1.num);
	printf("사는지역 : %s\n", s1.loc);

	return 0;
}