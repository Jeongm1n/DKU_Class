/*�� ������ �Էµ� ������ ������� �Է¹޾� ��ū�� ���� ����ϴ� ���α׷��� �ۼ��϶�.*/
#include <iostream>
using namespace std;

int main()
{
	char str[100][80];
	int i = 0;
	int count = 0;
	char* p = str[0];
	for (int i = 0; i < 100; i++) {
		gets_s(str[i]);
		if (!str[i][0])
			break;
	}
	while (*p)
	{
		if (*p != ' ')
			p++;
		if (*p == ' ') {
			p++;
			count++;
			continue;
		}
		if (*p == '\0') {
			*p = str[++i][0];
			count++;
			continue;
		}
	}
	cout << count << endl;
	return 0;
}