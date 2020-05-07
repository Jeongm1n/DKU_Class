#include<stdio.h>

int main()
{
	char ch[1024];
	int i;
	printf("문자열을 입력하시오: ");
	gets_s(ch); // 문자열 입력 받기

	for (i = 0; ch[i]; i++); // 문자열 길이 체크

	printf("입력하신 문자열의 길이는 %d 입니다.\n", i);

	return 0;
}