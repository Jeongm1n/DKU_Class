#include<iostream>
using namespace std;
class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; }// c 객체의 생성자
	coord(int i, int j) { x = i; y = j; } // a, b 객체의 생성자
	void get_xy(int& i, int& j) { i = x; j = y; }
	coord operator==(coord op2);// operator 연산자==를 사용하여 중복 정의
	coord operator&&(coord op2);// operator 연산자&&를 사용하여 중복 정의
};
coord coord::operator==(coord op2)
{
	coord temp; // class 타입 temp 선언
	temp.x = x == op2.x;//x객체와 op2.x의 값을 비교하며 같으면 1 다르면 0을 넣어줌
	temp.y = y == op2.y;//y객체와 op2.y의 값을 비교하며 같으면 1 다르면 0을 넣어줌
	return temp; // 값 반환
}
coord coord::operator&&(coord op2)
{
	coord temp;
	temp.x = x && op2.x; //x와 op2.x가 0이 아닌 수 이면 1를 넣어주고 둘 중 하나가 0이면 0을 넣어준다
	temp.y = y && op2.y;//y와 op2.y가 0이 아닌 수 이면 1를 넣어주고 둘 중 하나가 0이면 0을 넣어준다
	return temp; // 값 반환
}
int main()
{
	coord a(1, 0), b(3, 0), c; // 객체 3개 생성
	int x, y;
	c = a == b; // 연산자 중복
	c.get_xy(x, y); // c 객체에 x, y값을 불러서 출력
	cout << "c의 x : " << x << ", c의 y :" << y << endl;
	c = a && b; // 연산자 중복
	c.get_xy(x, y); // c 객체에 x, y값을 불러서 출력
	cout << "c의 x : " << x << ", c의 y :" << y << endl;

	return 0;
}