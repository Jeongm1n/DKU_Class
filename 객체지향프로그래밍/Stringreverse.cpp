#include <iostream>

using namespace std;
void strrevattach(char *to, const char *from);
int main() {
	char str1[20] = "Hi ";
	char str2[80] = "hello";
	strrevattach(str1, str2);
	cout << str1;
}
void strrevattach(char *to, const char *from)
{
	int str2_len = 0;
	int str1_len = 0;
	char tmp[80];
	for (int i = 0; from[i]; i++)
		str2_len++;
	for (int i = 0; to[i]; i++)
		str1_len++;
	for (int i = 0; from[i]; i++)
	{
		tmp[str2_len - i - 1] = from[i];
	}
	tmp[str2_len] = '\0';
	for (int i = 0; from[i]; i++)
	{
		to[str1_len + i] = tmp[i];
	}
	to[str1_len + str2_len] = '\0';
}