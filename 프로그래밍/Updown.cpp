#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(NULL));
	int n = rand() % 100 + 1; // 게임의 정답인 정수를 저장하기 위한 변수 n
	int i; // 정답을 맞추기 위해 입력을 받기 위한 변수 i
	int cnt = 0; // 시행횟수를 늘리기 위한 변수 cnt 초기화



	printf("\n하나의 수를 입력하시오: ");
	scanf_s("%d", &i); // 정답을 맞추기 위한 정수 입력

	while (1) // 정답과 같은 수를 입력 받을 때까지 무한루프 실행
	{

		if (i < n) // 정답보다 작은 수를 입력했으면
		{
			cnt++; // 시행횟수 1회 씩 늘리기
			printf("\n더 큰 수를 입력하시오: ");
			scanf_s("%d", &i); // 다른 정수 다시 입력
		}

		else if (i > n) // 정답보다 큰 수를 입력했으면
		{
			cnt++; // 시행횟수 1회 씩 늘리기
			printf("\n더 작은 수를 입력하시오: ");
			scanf_s("%d", &i); // 다른 정수 다시 입력
		}

		else // 정답과 같은 수를 입력했으면
		{
			cnt++; // 시행횟수 1회 늘리기
			printf("\n\n맞습니다.\n"); // "맞습니다." 문장출력
			break; // 무한루프종료
		}

	}
	printf("시행횟수는%d 번입니다.\n\n", cnt); // 시행횟수문장출력

	return 0;

}