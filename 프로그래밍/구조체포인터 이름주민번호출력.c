#include<stdio.h>
struct person
{
	char name[20];
	char pID[20];
	struct person *frnd;
};

int main()
{
	struct person man1 = { "Mr. Lee", "820204-0000512" };
	struct person man2 = { "Mr. Lee's Friend", "820000-0000101" };

	man1.frnd = &man2;

	printf("[Mr. Lee]\n");
	printf("name: %s\n", man1.name);
	printf("pID: %s\n", man1.pID);

	printf("[His Friend]\n");
	printf("name: %s\n", man1.frnd->name);
	printf("pID: %s\n", man1.frnd->pID);

	return 0;
}