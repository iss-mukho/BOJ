#include <iostream>
using namespace std;
int music[8];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int sg, i, check;
	for (i = 0; i < 8; ++i) 
		cin >> music[i];
	if (music[0] == 1) {
		check = 1;
		for (i = 1; i < 8; ++i) {
			if (music[i] != i + 1) {
				check = 0;
				break;
			}
		}
	}
	else if (music[0] == 8) {
		check = 2;
		for (i = 1; i < 8; ++i) {
			if (music[i] != 8 - i) {
				check = 0;
				break;
			}
		}
	}
	else
		check = 0;
	switch (check) {
	case 0:
		cout << "mixed\n";
		break;
	case 1:
		cout << "ascending\n";
		break;
	default:
		cout << "descending\n";
		break;
	}
	return 0;
}