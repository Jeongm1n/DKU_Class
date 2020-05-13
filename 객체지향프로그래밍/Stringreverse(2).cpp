/*문자열을 뒤집는 rev_str() 함수를 작성하여라.rev_str() 함수가 한 개 혹은 두 개의 문자열을 처리할 수 있게 함수를 중복하여라.
한 개의 문자열로 호출되면, 문자열을 뒤집어서 그 문자열에 넣어서 반환하고,
두 개의 문자열로 호출되면 문자열들을 뒤집은 후 두번째 인수의 문자열에 넣어서 반환한다.예를 들면 다음과 같다.
char s1[80], s2[80];
strcpy(s1, "hello");
rev_str(s1, s2); // 뒤집어진 문자열은 s2에 저장되어 변환되며,
				 // s1은 변하지 않는다.
rev_str(s1); // 뒤집어진 문자열은 s1에 저장되어 반환된다.
*/

#include<iostream>
#include<cstdio>
char rev_str(char *s1, char *s2);
char rev_str(char *s1);
using namespace std;

int main()
{
	char s1[80], s2[80];
	cout << "문자열을 입력하시오 : ";
	gets_s(s1);

	cout << "두 개의 문자열을 사용하여 뒤집기 : ";
	rev_str(s1, s2);
	cout << s2 << endl;

	cout << "한 개의 문자열을 사용하여 뒤집기 : ";
	rev_str(s1);
	cout << s1 << endl;

	return 0;
}
char rev_str(char *s1, char *s2)
{
	int i, j;
	j = strlen(s1);
	for (i = 0; i < j; i++)
	{
		s2[i] = s1[j - 1 - i];
	}
	s2[j] = '\0';
	return *s2;
}
char rev_str(char *s1)
{
	int i, j;
	int temp;
	j = strlen(s1);

	for (i = 0; i < j/2; i++)
	{
		temp = s1[i];
		s1[i] = s1[j - 1 - i];
		s1[j - 1 - i] = temp;
	}
	return *s1;
}