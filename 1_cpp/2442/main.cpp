#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, i, j;
	cin >> N;
	for (i = 0; i < N; ++i) {
		for (j = N - i-1; j > 0; --j)
			cout << ' ';
		for (j = 0; j<i*2+1; ++j)
			cout << '*';
		cout << '\n';
	}
	return 0;
}