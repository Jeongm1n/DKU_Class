#include <stdio.h>

void getSmall(int* numA, int* numS, int n);

int main()
{
	int i;
	int index = 6;
	int numA[6];
	int numS[6] = { 0,0,0,0,0,0 };

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &numA[i]);
	}

	getSmall(numA, numS, index);

	for (i = 0; i < 6; i++)
	{
		printf("%d ", numS[i]);
	}

	return 0;
}

void getSmall(int* numA, int* numS, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (*(numA + i) > *(numA + j))
				numS[i]++;
		}
	}
}