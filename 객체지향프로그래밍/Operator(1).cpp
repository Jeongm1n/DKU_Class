#include<iostream>
using namespace std;
class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; } // c ��ü�� ������
	coord(int i, int j) { x = i; y = j; } // a, b ��ü�� ������
	void get_xy(int& i, int& j) { i = x; j = y; }
	coord operator*(coord op2); // operator ������*�� ����Ͽ� �ߺ� ����
	coord operator/(coord op2); // operator ������/�� ����Ͽ� �ߺ� ����
};
coord coord::operator*(coord op2)
{
	coord temp; // class Ÿ�� temp ����
	temp.x = x * op2.x; // x��ü�� �Ƕ���ͷ� ���� op2.x ��ü�� ���Ѵ�
	temp.y = y * op2.y; // y��ü�� �Ƕ���ͷ� ���� op2.y ��ü�� ���Ѵ�
	return temp; // �� ��ȯ
}
coord coord::operator/(coord op2)
{
	coord temp; // class Ÿ�� temp ����
	temp.x = x / op2.x; // x��ü�� �Ƕ���ͷ� ���� op2.x ��ü�� ������
	temp.y = y / op2.y; // y��ü�� �Ƕ���ͷ� ���� op2.y ��ü�� ������.
	return temp; // �� ��ȯ
}
int main()
{
	coord a(10, 10), b(2, 5), c; // ��ü 3�� ����
	int x, y;
	c = a * b; // a operator* b �� ����
	c.get_xy(x, y); // c ��ü�� x, y���� �ҷ��� ���
	cout << " c��  x : " << x << ", c�� y : " << y << endl;
	c = a / b; // a operator/ b�� ����
	c.get_xy(x, y); // c ��ü�� x, y ���� �ҷ��� ���
	cout << " c��  x : " << x << ", c�� y : " << y << endl;
	return 0;
}