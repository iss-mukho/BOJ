// 백준 12852, 1로 만들기 2(실버 I), https://www.acmicpc.net/problem/12852
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int X, dp[MAX + 1];

void calc() {
	for (int i = 2; i <= X; ++i) {
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2]);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3]);
		dp[i] = min(dp[i], dp[i - 1]) + 1;
	}
}
int main() {
	scanf("%d", &X);

	for (int i = 1; i <= X; ++i)
		dp[i] = i;
	calc();

	printf("%d\n", dp[X] - 1);
	while (X) {
		printf("%d ", X);

		if (dp[X] == dp[X - 1] + 1) --X;
		else if (X % 2 == 0 && dp[X] == dp[X / 2] + 1) X /= 2;
		else if (X % 3 == 0 && dp[X] == dp[X / 3] + 1) X /= 3;
	}
	printf("\n");

	return 0;
}