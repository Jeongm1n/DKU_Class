#include<stdio.h>

int main()
{
	char ch;
	int i;
	printf("영문자를 입력하시오 : ");
	for (i = 1; i <= 5; i++)
	{
		scanf("%c", &ch);

		if (ch >= 'a'&&ch <= 'z')
		{
			printf("소문자입니다.\n");
			fflush(stdin);
		}

		else if (ch >= 'A'&&ch <= 'Z')
		{
			printf("대문자입니다.\n");
			fflush(stdin);
		}
		else
		{
			printf("영문자가 아닙니다.\n");
			fflush(stdin);
		}
	}
	return 0;
}