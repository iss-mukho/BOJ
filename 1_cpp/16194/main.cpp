// 백준 16194: 카드 구매하기 2(실버 I), https://www.acmicpc.net/problem/16194
#include <iostream>
using namespace std;
const int MAX = 1001;

int N;
int P[MAX], dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> P[i];

	for (int i = 1; i <= N; ++i) {
		dp[i] = P[i];
		for (int j = 1; j <= i; ++j)
			dp[i] = min(dp[i], dp[i-j] + dp[j]);
	}

	cout << dp[N] << '\n';

	return 0;
}
