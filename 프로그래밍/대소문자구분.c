#include<stdio.h>

int main()
{
	char ch;
	int i;
	printf("�����ڸ� �Է��Ͻÿ� : ");
	for (i = 1; i <= 5; i++)
	{
		scanf("%c", &ch);

		if (ch >= 'a'&&ch <= 'z')
		{
			printf("�ҹ����Դϴ�.\n");
			fflush(stdin);
		}

		else if (ch >= 'A'&&ch <= 'Z')
		{
			printf("�빮���Դϴ�.\n");
			fflush(stdin);
		}
		else
		{
			printf("�����ڰ� �ƴմϴ�.\n");
			fflush(stdin);
		}
	}
	return 0;
}