#include<stdio.h>

int main()
{
	char ch[1024];
	int i;
	int cnt = 0;
	printf("���ڿ��� �Է��Ͻÿ� : ");
	gets(ch);
	
	for (i = 0; *(ch + i); i++)
		cnt++;

	printf("�Է��Ͻ� ���ڿ��� ���̴� %d �Դϴ�.\n", cnt);

	return 0;
}
