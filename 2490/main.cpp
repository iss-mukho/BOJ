#include <iostream>
using namespace std;
int main() {
	int i, j, input, cnt = 0;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; ++j) {
			cin >> input;
			cnt += input;
		}
		switch (cnt) {
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "C\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "A\n";
			break;
		case 4:
			cout << "E\n";
			break;
		}
		cnt = 0;
	}
	return 0;
}