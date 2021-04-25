#include <iostream>
using namespace std;
int main() {
	int i, N, sum=0, minNum=101;
	for (i = 0; i < 7; ++i) {
		cin >> N;
		if (N % 2 == 1) {
			sum += N;
			if (N < minNum)
				minNum = N;
		}
	}
	if (sum)
		cout << sum << '\n' << minNum << '\n';
	else
		cout << -1 << '\n';
	return 0;
}