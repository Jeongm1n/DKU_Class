#include<iostream>
using namespace std;

int main()
{
	char str[80][80];
	int big = 0;
	int small = 0;
	for (int i = 0; i < 80; i++)
	{
		gets_s(str[i]);
		if (!str[i][0])
			break;
	}
	for (int i = 0; str[i][0]; i++)
	{
		for (int j = 0; str[i][j]; j++)
		{
			if (str[i][j] >= 'A'&&str[i][j] <= 'Z')
				big++;
			else if (str[i][j] >= 'a'&&str[i][j] <= 'z')
				small++;
		}
	}
	cout << big << " " << small << endl;

	return 0;
}