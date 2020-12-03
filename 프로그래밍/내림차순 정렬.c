#include<stdio.h>

int main()
{
	int a[20];
	int n;
	int i, j,k,l;
	int temp;
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	for (j = 0; j < i; j++)
	{
		for(l=0; l<i-1;l++ )
		if (a[l] < a[l + 1])
		{
			temp = a[l];
			a[l] = a[l+1];
			a[l+1] = temp;
		}
	}

	for(k=0; k<n; k++)
		printf("%d\n", a[k]);

	return 0;
}