#include <iostream>
using namespace std;
int main() {
	int N, i, j;
	cin >> N;
	for (i = 1; i <= N; ++i) {
		for (j = i - 1; j < N - 1; ++j)
			cout << ' ';
		cout << "*";
		if (i != 1) {
			for (j = 0; j < 2 * i - 3; ++j) {
				if (j % 2 == 0)
					cout << " ";
				else
					cout << "*";
			}
			cout << "*";
		}
		cout << '\n';
	}
}