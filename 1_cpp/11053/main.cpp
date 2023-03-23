// 백준 11053: 가장 긴 증가하는 부분 수열(실버 II), https://www.acmicpc.net/problem/11053
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int numbers[MAX], dp[MAX];
int N, answer = 0;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &numbers[i]);

	for (int i = 0; i < N; ++i) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; --j)
			if (numbers[i] > numbers[j])
				dp[i] = max(dp[i], dp[j] + 1);
		answer = max(answer, dp[i]);
	}

	printf("%d\n", answer);

	return 0;
}