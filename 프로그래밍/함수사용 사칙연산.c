#include<stdio.h>

void fn(int a, char b, int c)
{
	if (b == '+')
		printf("%d + %d = %d\n", a, c, a + c);
	else if (b == '-')
		printf("%d - %d = %d\n", a, c, a - c);
	else if (b == '*')
		printf("%d * %d = %d\n", a, c, a*c);
	else
		printf("%d / %d = %d\n", a, c, a / c);

}

int main()
{
	int m, n;
	char c;

	scanf_s("%d %c %d", &m, &c, &n);

	fn(m, c, n);

	return 0;
}