#include<stdio.h>

int main()
{
	int a[10];
	int* p[10] = { NULL };
	int i;
	int cnt = 0;
	int cnt1 = 0;

	for (i = 0; i<10; i++)
	{
		p[i] = &a[i];
		scanf("%d", &a[i]);
	}
	for (i = 0; i<10; i++)
	{
		if (*p[i] % 2 == 0)
			cnt++;
		else
			cnt1++;
	}
	printf("Â¦¼ö : %d°³\n", cnt);
	printf("È¦¼ö : %d°³\n", cnt1);

	return 0;
}