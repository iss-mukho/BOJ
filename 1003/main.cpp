#include <iostream>
using namespace std;
int main() {
	int T, N, i, j;
	int fibo[41][2] = {0, };
	fibo[0][0] = 1;
	fibo[1][1] = 1;
	cin >> T;
	for (i = 0; i < T; ++i) {
		cin >> N;
		if (N >= 2)
			for (j = 2; j <= N; j++) {
				fibo[j][0] = fibo[j - 2][0] + fibo[j - 1][0];
				fibo[j][1] = fibo[j - 2][1] + fibo[j - 1][1];
			}
		cout << fibo[N][0] << ' ' << fibo[N][1] << '\n';
	}
	return 0;
}
