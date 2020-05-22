#include<iostream>
using namespace std;
class Distance {
protected:
	double x, y;
public:
	Distance() { x = 0; y = 0; }; // ������
	Distance(double a, double b) { x = a; y = b; };
	virtual double trav_time() // �����Լ� ����
	{
		double t; //�ð� ���� ����
		t = (y - x) / 60;
		return t; // t ��ȯ
	}
};
class metric : public Distance {
public:
	metric(double a, double b) { x = a; y = b; }; // ������
	double trav_time()
	{
		double t; // �ð� ���� ����
		t = (y - x) / 100;
		return t; // t ��ȯ
	}
};
int main() {
	Distance mile(10, 20); // mile�� ����� ��
	metric km(10, 40); // km�� ����� ��

	cout << "Mile ����: " << mile.trav_time() << endl; // mile ���� ���
	cout << "Km ����: " << km.trav_time() << endl; // km ���� ���
	return 0;
}