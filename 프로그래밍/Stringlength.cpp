#include<stdio.h>

int main()
{
	char ch[1024];
	int i;
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(ch); // ���ڿ� �Է� �ޱ�

	for (i = 0; ch[i]; i++); // ���ڿ� ���� üũ

	printf("�Է��Ͻ� ���ڿ��� ���̴� %d �Դϴ�.\n", i);

	return 0;
}