/*1000과 2000 사이에 있는 모든 소수(prime number)를 찾는 프로그램을 작성하여라.*/
/*#include<iostream>
using namespace std;
int _Primenum(int);
int main()
{

	for (int i = 1000; i <= 2000; i++) // 1000부터 2000까지
	{
		if (_Primenum(i) == 1)         //_Primenum(i) 가 1일 경우가 소수임을 표현
			cout << i << "\t";         // 소수 출력
	}
}
int _Primenum(int n)                 
{ 
	for (int i = 2; i < n; i++)  // 2부터 하나 작은 숫자까지
	{
		if (n%i == 0)            // 2부터 하나 작은 숫자 중에서 나눠지는 수가 있다면
			return 0;            // 0을 반환
	}
	return 1;                    // 반복문에서 0을 반환하지 않았다면 1을 반환
}*/