/* 일련의 부동 소수 값들의 평균을 구하는 avg()라는 함수를 작성하여라. 이 함수는 2개의 인수를 가진다
. 첫번째 인수는 수들을 포함하는 배열에 대한 포인터이고, 두번째 인수는 배열의 크기를 나타내는 정수값이다. 
이 함수를 사용하기 위한 프로그램도 작성하여라.*/

#include<iostream>
using namespace std;

double avg(double *_decimal, int n);

int main()
{
	double decimal[3] = { 1.1, 2.2, 3.3 };

	cout << avg(decimal, 3) << endl;
}

double avg(double *_decimal, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += _decimal[i];

	return sum / n;

}