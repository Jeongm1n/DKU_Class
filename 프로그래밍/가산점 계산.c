#include<stdio.h>

int main()
{
	int gender, married, child, army;
	int plus = 0;
	printf("���ڸ� 1, ���ڸ� 2�� �Է��ϼ��� : ");
	scanf("%d", &gender);

	if (gender == 2)
	{
		printf("��ȥ�̸� 1, ��ȥ�̸� 2�� �Է��ϼ��� : ");
		scanf("%d", &married);
		if (married == 1)
		{
			plus++;
			printf("�ڳడ �Ѹ��̸� 1, �ڳడ �� �̻��̸� 2�� �Է��ϼ��� : ");
			scanf("%d", &child);
			if (child == 1)
				plus++;
			else
				plus += 2;
		}
	}
	else
	{
		printf("�����̸� 1, �����̸� 2�� �Է��ϼ���: ");
		scanf("%d", &army);
		if (army == 1)
		{
			plus++;
			printf("��ȥ�̸� 1, ��ȥ�̸� 2�� �Է��ϼ��� : ");
			scanf("%d", &married);
			if (married == 1)
				plus++;
		}
	}

	printf("�� �������� %d�� �Դϴ�.\n", plus);
	return 0;
}