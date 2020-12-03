#include<stdio.h>
#include<conio.h>//kbhit 함수를 위한 헤더 파일
#include<stdlib.h>//exit 함수를 위한 헤더 파일
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
	printf("\n프로그램을 종료합니다!\n");
	exit(0);

end:
	printf("\n키보드를 눌렀습니다!\n");

	return 0;
}