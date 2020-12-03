#include<stdio.h>

int fn(int x, int y, int z)
{
	int tot = 0;

	tot = x + y + z;

	return tot;
}

int main()
{
	int i, j;
	int stu[3][3];
	int total[3] = { 0,0,0 };

	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			scanf_s("%d", &stu[i][j]);
		}
		total[i] = fn(stu[i][0], stu[i][1], stu[i][2]);
	}

	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			printf("%d ", stu[i][j]);
		}
		printf("%d\n", total[i]);
	}

	return 0;
}