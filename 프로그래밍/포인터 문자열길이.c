#include<stdio.h>

int main()
{
	char ch[1024];
	int i;
	int cnt = 0;
	printf("문자열을 입력하시오 : ");
	gets(ch);
	
	for (i = 0; *(ch + i); i++)
		cnt++;

	printf("입력하신 문자열의 길이는 %d 입니다.\n", cnt);

	return 0;
}
