#include <iostream>

using namespace std;

int main() {
	int num, count = 0;
	int *p;

	cout << "�迭�� ũ�� : ";
	cin >> num;

	p = new int[num];
	cout << "5���� �� �Է� : ";
	for (int i = 0; i < num; i++) {
		cin >> p[i];
	}

	for (int i = 0; i < num; i++) {
		count = 0;
		for (int j = 0; j < num; j++) {
			if (p[i] > p[j])
				count++;
		}
		cout << p[i] << " --> " << count << endl;
	}

	delete[num] p;
	return 0;
}