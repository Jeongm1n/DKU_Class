/*빈 라인이 입력될 때까지 문장들을 입력받아 문자열에 있는 공백, 콤마
, 마침표의 수를 세는 프로그램을 작성하여라. 공백, 콤마, 마치묘를 구분하기 위해 switch문을 사용하여라*/
#include "pch.h"
#include <iostream>
using namespace std;
int main()
{

	char text[30][50];
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	for (int i = 0; i < 30; i++)
	{
		cout << i + 1 << " 번째 라인 : ";
		gets_s(text[i]);
		if (!text[i][0])
			break;
		for (int j = 0; text[i][j] != NULL; j++)
			switch (text[i][j])
			{
			case ' ': count1++; continue;

			case ',': count2++; continue;

			case '.': count3++; continue;

			default:continue;
			}


	}
	cout << "공백의 수 : " << count1 << endl;
	cout << "콤마의 수 : " << count2 << endl;
	cout << "마침표의 수 : " << count3 << endl;
	return 0;
}