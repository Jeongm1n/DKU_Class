#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* a; //�����ͺ�������
    int size_a, i, j, cnt; //��������

    printf("�迭��ũ�⸦�Է��Ͻÿ�: ");
    scanf_s("%d", &size_a); //�迭ũ���Է¹ޱ�

    a = (int*)malloc(size_a * sizeof(int)); //�����޸𸮸��Ҵ��ϱ����ؼ�malloc�Լ����

    printf("�������Է��Ͻÿ�: ");
    for (i = 0; i < size_a; i++)
        scanf_s("%d", &a[i]); // �迭ũ�⸸ŭ�����Է�

    printf("�ߺ���������������: ");

    for (i = 0; i < size_a; i++)
    {
        cnt = 0; //�񱳸��Ź��ϱ�����for���ȿ���cnt��0�����ʱ�ȭ
        for (j = 0; j < size_a; j++) //�����񱳸���������for��
        {
            if (a[i] == a[j])
            {
                cnt++; //if�������ǿ������ϸ�cnt �ø���
            }
        }
        if (cnt == 1) //�ߺ��Ǵ�������������cnt��1�̱⿡�̿Ͱ������ǹ�����
        {
            printf("%d ", a[i]); //�ߺ������ʴ��������
        }
    }
    printf("\n");

    free(a); //�����޸�����

    return 0;
}