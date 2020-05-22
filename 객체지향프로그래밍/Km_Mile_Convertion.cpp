#include<iostream>
using namespace std;
class Distance {
protected:
	double x, y;
public:
	Distance() { x = 0; y = 0; }; // 생성자
	Distance(double a, double b) { x = a; y = b; };
	virtual double trav_time() // 가상함수 선언
	{
		double t; //시간 변수 선언
		t = (y - x) / 60;
		return t; // t 반환
	}
};
class metric : public Distance {
public:
	metric(double a, double b) { x = a; y = b; }; // 생성자
	double trav_time()
	{
		double t; // 시간 변수 선언
		t = (y - x) / 100;
		return t; // t 반환
	}
};
int main() {
	Distance mile(10, 20); // mile로 계산할 값
	metric km(10, 40); // km로 계산할 값

	cout << "Mile 단위: " << mile.trav_time() << endl; // mile 단위 출력
	cout << "Km 단위: " << km.trav_time() << endl; // km 단위 출력
	return 0;
}