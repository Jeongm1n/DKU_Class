#include<iostream>
using namespace std;
class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; } // c ��ü�� ������
	coord(int i, int j) { x = i; y = j; } // a, b ��ü�� ������
	void get_xy(int& i, int& j) { i = x; j = y; }
	coord operator--(); // ���λ� �ߺ�
	coord operator--(int notused); // ���̻� �ߺ�
};
coord coord::operator--() {
	x--; // x ����
	y--; // y ����
	return *this; // ����� �� ��ȯ
}
coord coord::operator--(int notused) {
	coord temp = *this; // ������ �� ����
	x--; // x, y ����
	y--;
	return temp; // �� ��ȯ
}
int main() {
	int x, y;
	coord a(5, 5), b(10, 10), c;
	c = a--; // �ߺ�
	a.get_xy(x, y);
	cout << " a��  x : " << x << ", a�� y : " << y << endl;
	c.get_xy(x, y);
	cout << " c��  x : " << x << ", c�� y : " << y << endl;
	c = --b; // �ߺ�
	b.get_xy(x, y);
	cout << " b��  x : " << x << ", b�� y : " << y << endl;
	c.get_xy(x, y);
	cout << " c��  x : " << x << ", c�� y : " << y << endl;

	return 0;
}