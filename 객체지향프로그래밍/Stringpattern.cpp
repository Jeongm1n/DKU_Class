/*7.4���� ���� ����(find_substr �Լ�)�� �����Ͽ� ���ڿ����� ��ġ�ϴ�
�κй��ڿ��� ���� ����϶�*/
#include <iostream>
using namespace std;

int find_substr(char *str, char *find);

int main() {
	char str[80];
	char find[10];
	char *p = str;

	cout << "���ڿ� : ";
	cin >> str;
	cout << "���� : ";
	cin >> find;

	cout << "Ƚ�� : " << find_substr(str, find) << endl;

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