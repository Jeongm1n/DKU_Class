/*���ڿ��� ������ rev_str() �Լ��� �ۼ��Ͽ���.rev_str() �Լ��� �� �� Ȥ�� �� ���� ���ڿ��� ó���� �� �ְ� �Լ��� �ߺ��Ͽ���.
�� ���� ���ڿ��� ȣ��Ǹ�, ���ڿ��� ����� �� ���ڿ��� �־ ��ȯ�ϰ�,
�� ���� ���ڿ��� ȣ��Ǹ� ���ڿ����� ������ �� �ι�° �μ��� ���ڿ��� �־ ��ȯ�Ѵ�.���� ��� ������ ����.
char s1[80], s2[80];
strcpy(s1, "hello");
rev_str(s1, s2); // �������� ���ڿ��� s2�� ����Ǿ� ��ȯ�Ǹ�,
				 // s1�� ������ �ʴ´�.
rev_str(s1); // �������� ���ڿ��� s1�� ����Ǿ� ��ȯ�ȴ�.
*/

#include<iostream>
#include<cstdio>
char rev_str(char *s1, char *s2);
char rev_str(char *s1);
using namespace std;

int main()
{
	char s1[80], s2[80];
	cout << "���ڿ��� �Է��Ͻÿ� : ";
	gets_s(s1);

	cout << "�� ���� ���ڿ��� ����Ͽ� ������ : ";
	rev_str(s1, s2);
	cout << s2 << endl;

	cout << "�� ���� ���ڿ��� ����Ͽ� ������ : ";
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