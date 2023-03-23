#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	cin.ignore();
	for (int i = 0; i < T; i++) {
		string tc;
		getline(cin, tc);
		int score = 0;
		int cnt = 0;
		char comp = 'O';
		for (int j = 0; j < tc.length(); j++) {
			if (tc[j] == comp) {
				cnt++;
				score += cnt;
			}
			else
				cnt = 0;
		}
		cout << score << '\n';
		score = 0;
	}

	return 0;
}