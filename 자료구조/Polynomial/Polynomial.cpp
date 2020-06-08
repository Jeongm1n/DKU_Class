#include "StdAfx.h"
#include "Polynomial.h"
#include "Term.h"

#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Polynomial::Polynomial(void)
{
	capacity = 4;
	terms = 0;
	termArray = new Term[capacity];  // 크기 4 로 배열 생성
}

Polynomial::~Polynomial(void)
{

}

Polynomial Polynomial::Add(Polynomial b)
// a(x)(*this의 값)와 b(x)를 더한 결과를 반환한다.
{
	Polynomial c;
	int aPos = 0, bPos = 0;

	while ((aPos < terms) && (bPos < b.terms))
		if (termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}

	// A(x)(*this)의 나머지 항들을 추가한다.
	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);

	// B(x)의 나머지 항들을 추가한다.
	for (; bPos < b.terms; bPos++)
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

	return c;
} // Add의 끝


void Polynomial::NewTerm(const float theCoeff, const int theExp)
// 새로운 항을 termArray 끝에 첨가한다.
{
	int i;
	if (terms == capacity)
	{//termArray의 크기를 두 배로 확장
		capacity *= 2;
		Term* temp = new Term[capacity];           // 새로운 배열
		for (int i = 0; i < terms; i++)
			temp[i] = termArray[i];
		delete[] termArray;                       // 그전 메모리를 반환
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}
void Polynomial::Print()
{
	int i;

	cout << "\n";
	cout << "<< 다항식의 곱셈 결과 >>" << endl;
	if (terms) {
		for (i = 0; i < terms - 1; i++)
			cout << termArray[i].coef << " x^" << termArray[i].exp << " + ";
		// 마지막 항을 출력
		cout << termArray[i].coef << " x^" << termArray[i].exp << "\n";
	}
	else
		cout << " No terms ";

}
Polynomial Polynomial::Multiply(Polynomial b)
{
	Polynomial c;                                                    // 결과를 저장할 c객체 생성
	int aPos, bPos, i;
	cout << "\n"<< "<< A의 다항식 >>" << endl;
	for (i = 0; i < terms - 1; i++)
		cout << termArray[i].coef << " x^" << termArray[i].exp << " + ";
	cout << termArray[i].coef << " x^" << termArray[i].exp << "\n";
	cout << "<< B의 다항식 >>" << endl;
	for (i = 0; i < b.terms - 1; i++)
		cout << b.termArray[i].coef << " x^" << b.termArray[i].exp << " + ";
	cout << b.termArray[i].coef << " x^" << b.termArray[i].exp << "\n";
	for (aPos = 0; aPos < terms; aPos++)                             // 다항식 A 항의 수만큼 반복
	{
		Polynomial box;                                              // 곱셈을 저장할 box객체 생성
		for (bPos = 0; bPos < b.terms; bPos++)                       // 다항식 B 항의 수만큼 반복
		{
			float f = termArray[aPos].coef * b.termArray[bPos].coef; // 계수의 곱셈
			int e = termArray[aPos].exp + b.termArray[bPos].exp;     // 지수의 덧셈
			box.NewTerm(f, e);                                       // 계산된 계수와 지수를 객체 box에 저장
		}
		c = c.Add(box);                                              // 이후 값들을 c에 누적 덧셈
	}
	return c;                                                        // 결과가 저장된 c 객체 반환
}