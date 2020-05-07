#include<stdio.h>
#include<math.h>

struct point
{
    int x, y;
};

int main(void)
{
    struct point p[5];
    double dist;
    double min;
    int i, j;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0; // ���� ����, �ʱ�ȭ

    for (i = 0; i < 5; i++)
    {
        printf("x, y ��ǥ���Է��ϼ���: ");
        scanf_s("%d %d", &p[i].x, &p[i].y); // 5���� ��ǥ �Է�
    }

    min = sqrt(pow(p[0].x - p[1].x, 2) + pow(p[0].y - p[1].y, 2)); // ù ��° ��ǥ, �� ��° ��ǥ �Ÿ� ���Ͽ� min �ʱ�ȭ

    x1 = p[0].x;
    y1 = p[0].y;
    x2 = p[1].x;
    y2 = p[1].y; // ��ǥ �ʱ�ȭ

    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j <= 4; j++)
        {
            dist = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2)); // �� ��ǥ�� �Ÿ����ϱ�

            if (min > dist) // dist �� min ���� ������ 
            {
                min = dist; //min�� dist ����

                x1 = p[i].x;
                y1 = p[i].y;
                x2 = p[j].x;
                y2 = p[j].y; // min�� �ش��ϴ� ��ǥ �� ����
            }
        }
    }

    printf("���� ����� �� ��ǥ����(%d, %d), (%d, %d)�̸�, ���̴� %.2f �Դϴ�.\n", x1, y1, x2, y2, min); // ���

    return 0;
}