#include<iostream>
using namespace std;
template <class X> int find(X object, X* list, int size) // ���ø�Ʈ �Լ�
{
	int t = -1; // t = -1�� �ʱ�ȭ
	for (int i = 0; i < size; i++)
	{
		if (list[i] == object) // list[i]�� object�� ���ٸ�
			t = i; // t = i
	}
	if (t == -1) // t�� -1�̸�
		return t; // t ��ȯ
	else // �ƴ϶��
		return t + 1; // t(i)+1 ��ȯ
}
int main()
{
	int _size, * a, find_int; // �迭ũ�⺯����, �� �ڷ����� �����Ϳ�, Ž���� ���� ����
	float* b, find_float;
	char* c, find_char;

	cout << "size �Է�: ";
	cin >> _size;
	a = new int[_size]; // ������ �����Ҵ����
	for (int i = 0; i < _size; i++)
	{
		cout << "�����Է�: ";
		cin >> a[i]; // _size��ŭ ���� �Է�
	}
	cout << "Ž���Ұ�: ";
	cin >> find_int; // Ž���� �� �Է�
	cout << "÷��: " << find(find_int, a, _size) << endl; // ���

	cout << "size �Է�: ";
	cin >> _size;
	b = new float[_size]; // �Ǽ��� �����Ҵ����
	for (int i = 0; i < _size; i++)
	{
		cout << "�Ǽ��Է�: ";
		cin >> b[i]; //_size��ŭ �Ǽ� �Է�
	}
	cout << "Ž���Ұ�: ";
	cin >> find_float; // Ž���� �� �Է�
	cout << "÷��: " << find(find_float, b, _size) << endl; // ���

	cout << "size �Է�: ";
	cin >> _size;
	c = new char[_size]; // ������ �����Ҵ����
	for (int i = 0; i < _size; i++)
	{
		cout << "�����Է�: ";
		cin >> c[i]; // _size��ŭ ���� �Է�
	}
	cout << "Ž���Ұ�: ";
	cin >> find_char; // Ž���� �� �Է�
	cout << "÷��: " << find(find_char, c, _size) << endl; // ���
	return 0;
}