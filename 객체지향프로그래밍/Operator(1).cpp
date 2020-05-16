#include<iostream>
using namespace std;
class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; } // c 객체의 생성자
	coord(int i, int j) { x = i; y = j; } // a, b 객체의 생성자
	void get_xy(int& i, int& j) { i = x; j = y; }
	coord operator*(coord op2); // operator 연산자*를 사용하여 중복 정의
	coord operator/(coord op2); // operator 연산자/를 사용하여 중복 정의
};
coord coord::operator*(coord op2)
{
	coord temp; // class 타입 temp 선언
	temp.x = x * op2.x; // x객체랑 피라미터로 받은 op2.x 객체를 곱한다
	temp.y = y * op2.y; // y객체랑 피라미터로 받은 op2.y 객체를 곱한다
	return temp; // 값 반환
}
coord coord::operator/(coord op2)
{
	coord temp; // class 타입 temp 선언
	temp.x = x / op2.x; // x객체랑 피라미터로 받은 op2.x 객체를 나눈다
	temp.y = y / op2.y; // y객체랑 피라미터로 받은 op2.y 객체를 나눈다.
	return temp; // 값 반환
}
int main()
{
	coord a(10, 10), b(2, 5), c; // 객체 3개 생성
	int x, y;
	c = a * b; // a operator* b 와 같음
	c.get_xy(x, y); // c 객체에 x, y값을 불러서 출력
	cout << " c의  x : " << x << ", c의 y : " << y << endl;
	c = a / b; // a operator/ b와 같음
	c.get_xy(x, y); // c 객체에 x, y 값을 불러서 출력
	cout << " c의  x : " << x << ", c의 y : " << y << endl;
	return 0;
}