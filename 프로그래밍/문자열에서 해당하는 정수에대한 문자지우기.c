#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	int i, n;
	scanf("%s", a);
	while (1)
	{
		scanf("%d", &n);
		if (n<strlen(a))
		{
			for (i = n - 1; a[i]; i++)
				a[i] = a[i + 1];
		}

		printf("%s", a);

		if (strlen(a) == 1)
			break;
	}
	return 0;
}