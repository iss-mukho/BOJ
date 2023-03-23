#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX = 100;
ll dp[MAX + 1];
int T, N;

ll calc(int n) {
	if (n <= 3) return dp[n];

	if (!dp[n])
		dp[n] = calc(n - 3) + calc(n - 2);
	return dp[n];
}

int main() {
	scanf("%d", &T);
	dp[1] = 1, dp[2] = 1, dp[3] = 1;

	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", calc(N));
	}

	return 0;
}