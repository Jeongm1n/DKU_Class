#include<stdio.h>
#include<conio.h>//kbhit �Լ��� ���� ��� ����
#include<stdlib.h>//exit �Լ��� ���� ��� ����
int main()
{
	int i, j;
	
	for(i=1; i<9999; i++)
	{
		for(j=1; j<=20; j++)
		{
			if(kbhit()) goto end;
			printf("*");
		}
		printf("\n");
	}
	printf("\n���α׷��� �����մϴ�!\n");
	exit(0);

end:
	printf("\nŰ���带 �������ϴ�!\n");

	return 0;
}