#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	int i;
	int cnt = 1;

	gets(a);

	printf("%d. ", cnt);
	for (i = 0; i<strlen(a); i++)
	{
		if (a[i] == ' ')
		{
			cnt++;
			printf("\n%d. ", cnt);
		}
		¤±
		printf("%c", a[i]);
	}

	return 0;
}