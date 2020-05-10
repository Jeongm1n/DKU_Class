/*7.4절의 예제 문제(find_substr 함수)를 참고하여 문자열에서 일치하는
부분문자열의 수를 출력하라*/
#include <iostream>
using namespace std;

int find_substr(char *str, char *find);

int main() {
	char str[80];
	char find[10];
	char *p = str;

	cout << "문자열 : ";
	cin >> str;
	cout << "패턴 : ";
	cin >> find;

	cout << "횟수 : " << find_substr(str, find) << endl;

	return 0;
}

int find_substr(char *str, char *find) 
{
	int count = 0;

	char *p, *p2;
	for (int i = 0; str[i]; i++)
	{
		p = &str[i];
		p2 = find;
		while (*p2 && *p2 == *p) 
		{
			p++;
			p2++;
		}
		if (!*p2)
			count++;
	}
	return count;
}