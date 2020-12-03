#include <stdio.h>

int main()
{
	int a, b, i, j, k;

	scanf_s("%d %d", &a, &b);


	for (i = 1; i<10; i++) 
	{
		if (a>b) {
			k = a;
			for (j = 1; j<a - b + 2; j++)
			{
				printf("%d * %d = %2d   ", k, i, k*i);
				k--;
			}

			printf("\n");
		}

		else if (b>a) {
			k = a;
			for (j = 1; j<b - a + 2; j++)
			{
				printf("%d * %d = %2d   ", k, i, k*i);
				k++;
			}

			printf("\n");
		}

		else
			printf("%d * %d = %2d\n", a, i, a*i);
	}
	return 0;
}