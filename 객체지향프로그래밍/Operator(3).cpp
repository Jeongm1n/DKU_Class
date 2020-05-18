#include<iostream>
using namespace std;
class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; } // c 객체의 생성자
	coord(int i, int j) { x = i; y = j; } // a, b 객체의 생성자
	void get_xy(int& i, int& j) { i = x; j = y; }
	coord operator--(); // 접두사 중복
	coord operator--(int notused); // 접미사 중복
};
coord coord::operator--() {
	x--; // x 감소
	y--; // y 감소
	return *this; // 변경된 값 반환
}
coord coord::operator--(int notused) {
	coord temp = *this; // 원래의 값 저장
	x--; // x, y 감소
	y--;
	return temp; // 값 반환
}
int main() {
	int x, y;
	coord a(5, 5), b(10, 10), c;
	c = a--; // 중복
	a.get_xy(x, y);
	cout << " a의  x : " << x << ", a의 y : " << y << endl;
	c.get_xy(x, y);
	cout << " c의  x : " << x << ", c의 y : " << y << endl;
	c = --b; // 중복
	b.get_xy(x, y);
	cout << " b의  x : " << x << ", b의 y : " << y << endl;
	c.get_xy(x, y);
	cout << " c의  x : " << x << ", c의 y : " << y << endl;

	return 0;
}