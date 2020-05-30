#include<iostream>
using namespace std;

template <class X> void min(X a, X b) // 템플리트 함수 
{
	if (a > b) // b가 a보다 작다면
		cout << "더작은값은: " << b << endl; // b 값 출력
	else if (a < b) // a가 b보다 작다면
		cout << "더작은값은: " << a << endl; // a 값 출력
	else
		cout << "동일합니다." << endl;
}
int main()
{
	int x = 3;
	int y = 4;
	char p = 'c';
	char q = 'a';
	min(x, y);  // 정수
	min(p, q); // 문자

	return 0;
}