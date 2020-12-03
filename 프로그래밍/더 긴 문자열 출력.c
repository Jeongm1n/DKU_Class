#include<stdio.h>
#include<string.h>

int main()
{
	char a[1024];
	char b[1024];

	scanf("%s %s", a, b);

	if (strlen(a)>strlen(b))
		puts(a);
	else
		puts(b);

	return 0;

}