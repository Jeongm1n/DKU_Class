/* �Ϸ��� �ε� �Ҽ� ������ ����� ���ϴ� avg()��� �Լ��� �ۼ��Ͽ���. �� �Լ��� 2���� �μ��� ������
. ù��° �μ��� ������ �����ϴ� �迭�� ���� �������̰�, �ι�° �μ��� �迭�� ũ�⸦ ��Ÿ���� �������̴�. 
�� �Լ��� ����ϱ� ���� ���α׷��� �ۼ��Ͽ���.*/

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