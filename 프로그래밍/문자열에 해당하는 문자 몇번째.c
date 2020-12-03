#include <stdio.h>

int main()
{
	char a[100], c;
	int i;

	scanf("%s %c", a, &c);


	for (i = 0; a[i]; i++)
	{
		if (a[i] == c)
		{
			printf("%d", i);
			break;
		}
		
	}

	return 0;
}