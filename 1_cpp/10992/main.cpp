#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int N, i, j;
	cin >> N;
	for (i = 1; i <= N; ++i) {
		for (j = i - 1; j < N - 1; ++j)
			cout << ' ';
		cout << "*";
		if (i != 1) {
			if (i == N)
				for (j = 0; j <= 2 * i - 3; ++j)
					cout << "*";
			else {
				for (j = 0; j < 2 * i - 3; ++j)
					cout << " ";
				cout << "*";
			}
		}
		cout << '\n';
	}
}