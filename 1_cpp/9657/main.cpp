// 백준 9657: 돌 게임 3(실버 III), https://www.acmicpc.net/problem/9657
#include <iostream>
using namespace std;

const int MAX = 1001;

int main() {
	int dp[MAX];
	fill_n(dp, MAX, 0);

	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= N; ++i) {
		if (dp[i - 1] == 0) {
			dp[i] = 1;
			continue;
		}
		if (dp[i - 3] == 0) {
			dp[i] = 1;
			continue;
		}
		if (dp[i - 4] == 0) {
			dp[i] = 1;
			continue;
		}
		dp[i] = 0;
	}

	cout << ((dp[N] == 1) ? "SK" : "CY") << '\n';

	return 0;
}
