#include <iostream>
using namespace std;
int main() {
	int N, i, j;
	cin >> N;
	for (i = 1; i <= N; ++i) {
		for (j = 0; j < i; ++j)
			cout << "*";
		cout << '\n';
	}
	for (i -= 2; i >= 1; --i) {
		for (j = 0; j < i; ++j)
			cout << "*";
		cout << '\n';
	}
	return 0;
}