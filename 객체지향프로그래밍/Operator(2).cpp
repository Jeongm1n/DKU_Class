#include<iostream>
using namespace std;
class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; }// c ��ü�� ������
	coord(int i, int j) { x = i; y = j; } // a, b ��ü�� ������
	void get_xy(int& i, int& j) { i = x; j = y; }
	coord operator==(coord op2);// operator ������==�� ����Ͽ� �ߺ� ����
	coord operator&&(coord op2);// operator ������&&�� ����Ͽ� �ߺ� ����
};
coord coord::operator==(coord op2)
{
	coord temp; // class Ÿ�� temp ����
	temp.x = x == op2.x;//x��ü�� op2.x�� ���� ���ϸ� ������ 1 �ٸ��� 0�� �־���
	temp.y = y == op2.y;//y��ü�� op2.y�� ���� ���ϸ� ������ 1 �ٸ��� 0�� �־���
	return temp; // �� ��ȯ
}
coord coord::operator&&(coord op2)
{
	coord temp;
	temp.x = x && op2.x; //x�� op2.x�� 0�� �ƴ� �� �̸� 1�� �־��ְ� �� �� �ϳ��� 0�̸� 0�� �־��ش�
	temp.y = y && op2.y;//y�� op2.y�� 0�� �ƴ� �� �̸� 1�� �־��ְ� �� �� �ϳ��� 0�̸� 0�� �־��ش�
	return temp; // �� ��ȯ
}
int main()
{
	coord a(1, 0), b(3, 0), c; // ��ü 3�� ����
	int x, y;
	c = a == b; // ������ �ߺ�
	c.get_xy(x, y); // c ��ü�� x, y���� �ҷ��� ���
	cout << "c�� x : " << x << ", c�� y :" << y << endl;
	c = a && b; // ������ �ߺ�
	c.get_xy(x, y); // c ��ü�� x, y���� �ҷ��� ���
	cout << "c�� x : " << x << ", c�� y :" << y << endl;

	return 0;
}