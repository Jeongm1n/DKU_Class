#include<stdio.h>

struct point
{
	double x, y;
}f, m;
int main()
{
	printf("아버지의 키와 몸무게는 ? ");
	scanf("%lf %lf", &f.x, &f.y);
	printf("어머니의 키와 몸무게는 ? ");
	scanf("%lf %lf", &m.x, &m.y);

	printf("학생의 키 : %.f\n", ((f.x + m.x) / 2) + 5);
	printf("학생의 몸무게 : %.1f\n", ((f.y + m.y) / 2) - 4.5);

	return 0;
}