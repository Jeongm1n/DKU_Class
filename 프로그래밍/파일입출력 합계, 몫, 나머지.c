#include<stdio.h>

int main()
{
	int a, b, c;

	fscanf(stdin, "%d %d %d", &a, &b, &c);

	fprintf(stdout, "%d %d...%d", a + b + c, (a + b + c) / 3, (a + b + c) % 3);
	return 0;
}