#include<stdio.h>

int main()
{
	int i, index;
	int a[100];
	int cnt = 0;
	for (i = 0; i < 100; i++)
	{
		fscanf(stdin, "%d", &a[i]);
		if (a[i] == 0)
			break;
	}

	for (i = 0; i < 100; i++)
	{
		if (a[i] % 3 == 0 && a[i] % 5 == 0&&a[i] != 0)
		{
			index = i;
			fprintf(stdout, "%d ", a[index]);
			cnt++;
		}
	}
	
	fprintf(stdout, "\n%d°³\n", cnt);

	return 0;
}