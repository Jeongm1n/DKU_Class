#include<stdio.h>

int main() 
{
	int i;
	int a = 0, b= 0;
	char input[1024];

	printf("�׽�Ʈ ������ : ");
	gets(input);

	for (i = 0; input[i]; i++) 
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			input[i] += 32;
			a++;
		}
		else if (input[i] >= 'a' && input[i] <= 'z')
		{
			input[i] -= 32;
			b++;
		}
	}
	printf("��� : %s", input);
	printf("\n�ҹ��� ���� : %d\n�빮�� ���� : %d\n", a, b);

	return 0;
}