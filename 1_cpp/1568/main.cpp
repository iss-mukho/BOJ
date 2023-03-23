#include <iostream>
using namespace std;
int main() {
	int N, K = 1, t = 0;
	cin >> N;
	while (N > 0) {
		if (N < K) {
			K = 1;
		}
		N -= K;
		++K;
		++t;
	}
	cout << t << '\n';
	return 0;
}