#include<stdio.h>

struct point
{
	int x, y;
	int x1, y1;
}p1, p2;

int main()
{
	scanf("%d %d %d %d", &p1.x, &p1.y, &p1.x1, &p1.y1);
	scanf("%d %d %d %d", &p2.x, &p2.y, &p2.x1, &p2.y1);

	p1.x = p1.x < p2.x ? p1.x : p2.x;
	p1.y = p1.y < p2.y ? p1.y : p2.y;
	p1.x1 = p1.x1 > p2.x1 ? p1.x1 : p2.x1;
	p1.y1 = p1.y1 > p2.y1 ? p1.y1 : p2.y1;

	printf("%d %d %d %d\n", p1.x, p1.y, p1.x1, p1.y1);

	return 0;
}