/* 사용자가 입력한 영문자, 숫자, 구두점(, . ! 3가지)의 개수를 세는 프로그램	을 작성하여라. 사용자가 <Enter> 키를 누르면 입력이 중단된다.
if 문을 사용하여 문자를 구두점, 숫자, 영문자로 분류하여라. 프로그램이 종료할 때 각각의 개수를 출력하여라.*/
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[80];                                   // 입력받을 문자열
	int countalpha = 0, countnum = 0, countdot = 0;   // 각각의 개수를 세기 위한 변수와 변수 초기화

	while (1)                                         // 입력될 문자열의 크기를 모르기 때문에 Enter키를 누를 때까지 무한루프 설정
	{
		gets_s(str);                                // 문자열 입력

		if (str[0] == '\0')                         // 문자열을 입력하지 않고 바로 엔터를 누를 시	null 문자로 인식
			break;                                    // 무한루프 탈출
		

		for (int i = 0; str[i] != '\0'; i++)        // null문자를 만날 때까지 for문 실행
		{
			if ('A' <= str[i] && str[i] <= 'Z' || 'a' <= str[i] && str[i] <= 'z') // 대문자 A에서 Z까지 또는 소문자 a에서 z까지일 때
				countalpha++;                                                             // countalpha(영문자) 증가
			else if ('0' <= str[i] && str[i] <= '9')                                  // 숫자 0에서 9까지일 때
				countnum++;                                                               // countnum(숫자) 증가
			else if (str[i] == '.' || str[i] == ',' || str[i] == '!')               // '.', ',', '!'일 때
				countdot++;                                                               // countdot(구두점) 증가
		}
	}
	cout << "영문자의 개수 : " << countalpha << endl;//
	cout << "숫자의 개수 : " << countnum << endl;    // 각각의 개수 출력
	cout << "구두점의 개수 : " << countdot << endl;  //

	return 0;
}