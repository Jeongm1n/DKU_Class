#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* a; //포인터변수선언
    int size_a, i, j, cnt; //변수선언

    printf("배열의크기를입력하시오: ");
    scanf_s("%d", &size_a); //배열크기입력받기

    a = (int*)malloc(size_a * sizeof(int)); //동적메모리를할당하기위해서malloc함수사용

    printf("정수를입력하시오: ");
    for (i = 0; i < size_a; i++)
        scanf_s("%d", &a[i]); // 배열크기만큼정수입력

    printf("중복되지않은정수들: ");

    for (i = 0; i < size_a; i++)
    {
        cnt = 0; //비교를매번하기위해for문안에서cnt를0으로초기화
        for (j = 0; j < size_a; j++) //정수비교를위한이중for문
        {
            if (a[i] == a[j])
            {
                cnt++; //if문의조건에만족하면cnt 늘리기
            }
        }
        if (cnt == 1) //중복되는정수가없으면cnt가1이기에이와같이조건문설정
        {
            printf("%d ", a[i]); //중복되지않는정수출력
        }
    }
    printf("\n");

    free(a); //동적메모리해제

    return 0;
}