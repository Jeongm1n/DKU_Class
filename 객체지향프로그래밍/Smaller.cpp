#include<iostream>
using namespace std;

template <class X> void min(X a, X b) // ���ø�Ʈ �Լ� 
{
	if (a > b) // b�� a���� �۴ٸ�
		cout << "����������: " << b << endl; // b �� ���
	else if (a < b) // a�� b���� �۴ٸ�
		cout << "����������: " << a << endl; // a �� ���
	else
		cout << "�����մϴ�." << endl;
}
int main()
{
	int x = 3;
	int y = 4;
	char p = 'c';
	char q = 'a';
	min(x, y);  // ����
	min(p, q); // ����

	return 0;
}