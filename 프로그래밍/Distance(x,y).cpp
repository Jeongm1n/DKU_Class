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
    int y2 = 0; // 변수 선언, 초기화

    for (i = 0; i < 5; i++)
    {
        printf("x, y 좌표를입력하세요: ");
        scanf_s("%d %d", &p[i].x, &p[i].y); // 5개의 좌표 입력
    }

    min = sqrt(pow(p[0].x - p[1].x, 2) + pow(p[0].y - p[1].y, 2)); // 첫 번째 좌표, 두 번째 좌표 거리 구하여 min 초기화

    x1 = p[0].x;
    y1 = p[0].y;
    x2 = p[1].x;
    y2 = p[1].y; // 좌표 초기화

    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j <= 4; j++)
        {
            dist = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2)); // 각 좌표의 거리구하기

            if (min > dist) // dist 가 min 보다 작으면 
            {
                min = dist; //min에 dist 저장

                x1 = p[i].x;
                y1 = p[i].y;
                x2 = p[j].x;
                y2 = p[j].y; // min에 해당하는 좌표 값 저장
            }
        }
    }

    printf("가장 가까운 두 좌표값은(%d, %d), (%d, %d)이며, 길이는 %.2f 입니다.\n", x1, y1, x2, y2, min); // 출력

    return 0;
}