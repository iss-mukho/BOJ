#include <iostream>
using namespace std;

const int MAX = 41;

int dp[MAX][2];
int T, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[0][0] = 1; dp[1][1] = 1;
	dp[2][0] = 1; dp[2][1] = 1;

	for (int i = 3; i < MAX; ++i) {
		dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
		dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
	}

	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << dp[N][0] << ' ' << dp[N][1] << '\n';
	}

	return 0;
}