#include<iostream>
using namespace std;
class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; }// c ��ü�� ������
	coord(int i, int j) { x = i; y = j; } // a, b ��ü�� ������
	void get_xy(int& i, int& j) { i = x; j = y; }
	friend coord operator-(coord op1, coord op2); // operator ������-�� ����Ͽ� �ߺ� ����
	friend coord operator/(coord op1, coord op2); // operator ������/�� ����Ͽ� �ߺ� ����
};
coord operator-(coord op1, coord op2)
{
	coord temp;// class Ÿ�� temp ����
	temp.x = op1.x - op2.x;// x��ü�� �Ƕ���ͷ� ���� op2.x ��ü�� ����
	temp.y = op1.y - op2.y;// y��ü�� �Ƕ���ͷ� ���� op2.y ��ü�� ����
	return temp; // �� ��ȯ
}
coord operator/(coord op1, coord op2)
{
	coord temp; // class Ÿ�� temp ����
	temp.x = op1.x / op2.x;// x��ü�� �Ƕ���ͷ� ���� op2.x ��ü�� ������
	temp.y = op1.y / op2.y;// y��ü�� �Ƕ���ͷ� ���� op2.y ��ü�� ������
	return temp; // �� ��ȯ
}
int main()
{
	int x, y;
	coord a(10, 10), b(2, 5), c;
	c = a - b; // �ߺ�
	c.get_xy(x, y);// c ��ü�� x, y���� �ҷ��� ���
	cout << " c��  x : " << x << ", c�� y : " << y << endl;
	c = a / b;
	c.get_xy(x, y);// c ��ü�� x, y���� �ҷ��� ���
	cout << " c��  x : " << x << ", c�� y : " << y << endl;
	return 0;
}