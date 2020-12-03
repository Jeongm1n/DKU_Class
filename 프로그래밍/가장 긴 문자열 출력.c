#include<stdio.h>
#include<string.h>
int main()
{
	char *arr[5];
	char str[5][80];
	int p, index;
	int i;
	char a[1024];

	for (i = 0; i<5; i++)
	{
		gets(str[i]);
		arr[i] = str[i];
	}

	p = strlen(str[0]);

	for (i = 1; i<5; i++)
	{
		if (strlen(str[i])>p)
		{
			p = strlen(str[i]);
			index = i;
		}
	}

	printf("%s\n", str[index]);//arr도되는데..

	return 0;
}