// 백준 1006: 습격자 초라기(플래티넘 III), https://www.acmicpc.net/problem/1006
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 210000000;

int enemy[2][10001];
int dp[10001][3];
int T, N, W;

void process() {
	for (int i = 2; i <= N; ++i) {
		int up = (enemy[0][i - 1] + enemy[0][i] <= W) ? 1 : 2;
		int down = (enemy[1][i - 1] + enemy[1][i] <= W) ? 1 : 2;
		int v = (enemy[0][i] + enemy[1][i] <= W) ? 1 : 2;

		dp[i][0] = min(min(dp[i - 1][0] + v, dp[i - 2][0] + up + down), min(dp[i - 1][1] + up + 1, dp[i - 1][2] + down + 1));
		dp[i][1] = min(dp[i - 1][2] + down, dp[i - 1][0] + 1);
		dp[i][2] = min(dp[i - 1][1] + up, dp[i - 1][0] + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		int answer = INF;
		memset(dp, 0, sizeof(dp));

		cin >> N >> W;
		
		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= N; ++j)
				cin >> enemy[i][j];
			
		int up = enemy[0][1];
		int down = enemy[1][1];

		dp[1][0] = (enemy[0][1] + enemy[1][1] <= W) ? 1 : 2;
		dp[1][1] = dp[1][2] = 1;
		process();
		answer = min(answer, dp[N][0]);

		if (enemy[0][1] + enemy[0][N] <= W) {
			dp[1][0] = 2;
			dp[1][1] = dp[1][2] = 1;
			enemy[0][1] = INF;
			process();
			answer = min(answer, dp[N][1]);
			enemy[0][1] = up;
		}

		if (enemy[1][1] + enemy[1][N] <= W) {
			dp[1][0] = 2;
			dp[1][1] = dp[1][2] = 1;
			enemy[1][1] = INF;
			process();
			answer = min(answer, dp[N][2]);
			enemy[1][1] = down;
		}

		if ((enemy[0][1] + enemy[0][N] <= W) && (enemy[1][1] + enemy[1][N] <= W)) {
			dp[1][0] = 2;
			dp[1][1] = dp[1][2] = 1;
			enemy[0][1] = enemy[1][1] = INF;
			process();
			answer = min(answer, dp[N - 1][0]);
			enemy[0][1] = up;
			enemy[1][1] = down;
		}

		if (N == 1) answer = (enemy[0][1] + enemy[1][1] <= W) ? 1 : 2;

		cout << answer << '\n';
	}

	return 0;
}
