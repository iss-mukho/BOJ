#include <iostream>
#include <string>
using namespace std;
string input[8];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, cnt = 0;
	for (i = 0; i < 8; ++i)
		cin >> input[i];
	for (i = 0; i < 8; ++i) {
		for (j = 0; j < 8; ++j) {
			if (i % 2 == 0) {
				if (j % 2 == 0)
					if (input[i][j] == 'F')
						++cnt;
			}
			else {
				if (j % 2 != 0)
					if (input[i][j] == 'F')
						++cnt;
			}	
		}
	}
	cout << cnt << '\n';
	return 0;
}