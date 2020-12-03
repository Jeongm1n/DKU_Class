#include<stdio.h>

int fn(int a)
{
	char ch[] = "~!@#$^&*()_+|";
	int i;
	for (i = 0; i < a; i++)
	{
		printf("%s\n", ch);
	}
}

int main()
{
	int n;

	scanf_s("%d", &n);

	fn(n);

	return 0;
}