#include<stdio.h>

void fn()
{
	printf("@@@@@@@@@@\n");
}

int main()
{
	printf("첫번째\n");
	fn();
	printf("두번째\n");
	fn();
	printf("세번째\n");
	fn();

	return 0;
}