#include<stdio.h>
#include<string.h>
struct stu
{
	char name[20];
	char num[20];
	char loc[20];
}s1[3];

int main()
{
	int i;
	for (i = 0; i<3; i++)
		scanf("%s %s %s", s1[i].name, s1[i].num, s1[i].loc);

	s1[0] = strcmp(s1[0].name, s1[1].name)>0 ? s1[1] : s1[0];
	s1[0] = strcmp(s1[0].name, s1[2].name)>0 ? s1[2] : s1[0];

	printf("�̸� : %s\n", s1[0].name);
	printf("����ȣ : %s\n", s1[0].num);
	printf("������� : %s\n", s1[0].loc);


	return 0;
}