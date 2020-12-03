#include<stdio.h>

int main()
{
	char a[100];
	int i, n,len;

	scanf("%s %d", a, &n);
	for (i = 0; a[i]; i++)
	{
		len = i+1;
	}

	for (i = len-1; i >= len-n; i--)
	{
		printf("%c", a[i]);
	}

	return 0;
}