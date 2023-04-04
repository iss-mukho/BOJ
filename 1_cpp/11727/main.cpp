// 백준 11727: 2xn 타일링 2(실버 3), https://www.acmicpc.net/problem/11727
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 1001;
int dp[MAX];

int main() {
	int n;
	scanf("%d", &n);
	dp[1] = 1, dp[2] = 3;
	for (int i = 3; i <= n; ++i)
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	printf("%d\n", dp[n]);
}
