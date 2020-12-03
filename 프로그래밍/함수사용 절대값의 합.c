#include<stdio.h>
#include<math.h>
/*
void fn_input(int irg[])
{
	int i;
	for (i = 0; i < 5; i++)
		scanf_s("%d", &irg[i]);
}
int fn_sum(int irg[])
{
	int i;
	int i_sum = 0;
	for (i = 0; i < 5; i++)
		i_sum += abs(irg[i]);
	return i_sum;
}
int main()
{
	int irg[5];
	int i_sum = 0;
	fn_input(irg);
	i_sum = fn_sum(irg);
	printf("%d\n", i_sum);

	return 0;
}*/
/*
int fn(int a[])
{
	int i, j;
	int total = 0;
	for (i = 0; i < 5; i++)
		scanf_s("%d", &a[i]);

	for (j = 0; j < 5; j++)
	{
		if (a[j] < 0)
		{
			a[j] = -a[j];
		}
		total += a[j];
	}

	return total;
}

int main()
{
	int a[5];
	int result;

	result = fn(a);

	printf("%d\n", result);

	return 0;
}*/

int fn(int a[])
{
	int j;
	int total = 0;

	for (j = 0; j < 5; j++)
	{
		if (a[j] < 0)
		{
			a[j] = -a[j];
		}
		total += a[j];
	}

	return total;
}

int main()
{
	int a[5];
	int i;
	int result;
	
	for (i = 0; i < 5; i++)
		scanf_s("%d", &a[i]);

	result = fn(a);

	printf("%d\n", result);

	return 0;
}