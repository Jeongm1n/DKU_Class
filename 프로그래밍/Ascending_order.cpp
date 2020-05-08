#include<stdio.h>

int main()
{
	int n, temp = 0;
	int a[100];

	while (1)
	{
		printf("정렬할 정수의 수를 입력하시오(종료 시 -1 입력) : ");
		scanf_s("%d", &n); // 정렬할정수의수입력

		if (n == -1) // n이-1 이면
		{
			printf("프로그램을종료합니다.\n");
			break; // 프로그램종료
		}

		printf("%d개의 정수를 입력하시오: ", n);
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &a[i]);
		} // 한 번 실행이 끝나면 다시 정렬할 정수 입력

		for (int i = 0; i < n; i++) // 정렬할 정수의 수까지 for문실행
		{
			for (int j = 0; j < n - 1; j++) // j < n 까지면 a[j+1]에서 a[n+1]이 되기에 j< n-1로 조건식을 충족
			{
				if (a[j] > a[j + 1])
				{
					temp = a[j]; 
					a[j] = a[j + 1];       // 오름차순 정렬
					a[j + 1] = temp; 
				}
			}
		}

		printf("정렬의 결과: ");
		for (int i = 0; i < n; i++) // 정렬할 정수의 수까지 for문 실행
		{
			printf("%d ", a[i]); // 오름차순 정렬 출력
		}
		printf("\n");
	}

	return 0;
}