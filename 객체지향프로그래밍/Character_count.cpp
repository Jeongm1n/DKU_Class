/* ����ڰ� �Է��� ������, ����, ������(, . ! 3����)�� ������ ���� ���α׷�	�� �ۼ��Ͽ���. ����ڰ� <Enter> Ű�� ������ �Է��� �ߴܵȴ�.
if ���� ����Ͽ� ���ڸ� ������, ����, �����ڷ� �з��Ͽ���. ���α׷��� ������ �� ������ ������ ����Ͽ���.*/
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[80];                                   // �Է¹��� ���ڿ�
	int countalpha = 0, countnum = 0, countdot = 0;   // ������ ������ ���� ���� ������ ���� �ʱ�ȭ

	while (1)                                         // �Էµ� ���ڿ��� ũ�⸦ �𸣱� ������ EnterŰ�� ���� ������ ���ѷ��� ����
	{
		gets_s(str);                                // ���ڿ� �Է�

		if (str[0] == '\0')                         // ���ڿ��� �Է����� �ʰ� �ٷ� ���͸� ���� ��	null ���ڷ� �ν�
			break;                                    // ���ѷ��� Ż��
		

		for (int i = 0; str[i] != '\0'; i++)        // null���ڸ� ���� ������ for�� ����
		{
			if ('A' <= str[i] && str[i] <= 'Z' || 'a' <= str[i] && str[i] <= 'z') // �빮�� A���� Z���� �Ǵ� �ҹ��� a���� z������ ��
				countalpha++;                                                             // countalpha(������) ����
			else if ('0' <= str[i] && str[i] <= '9')                                  // ���� 0���� 9������ ��
				countnum++;                                                               // countnum(����) ����
			else if (str[i] == '.' || str[i] == ',' || str[i] == '!')               // '.', ',', '!'�� ��
				countdot++;                                                               // countdot(������) ����
		}
	}
	cout << "�������� ���� : " << countalpha << endl;//
	cout << "������ ���� : " << countnum << endl;    // ������ ���� ���
	cout << "�������� ���� : " << countdot << endl;  //

	return 0;
}