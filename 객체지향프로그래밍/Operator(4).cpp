#include<iostream>
using namespace std;
class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; }// c 객체의 생성자
	coord(int i, int j) { x = i; y = j; } // a, b 객체의 생성자
	void get_xy(int& i, int& j) { i = x; j = y; }
	friend coord operator-(coord op1, coord op2); // operator 연산자-를 사용하여 중복 정의
	friend coord operator/(coord op1, coord op2); // operator 연산자/를 사용하여 중복 정의
};
coord operator-(coord op1, coord op2)
{
	coord temp;// class 타입 temp 선언
	temp.x = op1.x - op2.x;// x객체랑 피라미터로 받은 op2.x 객체를 뺀다
	temp.y = op1.y - op2.y;// y객체랑 피라미터로 받은 op2.y 객체를 뺀다
	return temp; // 값 반환
}
coord operator/(coord op1, coord op2)
{
	coord temp; // class 타입 temp 선언
	temp.x = op1.x / op2.x;// x객체랑 피라미터로 받은 op2.x 객체를 나눈다
	temp.y = op1.y / op2.y;// y객체랑 피라미터로 받은 op2.y 객체를 나눈다
	return temp; // 값 반환
}
int main()
{
	int x, y;
	coord a(10, 10), b(2, 5), c;
	c = a - b; // 중복
	c.get_xy(x, y);// c 객체에 x, y값을 불러서 출력
	cout << " c의  x : " << x << ", c의 y : " << y << endl;
	c = a / b;
	c.get_xy(x, y);// c 객체에 x, y값을 불러서 출력
	cout << " c의  x : " << x << ", c의 y : " << y << endl;
	return 0;
}