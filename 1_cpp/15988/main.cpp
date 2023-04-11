// 백준 15988: 1, 2, 3 더하기 3(실버 II), https://www.acmicpc.net/problem/15988
#include <iostream>
using namespace std;

const long long INF = 1000000009;
const int MAX = 1000001;

int T, N;
long long dp[MAX];

void calcDp() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < MAX; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % INF;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	calcDp();

	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N] << '\n';;
	}

	return 0;
}
