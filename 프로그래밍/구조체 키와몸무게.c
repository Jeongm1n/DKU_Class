#include<stdio.h>

struct point
{
	double x, y;
}f, m;
int main()
{
	printf("�ƹ����� Ű�� �����Դ� ? ");
	scanf("%lf %lf", &f.x, &f.y);
	printf("��Ӵ��� Ű�� �����Դ� ? ");
	scanf("%lf %lf", &m.x, &m.y);

	printf("�л��� Ű : %.f\n", ((f.x + m.x) / 2) + 5);
	printf("�л��� ������ : %.1f\n", ((f.y + m.y) / 2) - 4.5);

	return 0;
}