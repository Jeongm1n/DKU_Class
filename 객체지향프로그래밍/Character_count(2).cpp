/*�� ������ �Էµ� ������ ������� �Է¹޾� ���ڿ��� �ִ� ����, �޸�
, ��ħǥ�� ���� ���� ���α׷��� �ۼ��Ͽ���. ����, �޸�, ��ġ���� �����ϱ� ���� switch���� ����Ͽ���*/
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
		cout << i + 1 << " ��° ���� : ";
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
	cout << "������ �� : " << count1 << endl;
	cout << "�޸��� �� : " << count2 << endl;
	cout << "��ħǥ�� �� : " << count3 << endl;
	return 0;
}