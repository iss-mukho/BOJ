#include <iostream>
#include <string>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, len;
	string N;
	while(true) {
		cin >> N;
		if (stoi(N) == 0)
			break;
		len = N.length() + 1;
		for (i = 0; i < N.length(); ++i) {
			switch (N[i]) {
			case '0':
				len += 4;
				break;
			case '1':
				len += 2;
				break;
			default:
				len += 3;
				break;
			}
		}
		cout << len << '\n';
	}
	return 0;
}