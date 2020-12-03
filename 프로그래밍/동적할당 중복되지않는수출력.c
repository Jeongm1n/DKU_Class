#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a; //포인터 변수 선언
	int size_a, i, j, cnt; //변수 선언

	printf("배열의 크기를 입력하시오: ");
	scanf("%d", &size_a); //배열 크기 입력 받기

	a = (int*)malloc(size_a * sizeof(int)); //동적 메모리를 할당하기 위해서 malloc함수 사용

	printf("정수를 입력하시오: ");
	for (i = 0; i < size_a; i++)
		scanf("%d", &a[i]); // 배열 크기만큼 정수 입력

	printf("중복되지 않은 정수들: ");

	for (i = 0; i < size_a; i++)
	{
		cnt = 0; //비교를 매번 하기위해 for문 안에서 cnt를 0으로 초기화
		for (j = 0; j < size_a; j++) //정수 비교를 위한 이중for문
		{
			if (a[i] == a[j])
			{
				cnt++; //if문의 조건에 만족하면 cnt 늘리기
			}
		}
		if (cnt == 1) //중복되는 정수가 없으면 cnt가 1이기에 이와 같이 조건문 설정
		{
			printf("%d ", a[i]); //중복되지 않는 정수 출력
		}
	}
	printf("\n");

	free(a); //동적메모리 해제

	return 0;
}