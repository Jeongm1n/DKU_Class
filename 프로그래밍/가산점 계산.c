#include<stdio.h>

int main()
{
	int gender, married, child, army;
	int plus = 0;
	printf("남자면 1, 여자면 2를 입력하세요 : ");
	scanf("%d", &gender);

	if (gender == 2)
	{
		printf("기혼이면 1, 미혼이면 2를 입력하세요 : ");
		scanf("%d", &married);
		if (married == 1)
		{
			plus++;
			printf("자녀가 한명이면 1, 자녀가 둘 이상이면 2를 입력하세요 : ");
			scanf("%d", &child);
			if (child == 1)
				plus++;
			else
				plus += 2;
		}
	}
	else
	{
		printf("군필이면 1, 미필이면 2를 입력하세요: ");
		scanf("%d", &army);
		if (army == 1)
		{
			plus++;
			printf("기혼이면 1, 미혼이면 2를 입력하세요 : ");
			scanf("%d", &married);
			if (married == 1)
				plus++;
		}
	}

	printf("총 가산점은 %d점 입니다.\n", plus);
	return 0;
}